#include "mongoose.h"
#include "cameractl.h"
#include <unistd.h>

#pragma cle def GREEN_NOSHARE  {"level":"green"}

#pragma cle def ORANGE_NOSHARE {"level":"orange"}

#pragma cle def GREEN_SHARE {"level": "green", \
  "cdf": [ \
    {"remotelevel": "orange", "direction": "egress", "guarddirective": {"operation": "allow"}} \
  ]}

#pragma cle def ORANGE_SHARE {"level": "orange", \
  "cdf": [ \
    {"remotelevel": "green", "direction": "egress", "guarddirective": {"operation": "allow"}} \
  ]}

#pragma cle def XDLINKAGE_RUN_VIDEOPROC {"level":"orange", \
  "cdf": [\
    {"remotelevel":"green", "direction": "ingress", "guarddirective": {"operation": "allow"}, \
     "argtaints": [], \
     "codtaints": ["ORANGE_NOSHARE", "ORANGE_SHARE"], \
     "rettaints": ["TAG_RESPONSE_RUN_VIDEOPROC"], \
     "idempotent": true, \
     "num_tries": 1, \
     "timeout": 1000}, \
    {"remotelevel":"orange", "direction": "ingress", "guarddirective": {"operation": "allow"}, \
     "argtaints": [], \
     "codtaints": ["ORANGE_NOSHARE", "ORANGE_SHARE"], \
     "rettaints": ["TAG_RESPONSE_RUN_VIDEOPROC"]} \
  ]}

// timeout out to be <40ms for 25fps but MB roundtrip latency are higher than 100ms
#pragma cle def XDLINKAGE_GET_FRAME {"level":"orange", \
  "cdf": [\
    {"remotelevel":"green", "direction": "ingress", "guarddirective": {"operation": "allow"}, \
     "argtaints": [["TAG_REQUEST_GET_FRAME", "TAG_RESPONSE_GET_FRAME"]], \
     "codtaints": ["ORANGE_NOSHARE", "ORANGE_SHARE"], \
     "rettaints": ["TAG_RESPONSE_GET_FRAME"], \
     "idempotent": true, \
     "num_tries": 1, \
     "timeout": 150}, \
    {"remotelevel":"orange", "direction": "ingress", "guarddirective": {"operation": "allow"}, \
     "argtaints": [["TAG_REQUEST_GET_FRAME", "TAG_RESPONSE_GET_FRAME"]], \
     "codtaints": ["ORANGE_NOSHARE", "ORANGE_SHARE"], \
     "rettaints": ["TAG_RESPONSE_GET_FRAME"]} \
  ]}

// timeout out to be <40ms for 25fps but MB roundtrip latency are higher than 100ms
#pragma cle def XDLINKAGE_GET_METADATA {"level":"orange", \
  "cdf": [\
    {"remotelevel":"green", "direction": "ingress", "guarddirective": {"operation": "allow"}, \
     "argtaints": [["TAG_REQUEST_GET_METADATA","TAG_RESPONSE_GET_METADATA"], ["TAG_REQUEST_GET_METADATA","TAG_RESPONSE_GET_METADATA"], ["TAG_REQUEST_GET_METADATA","TAG_RESPONSE_GET_METADATA"], ["TAG_REQUEST_GET_METADATA","TAG_RESPONSE_GET_METADATA"]], \
     "codtaints": ["ORANGE_NOSHARE", "ORANGE_SHARE"], \
     "rettaints": ["TAG_RESPONSE_GET_METADATA"], \
     "idempotent": true, \
     "num_tries": 1, \
     "timeout": 150}, \
    {"remotelevel":"orange", "direction": "ingress", "guarddirective": {"operation": "allow"}, \
     "argtaints": [["TAG_REQUEST_GET_METADATA","TAG_RESPONSE_GET_METADATA"], ["TAG_REQUEST_GET_METADATA","TAG_RESPONSE_GET_METADATA"], ["TAG_REQUEST_GET_METADATA","TAG_RESPONSE_GET_METADATA"], ["TAG_REQUEST_GET_METADATA","TAG_RESPONSE_GET_METADATA"]], \
     "codtaints": ["ORANGE_NOSHARE", "ORANGE_SHARE"], \
     "rettaints": ["TAG_RESPONSE_GET_METADATA"]} \
  ]}

