#include "orange_rpc.h"
#define TAG_MATCH(X, Y) (X.mux == Y.mux && X.sec == Y.sec && X.typ == Y.typ)
#define WRAP(X) void *_wrapper_##X(void *tag) { while(1) { _handle_##X(); } }

void _hal_init(char *inuri, char *outuri) {
    xdc_log_level(2);
#ifdef __LEGACY_XDCOMMS__
    xdc_set_in(inuri);
    xdc_set_out(outuri);
    xdc_register(request_get_frame_data_encode, request_get_frame_data_decode, DATA_TYP_REQUEST_GET_FRAME);
    xdc_register(response_get_frame_data_encode, response_get_frame_data_decode, DATA_TYP_RESPONSE_GET_FRAME);
    xdc_register(request_get_metadata_data_encode, request_get_metadata_data_decode, DATA_TYP_REQUEST_GET_METADATA);
    xdc_register(response_get_metadata_data_encode, response_get_metadata_data_decode, DATA_TYP_RESPONSE_GET_METADATA);
    xdc_register(request_run_videoproc_data_encode, request_run_videoproc_data_decode, DATA_TYP_REQUEST_RUN_VIDEOPROC);
    xdc_register(response_run_videoproc_data_encode, response_run_videoproc_data_decode, DATA_TYP_RESPONSE_RUN_VIDEOPROC);
    xdc_register(request_send_camcmd_data_encode, request_send_camcmd_data_decode, DATA_TYP_REQUEST_SEND_CAMCMD);
    xdc_register(response_send_camcmd_data_encode, response_send_camcmd_data_decode, DATA_TYP_RESPONSE_SEND_CAMCMD);
#endif /* __LEGACY_XDCOMMS__ */

}

