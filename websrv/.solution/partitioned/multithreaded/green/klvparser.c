#include "klvparser.h"
#include "Constants.h"
#include "fielddecode.h"
#include "scaleddecode.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct KlvTag_t
{
    uint8_t Key;
    uint32_t Length;
    uint8_t *pData;
    struct KlvTag_t *pNext;
} KlvTag_t;


// Define to output data in radians, undefine for degrees
#define RADIANS

#ifdef RADIANS
# define CONVERT_ANGLE(x) radians(x)
#else
# define CONVERT_ANGLE(x) (x)
#endif // RADIANS

typedef enum
{
    KLV_TYPE_UINT,
    KLV_TYPE_INT,
    KLV_TYPE_DOUBLE,
    KLV_TYPE_STRING,
    KLV_TYPE_OTHER
} KlvType_t;

typedef struct
{
    char Name[64];
    KlvType_t Type;
    double Min;
    double Max;
} KlvTagInfo_t;




















