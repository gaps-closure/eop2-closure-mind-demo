#ifdef _cplusplus
extern "C" {
#endif /* _cplusplus */

#include "codec.h"

void nextrpc_print (nextrpc_datatype *nextrpc) {
  fprintf(stderr, "nextrpc(len=%ld): ", sizeof(*nextrpc));
  fprintf(stderr, " %d,", nextrpc->mux);
  fprintf(stderr, " %d,", nextrpc->sec);
  fprintf(stderr, " %d,", nextrpc->typ);
  fprintf(stderr, " %u, %u, %u, %hu, %hu\n",
          nextrpc->trailer.seq,
          nextrpc->trailer.rqr,
          nextrpc->trailer.oid,
          nextrpc->trailer.mid,
          nextrpc->trailer.crc);
}

void nextrpc_data_encode (void *buff_out, void *buff_in, size_t *len_out) {
  nextrpc_datatype *p1 = (nextrpc_datatype *) buff_in;
  nextrpc_output   *p2 = (nextrpc_output *)   buff_out;
  p2->mux = htonl(p1->mux);
  p2->sec = htonl(p1->sec);
  p2->typ = htonl(p1->typ);
  p2->trailer.seq = htonl(p1->trailer.seq);
  p2->trailer.rqr = htonl(p1->trailer.rqr);
  p2->trailer.oid = htonl(p1->trailer.oid);
  p2->trailer.mid = htons(p1->trailer.mid);
  p2->trailer.crc = htons(p1->trailer.crc);
  *len_out = sizeof(int32_t) + sizeof(int32_t) + sizeof(int32_t) + sizeof(trailer_datatype);
}

void nextrpc_data_decode (void *buff_out, void *buff_in, size_t *len_in) {
  nextrpc_output   *p1 = (nextrpc_output *)   buff_in;
  nextrpc_datatype *p2 = (nextrpc_datatype *) buff_out;
  p2->mux = ntohl(p1->mux);
  p2->sec = ntohl(p1->sec);
  p2->typ = ntohl(p1->typ);
  p2->trailer.seq = ntohl(p1->trailer.seq);
  p2->trailer.rqr = ntohl(p1->trailer.rqr);
  p2->trailer.oid = ntohl(p1->trailer.oid);
  p2->trailer.mid = ntohs(p1->trailer.mid);
  p2->trailer.crc = ntohs(p1->trailer.crc);
}

void okay_print (okay_datatype *okay) {
  fprintf(stderr, "okay(len=%ld): ", sizeof(*okay));
  fprintf(stderr, " %d,", okay->x);
  fprintf(stderr, " %u, %u, %u, %hu, %hu\n",
          okay->trailer.seq,
          okay->trailer.rqr,
          okay->trailer.oid,
          okay->trailer.mid,
          okay->trailer.crc);
}

void okay_data_encode (void *buff_out, void *buff_in, size_t *len_out) {
  okay_datatype *p1 = (okay_datatype *) buff_in;
  okay_output   *p2 = (okay_output *)   buff_out;
  p2->x = htonl(p1->x);
  p2->trailer.seq = htonl(p1->trailer.seq);
  p2->trailer.rqr = htonl(p1->trailer.rqr);
  p2->trailer.oid = htonl(p1->trailer.oid);
  p2->trailer.mid = htons(p1->trailer.mid);
  p2->trailer.crc = htons(p1->trailer.crc);
  *len_out = sizeof(int32_t) + sizeof(trailer_datatype);
}

void okay_data_decode (void *buff_out, void *buff_in, size_t *len_in) {
  okay_output   *p1 = (okay_output *)   buff_in;
  okay_datatype *p2 = (okay_datatype *) buff_out;
  p2->x = ntohl(p1->x);
  p2->trailer.seq = ntohl(p1->trailer.seq);
  p2->trailer.rqr = ntohl(p1->trailer.rqr);
  p2->trailer.oid = ntohl(p1->trailer.oid);
  p2->trailer.mid = ntohs(p1->trailer.mid);
  p2->trailer.crc = ntohs(p1->trailer.crc);
}

void request_get_frame_print (request_get_frame_datatype *request_get_frame) {
  fprintf(stderr, "request_get_frame(len=%ld): ", sizeof(*request_get_frame));
  fprintf(stderr, " %d,", request_get_frame->dummy);
  fprintf(stderr, " %u, %u, %u, %hu, %hu\n",
          request_get_frame->trailer.seq,
          request_get_frame->trailer.rqr,
          request_get_frame->trailer.oid,
          request_get_frame->trailer.mid,
          request_get_frame->trailer.crc);
}

void request_get_frame_data_encode (void *buff_out, void *buff_in, size_t *len_out) {
  request_get_frame_datatype *p1 = (request_get_frame_datatype *) buff_in;
  request_get_frame_output   *p2 = (request_get_frame_output *)   buff_out;
  p2->dummy = htonl(p1->dummy);
  p2->trailer.seq = htonl(p1->trailer.seq);
  p2->trailer.rqr = htonl(p1->trailer.rqr);
  p2->trailer.oid = htonl(p1->trailer.oid);
  p2->trailer.mid = htons(p1->trailer.mid);
  p2->trailer.crc = htons(p1->trailer.crc);
  *len_out = sizeof(int32_t) + sizeof(trailer_datatype);
}

void request_get_frame_data_decode (void *buff_out, void *buff_in, size_t *len_in) {
  request_get_frame_output   *p1 = (request_get_frame_output *)   buff_in;
  request_get_frame_datatype *p2 = (request_get_frame_datatype *) buff_out;
  p2->dummy = ntohl(p1->dummy);
  p2->trailer.seq = ntohl(p1->trailer.seq);
  p2->trailer.rqr = ntohl(p1->trailer.rqr);
  p2->trailer.oid = ntohl(p1->trailer.oid);
  p2->trailer.mid = ntohs(p1->trailer.mid);
  p2->trailer.crc = ntohs(p1->trailer.crc);
}

void response_get_frame_print (response_get_frame_datatype *response_get_frame) {
  fprintf(stderr, "response_get_frame(len=%ld): ", sizeof(*response_get_frame));
  fprintf(stderr, " %d,", response_get_frame->ret);
  for (int i=0; i<64000; i++) {
    fprintf(stderr, " %hd,", response_get_frame->buf[i]);
  }
  fprintf(stderr, " %u, %u, %u, %hu, %hu\n",
          response_get_frame->trailer.seq,
          response_get_frame->trailer.rqr,
          response_get_frame->trailer.oid,
          response_get_frame->trailer.mid,
          response_get_frame->trailer.crc);
}

void response_get_frame_data_encode (void *buff_out, void *buff_in, size_t *len_out) {
  response_get_frame_datatype *p1 = (response_get_frame_datatype *) buff_in;
  response_get_frame_output   *p2 = (response_get_frame_output *)   buff_out;
  p2->ret = htonl(p1->ret);
  for (int i=0; i<64000; i++) {
    p2->buf[i] = codec_id(p1->buf[i]);
  }
  p2->trailer.seq = htonl(p1->trailer.seq);
  p2->trailer.rqr = htonl(p1->trailer.rqr);
  p2->trailer.oid = htonl(p1->trailer.oid);
  p2->trailer.mid = htons(p1->trailer.mid);
  p2->trailer.crc = htons(p1->trailer.crc);
  *len_out = sizeof(int32_t) + sizeof(int8_t) * 64000 + sizeof(trailer_datatype);
}

void response_get_frame_data_decode (void *buff_out, void *buff_in, size_t *len_in) {
  response_get_frame_output   *p1 = (response_get_frame_output *)   buff_in;
  response_get_frame_datatype *p2 = (response_get_frame_datatype *) buff_out;
  p2->ret = ntohl(p1->ret);
  for (int i=0; i<64000; i++) {
    p2->buf[i] = codec_id(p1->buf[i]);
  }
  p2->trailer.seq = ntohl(p1->trailer.seq);
  p2->trailer.rqr = ntohl(p1->trailer.rqr);
  p2->trailer.oid = ntohl(p1->trailer.oid);
  p2->trailer.mid = ntohs(p1->trailer.mid);
  p2->trailer.crc = ntohs(p1->trailer.crc);
}

void request_get_metadata_print (request_get_metadata_datatype *request_get_metadata) {
  fprintf(stderr, "request_get_metadata(len=%ld): ", sizeof(*request_get_metadata));
  fprintf(stderr, " %d,", request_get_metadata->dummy);
  fprintf(stderr, " %u, %u, %u, %hu, %hu\n",
          request_get_metadata->trailer.seq,
          request_get_metadata->trailer.rqr,
          request_get_metadata->trailer.oid,
          request_get_metadata->trailer.mid,
          request_get_metadata->trailer.crc);
}

void request_get_metadata_data_encode (void *buff_out, void *buff_in, size_t *len_out) {
  request_get_metadata_datatype *p1 = (request_get_metadata_datatype *) buff_in;
  request_get_metadata_output   *p2 = (request_get_metadata_output *)   buff_out;
  p2->dummy = htonl(p1->dummy);
  p2->trailer.seq = htonl(p1->trailer.seq);
  p2->trailer.rqr = htonl(p1->trailer.rqr);
  p2->trailer.oid = htonl(p1->trailer.oid);
  p2->trailer.mid = htons(p1->trailer.mid);
  p2->trailer.crc = htons(p1->trailer.crc);
  *len_out = sizeof(int32_t) + sizeof(trailer_datatype);
}

void request_get_metadata_data_decode (void *buff_out, void *buff_in, size_t *len_in) {
  request_get_metadata_output   *p1 = (request_get_metadata_output *)   buff_in;
  request_get_metadata_datatype *p2 = (request_get_metadata_datatype *) buff_out;
  p2->dummy = ntohl(p1->dummy);
  p2->trailer.seq = ntohl(p1->trailer.seq);
  p2->trailer.rqr = ntohl(p1->trailer.rqr);
  p2->trailer.oid = ntohl(p1->trailer.oid);
  p2->trailer.mid = ntohs(p1->trailer.mid);
  p2->trailer.crc = ntohs(p1->trailer.crc);
}

void response_get_metadata_print (response_get_metadata_datatype *response_get_metadata) {
  fprintf(stderr, "response_get_metadata(len=%ld): ", sizeof(*response_get_metadata));
  fprintf(stderr, " %d,", response_get_metadata->ret);
  for (int i=0; i<1; i++) {
    fprintf(stderr, " %lf,", response_get_metadata->lat[i]);
  }
  for (int i=0; i<1; i++) {
    fprintf(stderr, " %lf,", response_get_metadata->lon[i]);
  }
  for (int i=0; i<1; i++) {
    fprintf(stderr, " %lf,", response_get_metadata->alt[i]);
  }
  for (int i=0; i<1; i++) {
    fprintf(stderr, " %lf,", response_get_metadata->ts[i]);
  }
  fprintf(stderr, " %u, %u, %u, %hu, %hu\n",
          response_get_metadata->trailer.seq,
          response_get_metadata->trailer.rqr,
          response_get_metadata->trailer.oid,
          response_get_metadata->trailer.mid,
          response_get_metadata->trailer.crc);
}

void response_get_metadata_data_encode (void *buff_out, void *buff_in, size_t *len_out) {
  response_get_metadata_datatype *p1 = (response_get_metadata_datatype *) buff_in;
  response_get_metadata_output   *p2 = (response_get_metadata_output *)   buff_out;
  p2->ret = htonl(p1->ret);
  for (int i=0; i<1; i++) {
    p2->lat[i] = htond(p1->lat[i]);
  }
  for (int i=0; i<1; i++) {
    p2->lon[i] = htond(p1->lon[i]);
  }
  for (int i=0; i<1; i++) {
    p2->alt[i] = htond(p1->alt[i]);
  }
  for (int i=0; i<1; i++) {
    p2->ts[i] = htond(p1->ts[i]);
  }
  p2->trailer.seq = htonl(p1->trailer.seq);
  p2->trailer.rqr = htonl(p1->trailer.rqr);
  p2->trailer.oid = htonl(p1->trailer.oid);
  p2->trailer.mid = htons(p1->trailer.mid);
  p2->trailer.crc = htons(p1->trailer.crc);
  *len_out = sizeof(int32_t) + sizeof(double) * 1 + sizeof(double) * 1 + sizeof(double) * 1 + sizeof(double) * 1 + sizeof(trailer_datatype);
}

void response_get_metadata_data_decode (void *buff_out, void *buff_in, size_t *len_in) {
  response_get_metadata_output   *p1 = (response_get_metadata_output *)   buff_in;
  response_get_metadata_datatype *p2 = (response_get_metadata_datatype *) buff_out;
  p2->ret = ntohl(p1->ret);
  for (int i=0; i<1; i++) {
    p2->lat[i] = ntohd(p1->lat[i]);
  }
  for (int i=0; i<1; i++) {
    p2->lon[i] = ntohd(p1->lon[i]);
  }
  for (int i=0; i<1; i++) {
    p2->alt[i] = ntohd(p1->alt[i]);
  }
  for (int i=0; i<1; i++) {
    p2->ts[i] = ntohd(p1->ts[i]);
  }
  p2->trailer.seq = ntohl(p1->trailer.seq);
  p2->trailer.rqr = ntohl(p1->trailer.rqr);
  p2->trailer.oid = ntohl(p1->trailer.oid);
  p2->trailer.mid = ntohs(p1->trailer.mid);
  p2->trailer.crc = ntohs(p1->trailer.crc);
}

void request_run_videoproc_print (request_run_videoproc_datatype *request_run_videoproc) {
  fprintf(stderr, "request_run_videoproc(len=%ld): ", sizeof(*request_run_videoproc));
  fprintf(stderr, " %d,", request_run_videoproc->dummy);
  fprintf(stderr, " %u, %u, %u, %hu, %hu\n",
          request_run_videoproc->trailer.seq,
          request_run_videoproc->trailer.rqr,
          request_run_videoproc->trailer.oid,
          request_run_videoproc->trailer.mid,
          request_run_videoproc->trailer.crc);
}

void request_run_videoproc_data_encode (void *buff_out, void *buff_in, size_t *len_out) {
  request_run_videoproc_datatype *p1 = (request_run_videoproc_datatype *) buff_in;
  request_run_videoproc_output   *p2 = (request_run_videoproc_output *)   buff_out;
  p2->dummy = htonl(p1->dummy);
  p2->trailer.seq = htonl(p1->trailer.seq);
  p2->trailer.rqr = htonl(p1->trailer.rqr);
  p2->trailer.oid = htonl(p1->trailer.oid);
  p2->trailer.mid = htons(p1->trailer.mid);
  p2->trailer.crc = htons(p1->trailer.crc);
  *len_out = sizeof(int32_t) + sizeof(trailer_datatype);
}

void request_run_videoproc_data_decode (void *buff_out, void *buff_in, size_t *len_in) {
  request_run_videoproc_output   *p1 = (request_run_videoproc_output *)   buff_in;
  request_run_videoproc_datatype *p2 = (request_run_videoproc_datatype *) buff_out;
  p2->dummy = ntohl(p1->dummy);
  p2->trailer.seq = ntohl(p1->trailer.seq);
  p2->trailer.rqr = ntohl(p1->trailer.rqr);
  p2->trailer.oid = ntohl(p1->trailer.oid);
  p2->trailer.mid = ntohs(p1->trailer.mid);
  p2->trailer.crc = ntohs(p1->trailer.crc);
}

void response_run_videoproc_print (response_run_videoproc_datatype *response_run_videoproc) {
  fprintf(stderr, "response_run_videoproc(len=%ld): ", sizeof(*response_run_videoproc));
  fprintf(stderr, " %d,", response_run_videoproc->ret);
  fprintf(stderr, " %u, %u, %u, %hu, %hu\n",
          response_run_videoproc->trailer.seq,
          response_run_videoproc->trailer.rqr,
          response_run_videoproc->trailer.oid,
          response_run_videoproc->trailer.mid,
          response_run_videoproc->trailer.crc);
}

void response_run_videoproc_data_encode (void *buff_out, void *buff_in, size_t *len_out) {
  response_run_videoproc_datatype *p1 = (response_run_videoproc_datatype *) buff_in;
  response_run_videoproc_output   *p2 = (response_run_videoproc_output *)   buff_out;
  p2->ret = htonl(p1->ret);
  p2->trailer.seq = htonl(p1->trailer.seq);
  p2->trailer.rqr = htonl(p1->trailer.rqr);
  p2->trailer.oid = htonl(p1->trailer.oid);
  p2->trailer.mid = htons(p1->trailer.mid);
  p2->trailer.crc = htons(p1->trailer.crc);
  *len_out = sizeof(int32_t) + sizeof(trailer_datatype);
}

void response_run_videoproc_data_decode (void *buff_out, void *buff_in, size_t *len_in) {
  response_run_videoproc_output   *p1 = (response_run_videoproc_output *)   buff_in;
  response_run_videoproc_datatype *p2 = (response_run_videoproc_datatype *) buff_out;
  p2->ret = ntohl(p1->ret);
  p2->trailer.seq = ntohl(p1->trailer.seq);
  p2->trailer.rqr = ntohl(p1->trailer.rqr);
  p2->trailer.oid = ntohl(p1->trailer.oid);
  p2->trailer.mid = ntohs(p1->trailer.mid);
  p2->trailer.crc = ntohs(p1->trailer.crc);
}

void request_send_camcmd_print (request_send_camcmd_datatype *request_send_camcmd) {
  fprintf(stderr, "request_send_camcmd(len=%ld): ", sizeof(*request_send_camcmd));
  fprintf(stderr, " %lf,", request_send_camcmd->pan);
  fprintf(stderr, " %lf,", request_send_camcmd->tilt);
  fprintf(stderr, " %lf,", request_send_camcmd->imptime);
  fprintf(stderr, " %hd,", request_send_camcmd->mode);
  fprintf(stderr, " %hd,", request_send_camcmd->stab);
  fprintf(stderr, " %u, %u, %u, %hu, %hu\n",
          request_send_camcmd->trailer.seq,
          request_send_camcmd->trailer.rqr,
          request_send_camcmd->trailer.oid,
          request_send_camcmd->trailer.mid,
          request_send_camcmd->trailer.crc);
}

void request_send_camcmd_data_encode (void *buff_out, void *buff_in, size_t *len_out) {
  request_send_camcmd_datatype *p1 = (request_send_camcmd_datatype *) buff_in;
  request_send_camcmd_output   *p2 = (request_send_camcmd_output *)   buff_out;
  p2->pan = htond(p1->pan);
  p2->tilt = htond(p1->tilt);
  p2->imptime = htond(p1->imptime);
  p2->mode = codec_id(p1->mode);
  p2->stab = codec_id(p1->stab);
  p2->trailer.seq = htonl(p1->trailer.seq);
  p2->trailer.rqr = htonl(p1->trailer.rqr);
  p2->trailer.oid = htonl(p1->trailer.oid);
  p2->trailer.mid = htons(p1->trailer.mid);
  p2->trailer.crc = htons(p1->trailer.crc);
  *len_out = sizeof(double) + sizeof(double) + sizeof(double) + sizeof(int8_t) + sizeof(int8_t) + sizeof(trailer_datatype);
}

void request_send_camcmd_data_decode (void *buff_out, void *buff_in, size_t *len_in) {
  request_send_camcmd_output   *p1 = (request_send_camcmd_output *)   buff_in;
  request_send_camcmd_datatype *p2 = (request_send_camcmd_datatype *) buff_out;
  p2->pan = ntohd(p1->pan);
  p2->tilt = ntohd(p1->tilt);
  p2->imptime = ntohd(p1->imptime);
  p2->mode = codec_id(p1->mode);
  p2->stab = codec_id(p1->stab);
  p2->trailer.seq = ntohl(p1->trailer.seq);
  p2->trailer.rqr = ntohl(p1->trailer.rqr);
  p2->trailer.oid = ntohl(p1->trailer.oid);
  p2->trailer.mid = ntohs(p1->trailer.mid);
  p2->trailer.crc = ntohs(p1->trailer.crc);
}

void response_send_camcmd_print (response_send_camcmd_datatype *response_send_camcmd) {
  fprintf(stderr, "response_send_camcmd(len=%ld): ", sizeof(*response_send_camcmd));
  fprintf(stderr, " %d,", response_send_camcmd->ret);
  fprintf(stderr, " %u, %u, %u, %hu, %hu\n",
          response_send_camcmd->trailer.seq,
          response_send_camcmd->trailer.rqr,
          response_send_camcmd->trailer.oid,
          response_send_camcmd->trailer.mid,
          response_send_camcmd->trailer.crc);
}

void response_send_camcmd_data_encode (void *buff_out, void *buff_in, size_t *len_out) {
  response_send_camcmd_datatype *p1 = (response_send_camcmd_datatype *) buff_in;
  response_send_camcmd_output   *p2 = (response_send_camcmd_output *)   buff_out;
  p2->ret = htonl(p1->ret);
  p2->trailer.seq = htonl(p1->trailer.seq);
  p2->trailer.rqr = htonl(p1->trailer.rqr);
  p2->trailer.oid = htonl(p1->trailer.oid);
  p2->trailer.mid = htons(p1->trailer.mid);
  p2->trailer.crc = htons(p1->trailer.crc);
  *len_out = sizeof(int32_t) + sizeof(trailer_datatype);
}

void response_send_camcmd_data_decode (void *buff_out, void *buff_in, size_t *len_in) {
  response_send_camcmd_output   *p1 = (response_send_camcmd_output *)   buff_in;
  response_send_camcmd_datatype *p2 = (response_send_camcmd_datatype *) buff_out;
  p2->ret = ntohl(p1->ret);
  p2->trailer.seq = ntohl(p1->trailer.seq);
  p2->trailer.rqr = ntohl(p1->trailer.rqr);
  p2->trailer.oid = ntohl(p1->trailer.oid);
  p2->trailer.mid = ntohs(p1->trailer.mid);
  p2->trailer.crc = ntohs(p1->trailer.crc);
}


#ifdef _cplusplus
}
#endif /* _cplusplus */
