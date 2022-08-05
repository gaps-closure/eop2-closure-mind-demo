#ifndef _GREEN_RPC_
#define _GREEN_RPC_

#include "codec.h"
#include <limits.h>

#include "xdcomms.h"
#define INURI "ipc:///tmp/websrvsubgreen"
#define OUTURI "ipc:///tmp/websrvpubgreen"

#define MUX_BASE 0
#define SEC_BASE 0
#define TYP_BASE 0

extern void _master_rpc_init();

#pragma cle def RPC_GET_FRAME {"level": "green", \
    "cdf": [{"remotelevel":"green", "direction": "bidirectional", \
            "guarddirective": {"operation": "allow"}, \
            "argtaints": [["TAG_REQUEST_GET_FRAME", "TAG_RESPONSE_GET_FRAME"], ["TAG_REQUEST_GET_FRAME", "TAG_RESPONSE_GET_FRAME"]],\
            "codtaints": ["TAG_REQUEST_GET_FRAME", "TAG_RESPONSE_GET_FRAME"],\
            "rettaints": ["TAG_RESPONSE_GET_FRAME"]\
            }]}
#pragma cle def ERR_HANDLE_RPC_GET_FRAME {"level": "green", \
    "cdf": [{"remotelevel":"green", "direction": "bidirectional", \
            "guarddirective": {"operation": "allow"}, \
            "argtaints": [["TAG_REQUEST_GET_FRAME", "TAG_RESPONSE_GET_FRAME"]],\
            "codtaints": ["TAG_REQUEST_GET_FRAME", "TAG_RESPONSE_GET_FRAME"],\
            "rettaints": ["TAG_RESPONSE_GET_FRAME"]\
            }]}
#pragma cle def RPC_GET_METADATA {"level": "green", \
    "cdf": [{"remotelevel":"green", "direction": "bidirectional", \
            "guarddirective": {"operation": "allow"}, \
            "argtaints": [["TAG_REQUEST_GET_METADATA", "TAG_RESPONSE_GET_METADATA"], ["TAG_REQUEST_GET_METADATA", "TAG_RESPONSE_GET_METADATA"], ["TAG_REQUEST_GET_METADATA", "TAG_RESPONSE_GET_METADATA"], ["TAG_REQUEST_GET_METADATA", "TAG_RESPONSE_GET_METADATA"], ["TAG_REQUEST_GET_METADATA", "TAG_RESPONSE_GET_METADATA"]],\
            "codtaints": ["TAG_REQUEST_GET_METADATA", "TAG_RESPONSE_GET_METADATA"],\
            "rettaints": ["TAG_RESPONSE_GET_METADATA"]\
            }]}
#pragma cle def ERR_HANDLE_RPC_GET_METADATA {"level": "green", \
    "cdf": [{"remotelevel":"green", "direction": "bidirectional", \
            "guarddirective": {"operation": "allow"}, \
            "argtaints": [["TAG_REQUEST_GET_METADATA", "TAG_RESPONSE_GET_METADATA"], ["TAG_REQUEST_GET_METADATA", "TAG_RESPONSE_GET_METADATA"], ["TAG_REQUEST_GET_METADATA", "TAG_RESPONSE_GET_METADATA"], ["TAG_REQUEST_GET_METADATA", "TAG_RESPONSE_GET_METADATA"]],\
            "codtaints": ["TAG_REQUEST_GET_METADATA", "TAG_RESPONSE_GET_METADATA"],\
            "rettaints": ["TAG_RESPONSE_GET_METADATA"]\
            }]}
#pragma cle def RPC_RUN_VIDEOPROC {"level": "green", \
    "cdf": [{"remotelevel":"green", "direction": "bidirectional", \
            "guarddirective": {"operation": "allow"}, \
            "argtaints": [["TAG_REQUEST_RUN_VIDEOPROC", "TAG_RESPONSE_RUN_VIDEOPROC"]],\
            "codtaints": ["TAG_REQUEST_RUN_VIDEOPROC", "TAG_RESPONSE_RUN_VIDEOPROC"],\
            "rettaints": ["TAG_RESPONSE_RUN_VIDEOPROC"]\
            }]}
