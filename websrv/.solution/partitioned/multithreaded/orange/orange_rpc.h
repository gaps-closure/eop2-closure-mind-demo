#ifndef _ORANGE_RPC_
#define _ORANGE_RPC_

#include "codec.h"
#include <limits.h>
#include <pthread.h>
#include "xdcomms.h"
#define INURI "ipc:///tmp/websrvsuborange"
#define OUTURI "ipc:///tmp/websrvpuborange"

#define MUX_BASE 0
#define SEC_BASE 0
#define TYP_BASE 0

extern int _slave_rpc_loop();

#pragma cle def HANDLE_REQUEST_GET_FRAME {"level": "orange", \
    "cdf": [{"remotelevel":"orange", "direction": "bidirectional", \
            "guarddirective": {"operation": "allow"}, \
            "argtaints": [],\
            "codtaints": ["TAG_REQUEST_GET_FRAME", "TAG_RESPONSE_GET_FRAME"],\
            "rettaints": []\
            }]}
#pragma cle def HANDLE_REQUEST_GET_METADATA {"level": "orange", \
    "cdf": [{"remotelevel":"orange", "direction": "bidirectional", \
            "guarddirective": {"operation": "allow"}, \
            "argtaints": [],\
            "codtaints": ["TAG_REQUEST_GET_METADATA", "TAG_RESPONSE_GET_METADATA"],\
            "rettaints": []\
            }]}
#pragma cle def HANDLE_REQUEST_RUN_VIDEOPROC {"level": "orange", \
    "cdf": [{"remotelevel":"orange", "direction": "bidirectional", \
            "guarddirective": {"operation": "allow"}, \
            "argtaints": [],\
            "codtaints": ["TAG_REQUEST_RUN_VIDEOPROC", "TAG_RESPONSE_RUN_VIDEOPROC"],\
            "rettaints": []\
            }]}
#pragma cle def HANDLE_REQUEST_SEND_CAMCMD {"level": "orange", \
    "cdf": [{"remotelevel":"orange", "direction": "bidirectional", \
            "guarddirective": {"operation": "allow"}, \
            "argtaints": [],\
            "codtaints": ["TAG_REQUEST_SEND_CAMCMD", "TAG_RESPONSE_SEND_CAMCMD"],\
            "rettaints": []\
            }]}
#pragma cle def TAG_NEXTRPC {"level": "orange", \
    "cdf": [{"remotelevel": "orange", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [1,1,1]}}]}

#pragma cle def TAG_OKAY {"level": "orange", \
    "cdf": [{"remotelevel": "green", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [2,2,2]}}]}

#pragma cle def TAG_REQUEST_GET_FRAME {"level": "orange", \
    "cdf": [{"remotelevel": "orange", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [1,1,3]}}]}

#pragma cle def TAG_RESPONSE_GET_FRAME {"level": "orange", \
    "cdf": [{"remotelevel": "green", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [2,2,4]}}]}

#pragma cle def TAG_REQUEST_GET_METADATA {"level": "orange", \
    "cdf": [{"remotelevel": "orange", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [1,1,5]}}]}

#pragma cle def TAG_RESPONSE_GET_METADATA {"level": "orange", \
    "cdf": [{"remotelevel": "green", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [2,2,6]}}]}

#pragma cle def TAG_REQUEST_RUN_VIDEOPROC {"level": "orange", \
    "cdf": [{"remotelevel": "orange", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [1,1,7]}}]}

#pragma cle def TAG_RESPONSE_RUN_VIDEOPROC {"level": "orange", \
    "cdf": [{"remotelevel": "green", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [2,2,8]}}]}

#pragma cle def TAG_REQUEST_SEND_CAMCMD {"level": "orange", \
    "cdf": [{"remotelevel": "orange", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [1,1,9]}}]}

#pragma cle def TAG_RESPONSE_SEND_CAMCMD {"level": "orange", \
    "cdf": [{"remotelevel": "green", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [2,2,10]}}]}

#define MUX_NEXTRPC MUX_BASE + 1
#define SEC_NEXTRPC SEC_BASE + 1
#define MUX_OKAY MUX_BASE + 2
#define SEC_OKAY SEC_BASE + 2
#define MUX_REQUEST_GET_FRAME MUX_BASE + 1
#define SEC_REQUEST_GET_FRAME SEC_BASE + 1
#define MUX_RESPONSE_GET_FRAME MUX_BASE + 2
#define SEC_RESPONSE_GET_FRAME SEC_BASE + 2
#define MUX_REQUEST_GET_METADATA MUX_BASE + 1
#define SEC_REQUEST_GET_METADATA SEC_BASE + 1
#define MUX_RESPONSE_GET_METADATA MUX_BASE + 2
#define SEC_RESPONSE_GET_METADATA SEC_BASE + 2
#define MUX_REQUEST_RUN_VIDEOPROC MUX_BASE + 1
#define SEC_REQUEST_RUN_VIDEOPROC SEC_BASE + 1
#define MUX_RESPONSE_RUN_VIDEOPROC MUX_BASE + 2
#define SEC_RESPONSE_RUN_VIDEOPROC SEC_BASE + 2
#define MUX_REQUEST_SEND_CAMCMD MUX_BASE + 1
#define SEC_REQUEST_SEND_CAMCMD SEC_BASE + 1
#define MUX_RESPONSE_SEND_CAMCMD MUX_BASE + 2
#define SEC_RESPONSE_SEND_CAMCMD SEC_BASE + 2

extern int get_frame(char buf[]);
extern int get_metadata(double lat[],double lon[],double alt[],double ts[]);
extern int run_videoproc(void);
extern int send_camcmd(double pan,double tilt,double imptime,char mode,char stab);

#endif /* _ORANGE_RPC_ */