#pragma cle begin HANDLE_REQUEST_GET_FRAME
#pragma clang attribute push (__attribute__((annotate("HANDLE_REQUEST_GET_FRAME"))), apply_to = any(function,type_alias,record,enum,variable(unless(is_parameter)),field))
void _handle_request_get_frame() {
#pragma clang attribute pop
#pragma cle end HANDLE_REQUEST_GET_FRAME
    gaps_tag t_tag;
    gaps_tag o_tag;
#ifndef __LEGACY_XDCOMMS__
    my_tag_write(&t_tag, MUX_REQUEST_GET_FRAME, SEC_REQUEST_GET_FRAME, DATA_TYP_REQUEST_GET_FRAME);
#else
    tag_write(&t_tag, MUX_REQUEST_GET_FRAME, SEC_REQUEST_GET_FRAME, DATA_TYP_REQUEST_GET_FRAME);
#endif /* __LEGACY_XDCOMMS__ */
#ifndef __LEGACY_XDCOMMS__
    my_tag_write(&o_tag, MUX_RESPONSE_GET_FRAME, SEC_RESPONSE_GET_FRAME, DATA_TYP_RESPONSE_GET_FRAME);
#else
    tag_write(&o_tag, MUX_RESPONSE_GET_FRAME, SEC_RESPONSE_GET_FRAME, DATA_TYP_RESPONSE_GET_FRAME);
#endif /* __LEGACY_XDCOMMS__ */
    static int res_counter = 0;
    static int last_processed_result = 0;
    static int last_processed_error = 0;
    static int inited = 0;
#ifndef __LEGACY_XDCOMMS__
    void *psocket;
    void *ssocket;
#else
    static void *psocket;
    static void *ssocket;
#endif /* __LEGACY_XDCOMMS__ */
    #pragma cle begin TAG_REQUEST_GET_FRAME
    request_get_frame_datatype request_get_frame;
    #pragma cle end TAG_REQUEST_GET_FRAME
    #pragma cle begin TAG_RESPONSE_GET_FRAME
    response_get_frame_datatype response_get_frame;
    #pragma cle end TAG_RESPONSE_GET_FRAME
#ifndef __LEGACY_XDCOMMS__
    codec_map  mycmap[DATA_TYP_MAX];
    for (int i=0; i < DATA_TYP_MAX; i++)  mycmap[i].valid=0;
    my_xdc_register(request_get_frame_data_encode, request_get_frame_data_decode, DATA_TYP_REQUEST_GET_FRAME, mycmap);
    my_xdc_register(response_get_frame_data_encode, response_get_frame_data_decode, DATA_TYP_RESPONSE_GET_FRAME, mycmap);
    my_xdc_register(request_get_metadata_data_encode, request_get_metadata_data_decode, DATA_TYP_REQUEST_GET_METADATA, mycmap);
    my_xdc_register(response_get_metadata_data_encode, response_get_metadata_data_decode, DATA_TYP_RESPONSE_GET_METADATA, mycmap);
    my_xdc_register(request_run_videoproc_data_encode, request_run_videoproc_data_decode, DATA_TYP_REQUEST_RUN_VIDEOPROC, mycmap);
    my_xdc_register(response_run_videoproc_data_encode, response_run_videoproc_data_decode, DATA_TYP_RESPONSE_RUN_VIDEOPROC, mycmap);
    my_xdc_register(request_send_camcmd_data_encode, request_send_camcmd_data_decode, DATA_TYP_REQUEST_SEND_CAMCMD, mycmap);
    my_xdc_register(response_send_camcmd_data_encode, response_send_camcmd_data_decode, DATA_TYP_RESPONSE_SEND_CAMCMD, mycmap);
#endif /* __LEGACY_XDCOMMS__ */
#ifndef __LEGACY_XDCOMMS__
    void * ctx = zmq_ctx_new();
    psocket = my_xdc_pub_socket(ctx, (char *)OUTURI);
    ssocket = my_xdc_sub_socket(t_tag, ctx, (char*)INURI);
    sleep(1); /* zmq socket join delay */
#else
    if (!inited) {
        inited = 1;
        psocket = xdc_pub_socket();
        ssocket = xdc_sub_socket(t_tag);
        sleep(1); /* zmq socket join delay */
    }
#endif /* __LEGACY_XDCOMMS__ */
#ifndef __LEGACY_XDCOMMS__
    int proc_error = 1;
    while (proc_error == 1) {
        my_xdc_blocking_recv(ssocket, &request_get_frame, &t_tag, mycmap);
        int req_counter = request_get_frame.trailer.seq;
        if(req_counter > res_counter){
            proc_error = 0;
            res_counter = req_counter;
            last_processed_result = get_frame(response_get_frame.buf);
            response_get_frame.ret = last_processed_result;
            last_processed_error = proc_error;
        }
#ifndef __ONEWAY_RPC__
        response_get_frame.trailer.seq = res_counter << 2 | last_processed_error << 1;
        my_xdc_asyn_send(psocket, &response_get_frame, &o_tag, mycmap);
#else /* __ONEWAY_RPC__ */
        res_counter = req_counter;
#endif /* __ONEWAY_RPC__ */
    }
    zmq_close(psocket);
    zmq_close(ssocket);
    zmq_ctx_shutdown(ctx);
#else
    int proc_error = 1;
    while (proc_error == 1) {
        xdc_blocking_recv(ssocket, &request_get_frame, &t_tag);
        int req_counter = request_get_frame.trailer.seq;
        if(req_counter > res_counter){
            proc_error = 0;
            res_counter = req_counter;
            last_processed_result = get_frame(response_get_frame.buf);
            response_get_frame.ret = last_processed_result;
            last_processed_error = proc_error;
        }
#ifndef __ONEWAY_RPC__
        response_get_frame.trailer.seq = res_counter << 2 | last_processed_error << 1;
        xdc_asyn_send(psocket, &response_get_frame, &o_tag);
#else /* __ONEWAY_RPC__ */
        res_counter = req_counter;
#endif /* __ONEWAY_RPC__ */
    }
#endif /* __LEGACY_XDCOMMS__ */
}