#pragma cle def ERR_HANDLE_RPC_RUN_VIDEOPROC {"level": "green", \
    "cdf": [{"remotelevel":"green", "direction": "bidirectional", \
            "guarddirective": {"operation": "allow"}, \
            "argtaints": [],\
            "codtaints": ["TAG_REQUEST_RUN_VIDEOPROC", "TAG_RESPONSE_RUN_VIDEOPROC"],\
            "rettaints": ["TAG_RESPONSE_RUN_VIDEOPROC"]\
            }]}
#pragma cle def RPC_SEND_CAMCMD {"level": "green", \
    "cdf": [{"remotelevel":"green", "direction": "bidirectional", \
            "guarddirective": {"operation": "allow"}, \
            "argtaints": [["TAG_REQUEST_SEND_CAMCMD", "TAG_RESPONSE_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD", "TAG_RESPONSE_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD", "TAG_RESPONSE_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD", "TAG_RESPONSE_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD", "TAG_RESPONSE_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD", "TAG_RESPONSE_SEND_CAMCMD"]],\
            "codtaints": ["TAG_REQUEST_SEND_CAMCMD", "TAG_RESPONSE_SEND_CAMCMD"],\
            "rettaints": ["TAG_RESPONSE_SEND_CAMCMD"]\
            }]}
#pragma cle def ERR_HANDLE_RPC_SEND_CAMCMD {"level": "green", \
    "cdf": [{"remotelevel":"green", "direction": "bidirectional", \
            "guarddirective": {"operation": "allow"}, \
            "argtaints": [["TAG_REQUEST_SEND_CAMCMD", "TAG_RESPONSE_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD", "TAG_RESPONSE_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD", "TAG_RESPONSE_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD", "TAG_RESPONSE_SEND_CAMCMD"], ["TAG_REQUEST_SEND_CAMCMD", "TAG_RESPONSE_SEND_CAMCMD"]],\
            "codtaints": ["TAG_REQUEST_SEND_CAMCMD", "TAG_RESPONSE_SEND_CAMCMD"],\
            "rettaints": ["TAG_RESPONSE_SEND_CAMCMD"]\
            }]}
#pragma cle def TAG_NEXTRPC {"level": "green", \
    "cdf": [{"remotelevel": "orange", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [1,1,1]}}]}

#pragma cle def TAG_OKAY {"level": "green", \
    "cdf": [{"remotelevel": "green", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [2,2,2]}}]}

#pragma cle def TAG_REQUEST_GET_FRAME {"level": "green", \
    "cdf": [{"remotelevel": "orange", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [1,1,3]}}]}

#pragma cle def TAG_RESPONSE_GET_FRAME {"level": "green", \
    "cdf": [{"remotelevel": "green", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [2,2,4]}}]}

#pragma cle def TAG_REQUEST_GET_METADATA {"level": "green", \
    "cdf": [{"remotelevel": "orange", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [1,1,5]}}]}

#pragma cle def TAG_RESPONSE_GET_METADATA {"level": "green", \
    "cdf": [{"remotelevel": "green", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [2,2,6]}}]}

#pragma cle def TAG_REQUEST_RUN_VIDEOPROC {"level": "green", \
    "cdf": [{"remotelevel": "orange", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [1,1,7]}}]}

#pragma cle def TAG_RESPONSE_RUN_VIDEOPROC {"level": "green", \
    "cdf": [{"remotelevel": "green", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [2,2,8]}}]}

#pragma cle def TAG_REQUEST_SEND_CAMCMD {"level": "green", \
    "cdf": [{"remotelevel": "orange", "direction": "egress", \
            "guarddirective": {"operation": "allow", "gapstag": [1,1,9]}}]}

#pragma cle def TAG_RESPONSE_SEND_CAMCMD {"level": "green", \
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

extern int _err_handle_rpc_get_frame(char buf[]);
extern int _err_handle_rpc_get_metadata(double lat[],double lon[],double alt[],double ts[]);
extern int _err_handle_rpc_run_videoproc(void);
extern int _err_handle_rpc_send_camcmd(double pan,double tilt,double imptime,char mode,char stab);

#endif /* _GREEN_RPC_ */
