#include "orange_rpc.h"
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
     "rettaints": ["TAG_RESPONSE_RUN_VIDEOPROC"]}, \
    {"remotelevel":"orange", "direction": "ingress", "guarddirective": {"operation": "allow"}, \
     "argtaints": [], \
     "codtaints": ["ORANGE_NOSHARE", "ORANGE_SHARE"], \
     "rettaints": ["TAG_RESPONSE_RUN_VIDEOPROC"]} \
  ]}

#pragma cle def XDLINKAGE_GET_FRAME {"level":"orange", \
  "cdf": [\
    {"remotelevel":"green", "direction": "ingress", "guarddirective": {"operation": "allow"}, \
     "argtaints": [["TAG_REQUEST_GET_FRAME"]], \
     "codtaints": ["ORANGE_NOSHARE", "ORANGE_SHARE"], \
     "rettaints": ["TAG_RESPONSE_GET_FRAME"]}, \
    {"remotelevel":"orange", "direction": "ingress", "guarddirective": {"operation": "allow"}, \
     "argtaints": [["TAG_REQUEST_GET_FRAME"]], \
     "codtaints": ["ORANGE_NOSHARE", "ORANGE_SHARE"], \
     "rettaints": ["TAG_RESPONSE_GET_FRAME"]} \
  ]}

#pragma cle def XDLINKAGE_GET_METADATA {"level":"orange", \
  "cdf": [\
    {"remotelevel":"green", "direction": "ingress", "guarddirective": {"operation": "allow"}, \
     "argtaints": [["TAG_REQUEST_GET_METADATA"], ["TAG_REQUEST_GET_METADATA"], ["TAG_REQUEST_GET_METADATA"], ["TAG_REQUEST_GET_METADATA"]], \
     "codtaints": ["ORANGE_NOSHARE", "ORANGE_SHARE"], \
     "rettaints": ["TAG_RESPONSE_GET_METADATA"]}, \
    {"remotelevel":"orange", "direction": "ingress", "guarddirective": {"operation": "allow"}, \
     "argtaints": [["TAG_REQUEST_GET_METADATA"], ["TAG_REQUEST_GET_METADATA"], ["TAG_REQUEST_GET_METADATA"], ["TAG_REQUEST_GET_METADATA"]], \
     "codtaints": ["ORANGE_NOSHARE", "ORANGE_SHARE"], \
     "rettaints": ["TAG_RESPONSE_GET_METADATA"]} \
  ]}

#pragma cle def XDLINKAGE_SEND_CAMCMD {"level":"orange", \
  "cdf": [\
    {"remotelevel":"green", "direction": "ingress", "guarddirective": {"operation": "allow"}, \
     "argtaints": [["TAG_REQUEST_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD"]], \
     "codtaints": ["ORANGE_NOSHARE", "ORANGE_SHARE"], \
     "rettaints": ["TAG_RESPONSE_SEND_CAMCMD"]}, \
    {"remotelevel":"orange", "direction": "ingress", "guarddirective": {"operation": "allow"}, \
     "argtaints": [["TAG_REQUEST_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD"]], \
     "codtaints": ["ORANGE_NOSHARE", "ORANGE_SHARE"], \
     "rettaints": ["TAG_RESPONSE_SEND_CAMCMD"]} \
  ]}

#pragma cle def FUN_HANDLE_CAMERA_COMMAND {"level":"green", \
  "cdf": [\
    {"remotelevel":"green", "direction": "ingress", "guarddirective": {"operation": "allow"}, \
     "argtaints": [["GREEN"], ["GREEN"]], \
     "codtaints": ["GREEN_SHARE"], \
     "rettaints": ["GREEN"]} \
  ]}

#pragma cle def FUN_HANDLE_GET_METADATA {"level":"green", \
  "cdf": [\
    {"remotelevel":"green", "direction": "ingress", "guarddirective": {"operation": "allow"}, \
     "argtaints": [["GREEN"], ["GREEN"]], \
     "codtaints": ["GREEN_SHARE"], \
     "rettaints": ["GREEN"]} \
  ]}

#pragma cle def FUN_WSEND_VIDEO {"level":"green", \
  "cdf": [\
    {"remotelevel":"green", "direction": "ingress", "guarddirective": {"operation": "allow"}, \
     "argtaints": [["GREEN"]], \
     "codtaints": ["GREEN_SHARE"], \
     "rettaints": ["GREEN"]} \
  ]}

#pragma cle def FUN_WEBSRV_MAIN {"level":"green", \
  "cdf": [\
    {"remotelevel":"green", "direction": "ingress", "guarddirective": {"operation": "allow"}, \
     "argtaints": [], \
     "codtaints": ["GREEN_SHARE"], \
     "rettaints": ["GREEN"]} \
  ]}

#define FRAME_INTERVAL  20
#define POLL_INTERVAL   5
//XXX: mbedtls on MB not working as expected
// #define WSS_URL         "wss://0.0.0.0:8443"   
// #define HTTPS_URL       "https://0.0.0.0:8443"
#define WSS_URL         "ws://0.0.0.0:8443"   
#define HTTPS_URL       "http://0.0.0.0:8443"
#define WWW_ROOT        "./www"







int main(int argc, char *argv[]) {
  return _slave_rpc_loop();
}