#pragma cle begin HANDLE_REQUEST_GET_METADATA
#pragma clang attribute push (__attribute__((annotate("HANDLE_REQUEST_GET_METADATA"))), apply_to = any(function,type_alias,record,enum,variable(unless(is_parameter)),field))
void _handle_request_get_metadata() {
#pragma clang attribute pop
#pragma cle end HANDLE_REQUEST_GET_METADATA
    gaps_tag t_tag;
    gaps_tag o_tag;
#ifndef __LEGACY_XDCOMMS__
    my_tag_write(&t_tag, MUX_REQUEST_GET_METADATA, SEC_REQUEST_GET_METADATA, DATA_TYP_REQUEST_GET_METADATA);
#else
    tag_write(&t_tag, MUX_REQUEST_GET_METADATA, SEC_REQUEST_GET_METADATA, DATA_TYP_REQUEST_GET_METADATA);
#endif /* __LEGACY_XDCOMMS__ */
#ifndef __LEGACY_XDCOMMS__
    my_tag_write(&o_tag, MUX_RESPONSE_GET_METADATA, SEC_RESPONSE_GET_METADATA, DATA_TYP_RESPONSE_GET_METADATA);
#else
    tag_write(&o_tag, MUX_RESPONSE_GET_METADATA, SEC_RESPONSE_GET_METADATA, DATA_TYP_RESPONSE_GET_METADATA);
#endif /* __LEGACY_XDCOMMS__ */
    static int res_counter = 0;
    static int last_processed_result = 0;
    static int last_processed_error = 0;
    static int inited = 0;
#ifndef __LEGACY_XDCOMMS__
    void *psocket;
    void *ssocket;
#else
    static void *psocket;
    static void *ssocket;
#endif /* __LEGACY_XDCOMMS__ */
    #pragma cle begin TAG_REQUEST_GET_METADATA
    request_get_metadata_datatype request_get_metadata;
    #pragma cle end TAG_REQUEST_GET_METADATA
    #pragma cle begin TAG_RESPONSE_GET_METADATA
    response_get_metadata_datatype response_get_metadata;
    #pragma cle end TAG_RESPONSE_GET_METADATA
#ifndef __LEGACY_XDCOMMS__
    codec_map  mycmap[DATA_TYP_MAX];
    for (int i=0; i < DATA_TYP_MAX; i++)  mycmap[i].valid=0;
    my_xdc_register(request_get_frame_data_encode, request_get_frame_data_decode, DATA_TYP_REQUEST_GET_FRAME, mycmap);
    my_xdc_register(response_get_frame_data_encode, response_get_frame_data_decode, DATA_TYP_RESPONSE_GET_FRAME, mycmap);
    my_xdc_register(request_get_metadata_data_encode, request_get_metadata_data_decode, DATA_TYP_REQUEST_GET_METADATA, mycmap);
    my_xdc_register(response_get_metadata_data_encode, response_get_metadata_data_decode, DATA_TYP_RESPONSE_GET_METADATA, mycmap);
    my_xdc_register(request_run_videoproc_data_encode, request_run_videoproc_data_decode, DATA_TYP_REQUEST_RUN_VIDEOPROC, mycmap);
    my_xdc_register(response_run_videoproc_data_encode, response_run_videoproc_data_decode, DATA_TYP_RESPONSE_RUN_VIDEOPROC, mycmap);
    my_xdc_register(request_send_camcmd_data_encode, request_send_camcmd_data_decode, DATA_TYP_REQUEST_SEND_CAMCMD, mycmap);
    my_xdc_register(response_send_camcmd_data_encode, response_send_camcmd_data_decode, DATA_TYP_RESPONSE_SEND_CAMCMD, mycmap);
#endif /* __LEGACY_XDCOMMS__ */
#ifndef __LEGACY_XDCOMMS__
    void * ctx = zmq_ctx_new();
    psocket = my_xdc_pub_socket(ctx, (char *)OUTURI);
    ssocket = my_xdc_sub_socket(t_tag, ctx, (char*)INURI);
    sleep(1); /* zmq socket join delay */
#else
    if (!inited) {
        inited = 1;
        psocket = xdc_pub_socket();
        ssocket = xdc_sub_socket(t_tag);
        sleep(1); /* zmq socket join delay */
    }
#endif /* __LEGACY_XDCOMMS__ */
#ifndef __LEGACY_XDCOMMS__
    int proc_error = 1;
    while (proc_error == 1) {
        my_xdc_blocking_recv(ssocket, &request_get_metadata, &t_tag, mycmap);
        int req_counter = request_get_metadata.trailer.seq;
        if(req_counter > res_counter){
            proc_error = 0;
            res_counter = req_counter;
            last_processed_result = get_metadata(response_get_metadata.lat, response_get_metadata.lon, response_get_metadata.alt, response_get_metadata.ts);
            response_get_metadata.ret = last_processed_result;
            last_processed_error = proc_error;
        }
#ifndef __ONEWAY_RPC__
        response_get_metadata.trailer.seq = res_counter << 2 | last_processed_error << 1;
        my_xdc_asyn_send(psocket, &response_get_metadata, &o_tag, mycmap);
#else /* __ONEWAY_RPC__ */
        res_counter = req_counter;
#endif /* __ONEWAY_RPC__ */
    }
    zmq_close(psocket);
    zmq_close(ssocket);
    zmq_ctx_shutdown(ctx);
#else
    int proc_error = 1;
    while (proc_error == 1) {
        xdc_blocking_recv(ssocket, &request_get_metadata, &t_tag);
        int req_counter = request_get_metadata.trailer.seq;
        if(req_counter > res_counter){
            proc_error = 0;
            res_counter = req_counter;
            last_processed_result = get_metadata(response_get_metadata.lat, response_get_metadata.lon, response_get_metadata.alt, response_get_metadata.ts);
            response_get_metadata.ret = last_processed_result;
            last_processed_error = proc_error;
        }
#ifndef __ONEWAY_RPC__
        response_get_metadata.trailer.seq = res_counter << 2 | last_processed_error << 1;
        xdc_asyn_send(psocket, &response_get_metadata, &o_tag);
#else /* __ONEWAY_RPC__ */
        res_counter = req_counter;
#endif /* __ONEWAY_RPC__ */
    }
#endif /* __LEGACY_XDCOMMS__ */
}

