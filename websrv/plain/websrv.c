#include "mongoose.h"
#include "cameractl.h"
#include <unistd.h>

#define FRAME_INTERVAL  20
#define POLL_INTERVAL   5
#define WSS_URL         "wss://0.0.0.0:8443"   
#define HTTPS_URL       "https://0.0.0.0:8443"
#define WWW_ROOT        "./www"

int handle_camera_command(struct mg_connection *c, struct mg_http_message *hm) {
  double pan, tilt, imptime;
  char   mode, stab;
  if (hm != NULL) {
    struct mg_str json = mg_str("");
    json = mg_str_n(hm->body.ptr, hm->body.len);
    char *pstr = mg_json_get_str(json, "$.pan");
    char *tstr = mg_json_get_str(json, "$.tilt");
    char *istr = mg_json_get_str(json, "$.imptime");
    char *mstr = mg_json_get_str(json, "$.mode");
    char *sstr = mg_json_get_str(json, "$.stab");
    pan     = atof(pstr);
    tilt    = atof(tstr);
    imptime = atof(istr);
    mode    = strlen(mstr) >= 1 ? mstr[0] : '_';
    stab    = (char) atoi(sstr);
    // fprintf(stderr, "got params %lf %lf %lf %c %d \n", pan, tilt, imptime, mode, stab);
    free(pstr);
    free(tstr);
    free(istr);
    free(mstr);
    free(sstr);
    if (send_camcmd(pan, tilt, imptime, mode, stab) == 1) {
      mg_http_reply(c, 200, "Content-Type: application/json\r\n", "{\"result\": \"%s\"}\n", "OKAY");
      return 1;
    }
  }
  mg_http_reply(c, 200, "Content-Type: application/json\r\n", "{\"result\": \"%s\"}\n", "FAIL");
  return 0;
}

int handle_get_metadata(struct mg_connection *c, struct mg_http_message *hm) {
  double lat, lon, alt, ts;
  if (get_metadata(&lat, &lon, &alt, &ts) != 1) {
    lat = 0.0; lon = 0.0; alt = 0.0; ts = 0.0;
  }
  char *json = mg_mprintf("{%Q:%g,%Q:%g,%Q:%g,%Q:%g}", "Lat", lat, "Lon", lon, "Alt", alt, "Tim", ts);
  mg_http_reply(c, 200, "Content-Type: application/json\r\n", "%s\n", json);
  free(json);
  return 0;
}

void wsend_video(void *arg) {
  struct mg_mgr *mgr = (struct mg_mgr *) arg;
  static char buf[MAX_FRAME_BUF];
  int sz;
  sz = get_frame(buf);
  if (sz > 0) {
    for (struct mg_connection *c = mgr->conns; c != NULL; c = c->next) { // send next frame to each live stream
      if (c->label[0] == 'S') {
          mg_ws_send(c, buf, sz, WEBSOCKET_OP_BINARY);
          // fprintf(stderr, "Sent frame to websock: %d\n", sz);
      }
    }
  }
  return;
}

void webfn(struct mg_connection *c, int ev, void *ev_data, void *fn_data) {
  static const char *s_web_root = WWW_ROOT;
  if (ev == MG_EV_ACCEPT && fn_data != NULL) {
    struct mg_tls_opts opts = {
      .cert = "./creds/server.pem",
      .certkey = "./creds/server.pem",
    };
    mg_tls_init(c, &opts);
  } else if (ev == MG_EV_HTTP_MSG) {
    struct mg_http_message *hm = (struct mg_http_message *) ev_data;
    if (mg_http_match_uri(hm, "/ws/video"))   { // Upgrade to websocket, mark connection as livestreamr
      fprintf(stderr, "Stream request received, upgrading to websocket\n");
      mg_ws_upgrade(c, hm, NULL);
      c->label[0] = 'S';  
    } else if (mg_http_match_uri(hm, "/api/camcmd")) { // Handle camera API commands
      handle_camera_command(c, hm);
    } else if (mg_http_match_uri(hm, "/api/getllat")) { // Latest metadata
      handle_get_metadata(c, hm);
    } else {                                    // Serve files for webpages
      struct mg_http_serve_opts opts = {.root_dir = s_web_root};
      mg_http_serve_dir(c, ev_data, &opts);
    }
  } 
}

void run_webserver() {
  struct mg_mgr mgr;
  const char *s_listen_on  = WSS_URL;
  const char *s_https_addr = HTTPS_URL;
  mg_mgr_init(&mgr);
  fprintf(stderr, "Starting HTTPS camera API endpoint on %s/api\n", s_https_addr);
  fprintf(stderr, "Starting WSS video endpoint on %s/ws/video\n", s_listen_on);
  mg_http_listen(&mgr, s_https_addr, webfn, (void *) 1);
  mg_timer_add(&mgr, FRAME_INTERVAL, MG_TIMER_REPEAT, wsend_video, &mgr);
  for (;;) mg_mgr_poll(&mgr, POLL_INTERVAL);
  mg_mgr_free(&mgr);
}

int websrv_main(void) {
  if (run_videoproc() != 0) {
    fprintf(stderr, "Failed to run video processing\n");
  }
  run_webserver();
  return 0;
}

int main(int argc, char**argv) {
  return websrv_main();
}
