#include "cameractl.h"
#include "klvparser.h"

#include "OrionPublicPacket.h"
#include "OrionComm.h"
#include "Constants.h"
#include "fielddecode.h"
#include "earthposition.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/rational.h"
#include "libavutil/avstring.h"
#include "libavutil/imgutils.h"
#include "libswscale/swscale.h"

#if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(55,28,1)
#error "libavcodec version >= 55.28.1 required"
#endif

// For GEDL heuristics

// Incoming and outgoing packet structures. 




