#pragma cle begin HANDLE_REQUEST_RUN_VIDEOPROC
#pragma clang attribute push (__attribute__((annotate("HANDLE_REQUEST_RUN_VIDEOPROC"))), apply_to = any(function,type_alias,record,enum,variable(unless(is_parameter)),field))
void _handle_request_run_videoproc() {
#pragma clang attribute pop
#pragma cle end HANDLE_REQUEST_RUN_VIDEOPROC
    gaps_tag t_tag;
    gaps_tag o_tag;
#ifndef __LEGACY_XDCOMMS__
    my_tag_write(&t_tag, MUX_REQUEST_RUN_VIDEOPROC, SEC_REQUEST_RUN_VIDEOPROC, DATA_TYP_REQUEST_RUN_VIDEOPROC);
#else
    tag_write(&t_tag, MUX_REQUEST_RUN_VIDEOPROC, SEC_REQUEST_RUN_VIDEOPROC, DATA_TYP_REQUEST_RUN_VIDEOPROC);
#endif /* __LEGACY_XDCOMMS__ */
#ifndef __LEGACY_XDCOMMS__
    my_tag_write(&o_tag, MUX_RESPONSE_RUN_VIDEOPROC, SEC_RESPONSE_RUN_VIDEOPROC, DATA_TYP_RESPONSE_RUN_VIDEOPROC);
#else
    tag_write(&o_tag, MUX_RESPONSE_RUN_VIDEOPROC, SEC_RESPONSE_RUN_VIDEOPROC, DATA_TYP_RESPONSE_RUN_VIDEOPROC);
#endif /* __LEGACY_XDCOMMS__ */
    static int res_counter = 0;
    static int last_processed_result = 0;
    static int last_processed_error = 0;
    static int inited = 0;
#ifndef __LEGACY_XDCOMMS__
    void *psocket;
    void *ssocket;
#else
    static void *psocket;
    static void *ssocket;
#endif /* __LEGACY_XDCOMMS__ */
    #pragma cle begin TAG_REQUEST_RUN_VIDEOPROC
    request_run_videoproc_datatype request_run_videoproc;
    #pragma cle end TAG_REQUEST_RUN_VIDEOPROC
    #pragma cle begin TAG_RESPONSE_RUN_VIDEOPROC
    response_run_videoproc_datatype response_run_videoproc;
    #pragma cle end TAG_RESPONSE_RUN_VIDEOPROC
#ifndef __LEGACY_XDCOMMS__
    codec_map  mycmap[DATA_TYP_MAX];
    for (int i=0; i < DATA_TYP_MAX; i++)  mycmap[i].valid=0;
    my_xdc_register(request_get_frame_data_encode, request_get_frame_data_decode, DATA_TYP_REQUEST_GET_FRAME, mycmap);
    my_xdc_register(response_get_frame_data_encode, response_get_frame_data_decode, DATA_TYP_RESPONSE_GET_FRAME, mycmap);
    my_xdc_register(request_get_metadata_data_encode, request_get_metadata_data_decode, DATA_TYP_REQUEST_GET_METADATA, mycmap);
    my_xdc_register(response_get_metadata_data_encode, response_get_metadata_data_decode, DATA_TYP_RESPONSE_GET_METADATA, mycmap);
    my_xdc_register(request_run_videoproc_data_encode, request_run_videoproc_data_decode, DATA_TYP_REQUEST_RUN_VIDEOPROC, mycmap);
    my_xdc_register(response_run_videoproc_data_encode, response_run_videoproc_data_decode, DATA_TYP_RESPONSE_RUN_VIDEOPROC, mycmap);
    my_xdc_register(request_send_camcmd_data_encode, request_send_camcmd_data_decode, DATA_TYP_REQUEST_SEND_CAMCMD, mycmap);
    my_xdc_register(response_send_camcmd_data_encode, response_send_camcmd_data_decode, DATA_TYP_RESPONSE_SEND_CAMCMD, mycmap);
#endif /* __LEGACY_XDCOMMS__ */
#ifndef __LEGACY_XDCOMMS__
    void * ctx = zmq_ctx_new();
    psocket = my_xdc_pub_socket(ctx, (char *)OUTURI);
    ssocket = my_xdc_sub_socket(t_tag, ctx, (char*)INURI);
    sleep(1); /* zmq socket join delay */
#else
    if (!inited) {
        inited = 1;
        psocket = xdc_pub_socket();
        ssocket = xdc_sub_socket(t_tag);
        sleep(1); /* zmq socket join delay */
    }
#endif /* __LEGACY_XDCOMMS__ */
#ifndef __LEGACY_XDCOMMS__
    int proc_error = 1;
    while (proc_error == 1) {
        my_xdc_blocking_recv(ssocket, &request_run_videoproc, &t_tag, mycmap);
        int req_counter = request_run_videoproc.trailer.seq;
        if(req_counter > res_counter){
            proc_error = 0;
            res_counter = req_counter;
            last_processed_result = run_videoproc();
            response_run_videoproc.ret = last_processed_result;
            last_processed_error = proc_error;
        }
#ifndef __ONEWAY_RPC__
        response_run_videoproc.trailer.seq = res_counter << 2 | last_processed_error << 1;
        my_xdc_asyn_send(psocket, &response_run_videoproc, &o_tag, mycmap);
#else /* __ONEWAY_RPC__ */
        res_counter = req_counter;
#endif /* __ONEWAY_RPC__ */
    }
    zmq_close(psocket);
    zmq_close(ssocket);
    zmq_ctx_shutdown(ctx);
#else
    int proc_error = 1;
    while (proc_error == 1) {
        xdc_blocking_recv(ssocket, &request_run_videoproc, &t_tag);
        int req_counter = request_run_videoproc.trailer.seq;
        if(req_counter > res_counter){
            proc_error = 0;
            res_counter = req_counter;
            last_processed_result = run_videoproc();
            response_run_videoproc.ret = last_processed_result;
            last_processed_error = proc_error;
        }
#ifndef __ONEWAY_RPC__
        response_run_videoproc.trailer.seq = res_counter << 2 | last_processed_error << 1;
        xdc_asyn_send(psocket, &response_run_videoproc, &o_tag);
#else /* __ONEWAY_RPC__ */
        res_counter = req_counter;
#endif /* __ONEWAY_RPC__ */
    }
#endif /* __LEGACY_XDCOMMS__ */
}

