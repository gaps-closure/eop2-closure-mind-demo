#ifdef _cplusplus
extern "C" {
#endif /* _cplusplus */

#ifndef GMA_HEADER_FILE
#define GMA_HEADER_FILE

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include <arpa/inet.h>
#include <float.h>

#include "float754.h"

#define codec_id(X) (X)

#pragma pack(push,1)
typedef struct _trailer_datatype {
  uint32_t seq;
  uint32_t rqr;
  uint32_t oid;
  uint16_t mid;
  uint16_t crc;
} trailer_datatype;
#pragma pack(pop)

#ifndef TYP_BASE
#define TYP_BASE 0
#endif /* TYP_BASE */
#define DATA_TYP_NEXTRPC TYP_BASE + 1
#define DATA_TYP_OKAY TYP_BASE + 2
#define DATA_TYP_REQUEST_GET_FRAME TYP_BASE + 3
#define DATA_TYP_RESPONSE_GET_FRAME TYP_BASE + 4
#define DATA_TYP_REQUEST_GET_METADATA TYP_BASE + 5
#define DATA_TYP_RESPONSE_GET_METADATA TYP_BASE + 6
#define DATA_TYP_REQUEST_RUN_VIDEOPROC TYP_BASE + 7
#define DATA_TYP_RESPONSE_RUN_VIDEOPROC TYP_BASE + 8
#define DATA_TYP_REQUEST_SEND_CAMCMD TYP_BASE + 9
#define DATA_TYP_RESPONSE_SEND_CAMCMD TYP_BASE + 10

#pragma pack(push,1)
typedef struct _nextrpc_datatype {
  int32_t mux;
  int32_t sec;
  int32_t typ;
  trailer_datatype trailer;
} nextrpc_datatype;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _nextrpc_output {
  int32_t mux;
  int32_t sec;
  int32_t typ;
  trailer_datatype trailer;
} nextrpc_output;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _okay_datatype {
  int32_t x;
  trailer_datatype trailer;
} okay_datatype;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _okay_output {
  int32_t x;
  trailer_datatype trailer;
} okay_output;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _request_get_frame_datatype {
  int32_t dummy;
  trailer_datatype trailer;
} request_get_frame_datatype;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _request_get_frame_output {
  int32_t dummy;
  trailer_datatype trailer;
} request_get_frame_output;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _response_get_frame_datatype {
  int32_t ret;
  int8_t buf[64000];
  trailer_datatype trailer;
} response_get_frame_datatype;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _response_get_frame_output {
  int32_t ret;
  int8_t buf[64000];
  trailer_datatype trailer;
} response_get_frame_output;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _request_get_metadata_datatype {
  int32_t dummy;
  trailer_datatype trailer;
} request_get_metadata_datatype;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _request_get_metadata_output {
  int32_t dummy;
  trailer_datatype trailer;
} request_get_metadata_output;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _response_get_metadata_datatype {
  int32_t ret;
  double lat[1];
  double lon[1];
  double alt[1];
  double ts[1];
  trailer_datatype trailer;
} response_get_metadata_datatype;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _response_get_metadata_output {
  int32_t ret;
  uint64_t lat[1];
  uint64_t lon[1];
  uint64_t alt[1];
  uint64_t ts[1];
  trailer_datatype trailer;
} response_get_metadata_output;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _request_run_videoproc_datatype {
  int32_t dummy;
  trailer_datatype trailer;
} request_run_videoproc_datatype;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _request_run_videoproc_output {
  int32_t dummy;
  trailer_datatype trailer;
} request_run_videoproc_output;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _response_run_videoproc_datatype {
  int32_t ret;
  trailer_datatype trailer;
} response_run_videoproc_datatype;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _response_run_videoproc_output {
  int32_t ret;
  trailer_datatype trailer;
} response_run_videoproc_output;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _request_send_camcmd_datatype {
  double pan;
  double tilt;
  double imptime;
  int8_t mode;
  int8_t stab;
  trailer_datatype trailer;
} request_send_camcmd_datatype;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _request_send_camcmd_output {
  uint64_t pan;
  uint64_t tilt;
  uint64_t imptime;
  int8_t mode;
  int8_t stab;
  trailer_datatype trailer;
} request_send_camcmd_output;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _response_send_camcmd_datatype {
  int32_t ret;
  trailer_datatype trailer;
} response_send_camcmd_datatype;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _response_send_camcmd_output {
  int32_t ret;
  trailer_datatype trailer;
} response_send_camcmd_output;
#pragma pack(pop)

extern void nextrpc_print (nextrpc_datatype *nextrpc);
extern void nextrpc_data_encode (void *buff_out, void *buff_in, size_t *len_out);
extern void nextrpc_data_decode (void *buff_out, void *buff_in, size_t *len_in);

extern void okay_print (okay_datatype *okay);
extern void okay_data_encode (void *buff_out, void *buff_in, size_t *len_out);
extern void okay_data_decode (void *buff_out, void *buff_in, size_t *len_in);

extern void request_get_frame_print (request_get_frame_datatype *request_get_frame);
extern void request_get_frame_data_encode (void *buff_out, void *buff_in, size_t *len_out);
extern void request_get_frame_data_decode (void *buff_out, void *buff_in, size_t *len_in);

extern void response_get_frame_print (response_get_frame_datatype *response_get_frame);
extern void response_get_frame_data_encode (void *buff_out, void *buff_in, size_t *len_out);
extern void response_get_frame_data_decode (void *buff_out, void *buff_in, size_t *len_in);

extern void request_get_metadata_print (request_get_metadata_datatype *request_get_metadata);
extern void request_get_metadata_data_encode (void *buff_out, void *buff_in, size_t *len_out);
extern void request_get_metadata_data_decode (void *buff_out, void *buff_in, size_t *len_in);

extern void response_get_metadata_print (response_get_metadata_datatype *response_get_metadata);
extern void response_get_metadata_data_encode (void *buff_out, void *buff_in, size_t *len_out);
extern void response_get_metadata_data_decode (void *buff_out, void *buff_in, size_t *len_in);

extern void request_run_videoproc_print (request_run_videoproc_datatype *request_run_videoproc);
extern void request_run_videoproc_data_encode (void *buff_out, void *buff_in, size_t *len_out);
extern void request_run_videoproc_data_decode (void *buff_out, void *buff_in, size_t *len_in);

extern void response_run_videoproc_print (response_run_videoproc_datatype *response_run_videoproc);
extern void response_run_videoproc_data_encode (void *buff_out, void *buff_in, size_t *len_out);
extern void response_run_videoproc_data_decode (void *buff_out, void *buff_in, size_t *len_in);

extern void request_send_camcmd_print (request_send_camcmd_datatype *request_send_camcmd);
extern void request_send_camcmd_data_encode (void *buff_out, void *buff_in, size_t *len_out);
extern void request_send_camcmd_data_decode (void *buff_out, void *buff_in, size_t *len_in);

extern void response_send_camcmd_print (response_send_camcmd_datatype *response_send_camcmd);
extern void response_send_camcmd_data_encode (void *buff_out, void *buff_in, size_t *len_out);
extern void response_send_camcmd_data_decode (void *buff_out, void *buff_in, size_t *len_in);

#endif /* GMA_HEADER_FILE */

#ifdef _cplusplus
}
#endif /* _cplusplus */