// ideally this should be same as what the fps requires, but send_camcmd may take longer to work; until app is modified, we use this 1000ms timeout value
#pragma cle def XDLINKAGE_SEND_CAMCMD {"level":"orange", \
  "cdf": [\
    {"remotelevel":"green", "direction": "ingress", "guarddirective": {"operation": "allow"}, \
     "argtaints": [["TAG_REQUEST_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD"]], \
     "codtaints": ["ORANGE_NOSHARE", "ORANGE_SHARE"], \
     "rettaints": ["TAG_RESPONSE_SEND_CAMCMD"], \
     "idempotent": true, \
     "num_tries": 1, \
     "timeout": 1000}, \
    {"remotelevel":"orange", "direction": "ingress", "guarddirective": {"operation": "allow"}, \
     "argtaints": [["TAG_REQUEST_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD"]], \
     "codtaints": ["ORANGE_NOSHARE", "ORANGE_SHARE"], \
     "rettaints": ["TAG_RESPONSE_SEND_CAMCMD"]} \
  ]}

#pragma cle def FUN_HANDLE_CAMERA_COMMAND {"level":"green", \
  "cdf": [\
    {"remotelevel":"green", "direction": "ingress", "guarddirective": {"operation": "allow"}, \
     "argtaints": [["GREEN_NOSHARE"], ["GREEN_NOSHARE"]], \
     "codtaints": ["GREEN_SHARE", "TAG_REQUEST_SEND_CAMCMD", "TAG_RESPONSE_SEND_CAMCMD"], \
     "rettaints": ["GREEN_NOSHARE", "GREEN_SHARE"]} \
  ]}

#pragma cle def FUN_HANDLE_GET_METADATA {"level":"green", \
  "cdf": [\
    {"remotelevel":"green", "direction": "ingress", "guarddirective": {"operation": "allow"}, \
     "argtaints": [["GREEN_NOSHARE"], ["GREEN_NOSHARE"]], \
     "codtaints": ["GREEN_SHARE", "TAG_REQUEST_GET_METADATA", "TAG_RESPONSE_GET_METADATA"], \
     "rettaints": ["GREEN_NOSHARE", "GREEN_SHARE"]} \
  ]}
/* the rettaints below may be a problem, wsend_video was changed back to
   a void function, does it have a rettaint? this is problem, changing fn back
   to int/return 0 */
#pragma cle def FUN_WSEND_VIDEO {"level":"green", \
  "cdf": [\
    {"remotelevel":"green", "direction": "ingress", "guarddirective": {"operation": "allow"}, \
     "argtaints": [["GREEN_NOSHARE"]], \
     "codtaints": ["GREEN_SHARE", "TAG_REQUEST_GET_FRAME", "TAG_RESPONSE_GET_FRAME"], \
     "rettaints": ["GREEN_NOSHARE", "GREEN_SHARE"]} \
  ]}

#pragma cle def FUN_WEBSRV_MAIN {"level":"green", \
  "cdf": [\
    {"remotelevel":"green", "direction": "ingress", "guarddirective": {"operation": "allow"}, \
     "argtaints": [], \
     "codtaints": ["GREEN_SHARE","TAG_REQUEST_RUN_VIDEOPROC", "TAG_RESPONSE_RUN_VIDEOPROC"], \
     "rettaints": ["GREEN_NOSHARE", "GREEN_SHARE"]} \
  ]}

#define FRAME_INTERVAL  40
#define POLL_INTERVAL   5
//XXX: mbedtls on MB not working as expected
// #define WSS_URL         "wss://0.0.0.0:8443"   
// #define HTTPS_URL       "https://0.0.0.0:8443"
#define WSS_URL         "ws://0.0.0.0:8443"   
#define HTTPS_URL       "http://0.0.0.0:8443"
#define WWW_ROOT        "./www"

#pragma cle begin FUN_HANDLE_CAMERA_COMMAND 
int handle_camera_command(struct mg_connection *c, struct mg_http_message *hm) {
#pragma cle end FUN_HANDLE_CAMERA_COMMAND 
#pragma cle begin GREEN_SHARE
  double pan, tilt, imptime;
  char   mode, stab;
#pragma cle end GREEN_SHARE
  double pan_copy, tilt_copy, imptime_copy;
  char   mode_copy, stab_copy;
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
    
    memcpy(&pan_copy, &pan, sizeof(double));
    memcpy(&tilt_copy, &tilt, sizeof(double));
    memcpy(&imptime_copy, &imptime, sizeof(double));
    memcpy(&mode_copy, &mode, sizeof(char));
    memcpy(&stab_copy, &stab, sizeof(char));
    if (send_camcmd(pan_copy, tilt_copy, imptime_copy, mode_copy, stab_copy) == 1) {
      mg_http_reply(c, 200, "Content-Type: application/json\r\n", "{\"result\": \"%s\"}\n", "OKAY");
      return 1;
    }
  }
  mg_http_reply(c, 200, "Content-Type: application/json\r\n", "{\"result\": \"%s\"}\n", "FAIL");
  return 0;
}