#pragma cle begin HANDLE_REQUEST_SEND_CAMCMD
#pragma clang attribute push (__attribute__((annotate("HANDLE_REQUEST_SEND_CAMCMD"))), apply_to = any(function,type_alias,record,enum,variable(unless(is_parameter)),field))
void _handle_request_send_camcmd() {
#pragma clang attribute pop
#pragma cle end HANDLE_REQUEST_SEND_CAMCMD
    gaps_tag t_tag;
    gaps_tag o_tag;
#ifndef __LEGACY_XDCOMMS__
    my_tag_write(&t_tag, MUX_REQUEST_SEND_CAMCMD, SEC_REQUEST_SEND_CAMCMD, DATA_TYP_REQUEST_SEND_CAMCMD);
#else
    tag_write(&t_tag, MUX_REQUEST_SEND_CAMCMD, SEC_REQUEST_SEND_CAMCMD, DATA_TYP_REQUEST_SEND_CAMCMD);
#endif /* __LEGACY_XDCOMMS__ */
#ifndef __LEGACY_XDCOMMS__
    my_tag_write(&o_tag, MUX_RESPONSE_SEND_CAMCMD, SEC_RESPONSE_SEND_CAMCMD, DATA_TYP_RESPONSE_SEND_CAMCMD);
#else
    tag_write(&o_tag, MUX_RESPONSE_SEND_CAMCMD, SEC_RESPONSE_SEND_CAMCMD, DATA_TYP_RESPONSE_SEND_CAMCMD);
#endif /* __LEGACY_XDCOMMS__ */
    static int res_counter = 0;
    static int last_processed_result = 0;
    static int last_processed_error = 0;
    static int inited = 0;
#ifndef __LEGACY_XDCOMMS__
    void *psocket;
    void *ssocket;
#else
    static void *psocket;
    static void *ssocket;
#endif /* __LEGACY_XDCOMMS__ */
    #pragma cle begin TAG_REQUEST_SEND_CAMCMD
    request_send_camcmd_datatype request_send_camcmd;
    #pragma cle end TAG_REQUEST_SEND_CAMCMD
    #pragma cle begin TAG_RESPONSE_SEND_CAMCMD
    response_send_camcmd_datatype response_send_camcmd;
    #pragma cle end TAG_RESPONSE_SEND_CAMCMD
#ifndef __LEGACY_XDCOMMS__
    codec_map  mycmap[DATA_TYP_MAX];
    for (int i=0; i < DATA_TYP_MAX; i++)  mycmap[i].valid=0;
    my_xdc_register(request_get_frame_data_encode, request_get_frame_data_decode, DATA_TYP_REQUEST_GET_FRAME, mycmap);
    my_xdc_register(response_get_frame_data_encode, response_get_frame_data_decode, DATA_TYP_RESPONSE_GET_FRAME, mycmap);
    my_xdc_register(request_get_metadata_data_encode, request_get_metadata_data_decode, DATA_TYP_REQUEST_GET_METADATA, mycmap);
    my_xdc_register(response_get_metadata_data_encode, response_get_metadata_data_decode, DATA_TYP_RESPONSE_GET_METADATA, mycmap);
    my_xdc_register(request_run_videoproc_data_encode, request_run_videoproc_data_decode, DATA_TYP_REQUEST_RUN_VIDEOPROC, mycmap);
    my_xdc_register(response_run_videoproc_data_encode, response_run_videoproc_data_decode, DATA_TYP_RESPONSE_RUN_VIDEOPROC, mycmap);
    my_xdc_register(request_send_camcmd_data_encode, request_send_camcmd_data_decode, DATA_TYP_REQUEST_SEND_CAMCMD, mycmap);
    my_xdc_register(response_send_camcmd_data_encode, response_send_camcmd_data_decode, DATA_TYP_RESPONSE_SEND_CAMCMD, mycmap);
#endif /* __LEGACY_XDCOMMS__ */
#ifndef __LEGACY_XDCOMMS__
    void * ctx = zmq_ctx_new();
    psocket = my_xdc_pub_socket(ctx, (char *)OUTURI);
    ssocket = my_xdc_sub_socket(t_tag, ctx, (char*)INURI);
    sleep(1); /* zmq socket join delay */
#else
    if (!inited) {
        inited = 1;
        psocket = xdc_pub_socket();
        ssocket = xdc_sub_socket(t_tag);
        sleep(1); /* zmq socket join delay */
    }
#endif /* __LEGACY_XDCOMMS__ */
#ifndef __LEGACY_XDCOMMS__
    int proc_error = 1;
    while (proc_error == 1) {
        my_xdc_blocking_recv(ssocket, &request_send_camcmd, &t_tag, mycmap);
        int req_counter = request_send_camcmd.trailer.seq;
        if(req_counter > res_counter){
            proc_error = 0;
            res_counter = req_counter;
            last_processed_result = send_camcmd(request_send_camcmd.pan, request_send_camcmd.tilt, request_send_camcmd.imptime, request_send_camcmd.mode, request_send_camcmd.stab);
            response_send_camcmd.ret = last_processed_result;
            last_processed_error = proc_error;
        }
#ifndef __ONEWAY_RPC__
        response_send_camcmd.trailer.seq = res_counter << 2 | last_processed_error << 1;
        my_xdc_asyn_send(psocket, &response_send_camcmd, &o_tag, mycmap);
#else /* __ONEWAY_RPC__ */
        res_counter = req_counter;
#endif /* __ONEWAY_RPC__ */
    }
    zmq_close(psocket);
    zmq_close(ssocket);
    zmq_ctx_shutdown(ctx);
#else
    int proc_error = 1;
    while (proc_error == 1) {
        xdc_blocking_recv(ssocket, &request_send_camcmd, &t_tag);
        int req_counter = request_send_camcmd.trailer.seq;
        if(req_counter > res_counter){
            proc_error = 0;
            res_counter = req_counter;
            last_processed_result = send_camcmd(request_send_camcmd.pan, request_send_camcmd.tilt, request_send_camcmd.imptime, request_send_camcmd.mode, request_send_camcmd.stab);
            response_send_camcmd.ret = last_processed_result;
            last_processed_error = proc_error;
        }
#ifndef __ONEWAY_RPC__
        response_send_camcmd.trailer.seq = res_counter << 2 | last_processed_error << 1;
        xdc_asyn_send(psocket, &response_send_camcmd, &o_tag);
#else /* __ONEWAY_RPC__ */
        res_counter = req_counter;
#endif /* __ONEWAY_RPC__ */
    }
#endif /* __LEGACY_XDCOMMS__ */
}

WRAP(request_get_frame)
WRAP(request_get_metadata)
WRAP(request_run_videoproc)
WRAP(request_send_camcmd)
#define NXDRPC 4

int _slave_rpc_loop() {
    _hal_init((char *)INURI, (char *)OUTURI);
    pthread_t tid[NXDRPC];
    pthread_create(&tid[0], NULL, _wrapper_request_get_frame, NULL);
    pthread_create(&tid[1], NULL, _wrapper_request_get_metadata, NULL);
    pthread_create(&tid[2], NULL, _wrapper_request_run_videoproc, NULL);
    pthread_create(&tid[3], NULL, _wrapper_request_send_camcmd, NULL);
    for (int i = 0; i < NXDRPC; i++) pthread_join(tid[i], NULL);
    return 0;
}