#pragma cle begin FUN_HANDLE_GET_METADATA
int handle_get_metadata(struct mg_connection *c, struct mg_http_message *hm) {
#pragma cle end FUN_HANDLE_GET_METADATA
#pragma cle begin GREEN_SHARE
  double lat, lon, alt, ts;
#pragma cle end GREEN_SHARE

  double lat_copy, lon_copy, alt_copy, ts_copy;
  memcpy (&lat_copy, &lat, sizeof(double));
  memcpy (&lon_copy, &lon, sizeof(double));
  memcpy (&alt_copy, &alt, sizeof(double));
  memcpy (&ts_copy, &ts, sizeof(double));
  if (get_metadata(&lat_copy, &lon_copy, &alt_copy, &ts_copy) != 1) {
    lat_copy = 0.0; lon_copy = 0.0; alt_copy = 0.0; ts_copy = 0.0;
  }
  memcpy (&lat, &lat_copy, sizeof(double));
  memcpy (&lon, &lon_copy, sizeof(double));
  memcpy (&alt, &alt_copy, sizeof(double));
  memcpy (&ts, &ts_copy, sizeof(double));
  char *json = mg_mprintf("{%Q:%g,%Q:%g,%Q:%g,%Q:%g}", "Lat", lat, "Lon", lon, "Alt", alt, "Tim", ts);
  mg_http_reply(c, 200, "Content-Type: application/json\r\n", "%s\n", json);
  free(json);
  return 0;
}



#pragma cle begin FUN_WSEND_VIDEO
int wsend_video(void *arg) {
#pragma cle end FUN_WSEND_VIDEO
  struct mg_mgr *mgr = (struct mg_mgr *) arg;
#pragma cle begin GREEN_SHARE
  static char buf[MAX_FRAME_BUF];
#pragma cle end GREEN_SHARE
  int sz;
  char buf_copy[MAX_FRAME_BUF];
  char buf_noshare[MAX_FRAME_BUF];
  memset(buf_copy, 0, MAX_FRAME_BUF);
  memcpy(buf_copy, buf, MAX_FRAME_BUF);
  sz = get_frame(buf_copy);
  if (sz > 0) {
    for (struct mg_connection *c = mgr->conns; c != NULL; c = c->next) { // send next frame to each live stream
      if (c->label[0] == 'S') {
          memset(buf_noshare, 0, MAX_FRAME_BUF);
          memcpy(buf_noshare, buf_copy, MAX_FRAME_BUF);
          mg_ws_send(c, buf_noshare, sz, WEBSOCKET_OP_BINARY);
          // fprintf(stderr, "Sent frame to websock: %d\n", sz);
      }
    }
  }
  return 0;
}

int wsend_video_wrapper(void *arg) {
  wsend_video(arg);
  return 0;
}

void webfn(struct mg_connection *c, int ev, void *ev_data, void *fn_data) {
  static const char *s_web_root = WWW_ROOT;
  if (ev == MG_EV_ACCEPT && fn_data != NULL) {
    struct mg_tls_opts opts = {
      .cert = "./creds/server.cert",
      .certkey = "./creds/server.key",
    };
    /* mg_tls_init(c, &opts); */
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
  mg_timer_add(&mgr, FRAME_INTERVAL, MG_TIMER_REPEAT, wsend_video_wrapper, &mgr);
  for (;;) mg_mgr_poll(&mgr, POLL_INTERVAL);
  mg_mgr_free(&mgr);
}

#pragma cle begin FUN_WEBSRV_MAIN 
int websrv_main(void) {
#pragma cle end FUN_WEBSRV_MAIN 
  while (run_videoproc() != 0) {
    fprintf(stderr, "Failed to run video processing\n");
  }
  run_webserver();
  return 0;
}

int main(int argc, char**argv) {
  return websrv_main();
}
