#include "green_rpc.h"
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

#pragma cle begin RPC_GET_FRAME
#pragma clang attribute push (__attribute__((annotate("RPC_GET_FRAME"))), apply_to = any(function,type_alias,record,enum,variable(unless(is_parameter)),field))
int _rpc_get_frame(char buf[], int *error) {
#pragma clang attribute pop
#pragma cle end RPC_GET_FRAME
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
    static int req_counter = INT_MIN;
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
    int result;
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
    ssocket = my_xdc_sub_socket_non_blocking(o_tag, ctx, 1000, (char*)INURI);
    sleep(1); /* zmq socket join delay */
#else
    if (!inited) {
        inited = 1;
        psocket = xdc_pub_socket();
        ssocket = xdc_sub_socket_non_blocking(o_tag, 150);
        sleep(1); /* zmq socket join delay */
    }
#endif /* __LEGACY_XDCOMMS__ */
    request_get_frame.trailer.seq = req_counter;
#ifndef __LEGACY_XDCOMMS__
    if (req_counter == INT_MIN) {
        int tries_remaining = 5;
        while(tries_remaining != 0){
            my_xdc_asyn_send(psocket, &request_get_frame, &t_tag , mycmap);
#ifndef __ONEWAY_RPC__
            *error = my_xdc_recv(ssocket, &response_get_frame, &o_tag , mycmap);
            if (*error == -1){
                tries_remaining--;
                continue;
            }
#else
            *error = 0;
#endif /* __ONEWAY_RPC__ */
            break;  /* Reach here if received a response or __ONEWAY_RPC__ */
        }
#ifndef __ONEWAY_RPC__
        if (*error >= 0) req_counter = 1 + (response_get_frame.trailer.seq >> 2);
#else
        req_counter++;
#endif /* __ONEWAY_RPC__ */
    }
#else /* __LEGACY_XDCOMMS__ */
    if (req_counter == INT_MIN) {
        int tries_remaining = 1;
        while(tries_remaining != 0){
            xdc_asyn_send(psocket, &request_get_frame, &t_tag);
#ifndef __ONEWAY_RPC__
            *error = xdc_recv(ssocket, &response_get_frame, &o_tag);
            if (*error == -1){
                tries_remaining--;
                continue;
            }
#else
            *error = 0;
#endif /* __ONEWAY_RPC__ */
            break;  /* Reach here if received a response or __ONEWAY_RPC__ */
        }
#ifndef __ONEWAY_RPC__
        if (*error >= 0) req_counter = 1 + (response_get_frame.trailer.seq >> 2);
#else
        req_counter++;
#endif /* __ONEWAY_RPC__ */
    }
#endif /* __LEGACY_XDCOMMS__ */
    request_get_frame.trailer.seq = req_counter;
#ifndef __LEGACY_XDCOMMS__
    int tries_remaining = 5;
    while(tries_remaining != 0){
        my_xdc_asyn_send(psocket, &request_get_frame, &t_tag , mycmap);
#ifndef __ONEWAY_RPC__
        *error = my_xdc_recv(ssocket, &response_get_frame, &o_tag , mycmap);
        if (*error == -1){
            tries_remaining--;
            continue;
        }
#else
        *error = 0;
#endif /* __ONEWAY_RPC__ */
        break;  /* Reach here if received a response or __ONEWAY_RPC__ */
    }
    zmq_close(psocket);
    zmq_close(ssocket);
    zmq_ctx_shutdown(ctx);
#else /* __LEGACY_XDCOMMS__ */
    int tries_remaining = 1;
    while(tries_remaining != 0){
        xdc_asyn_send(psocket, &request_get_frame, &t_tag);
#ifndef __ONEWAY_RPC__
        *error = xdc_recv(ssocket, &response_get_frame, &o_tag);
        if (*error == -1){
            tries_remaining--;
            continue;
        }
#else
        *error = 0;
#endif /* __ONEWAY_RPC__ */
        break;  /* Reach here if received a response or __ONEWAY_RPC__ */
    }
#endif /* __LEGACY_XDCOMMS__ */
    req_counter++;
#ifndef __ONEWAY_RPC__
    for(int i=0; i<64000; i++) buf[i] = response_get_frame.buf[i];
    result = response_get_frame.ret;
    return (result);
#else
    return 0;
#endif /* __ONEWAY_RPC__ */
}

#pragma cle begin ERR_HANDLE_RPC_GET_FRAME
#pragma clang attribute push (__attribute__((annotate("ERR_HANDLE_RPC_GET_FRAME"))), apply_to = any(function,type_alias,record,enum,variable(unless(is_parameter)),field))
int _err_handle_rpc_get_frame(char buf[]){
#pragma clang attribute pop
#pragma cle end ERR_HANDLE_RPC_GET_FRAME
	int err_num;
	int res = _rpc_get_frame(buf, &err_num);
	// err handling code goes here
	return res;
}
#pragma cle begin RPC_GET_METADATA
#pragma clang attribute push (__attribute__((annotate("RPC_GET_METADATA"))), apply_to = any(function,type_alias,record,enum,variable(unless(is_parameter)),field))
int _rpc_get_metadata(double lat[],double lon[],double alt[],double ts[], int *error) {
#pragma clang attribute pop
#pragma cle end RPC_GET_METADATA
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
    static int req_counter = INT_MIN;
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
    int result;
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
    ssocket = my_xdc_sub_socket_non_blocking(o_tag, ctx, 1000, (char*)INURI);
    sleep(1); /* zmq socket join delay */
#else
    if (!inited) {
        inited = 1;
        psocket = xdc_pub_socket();
        ssocket = xdc_sub_socket_non_blocking(o_tag, 150);
        sleep(1); /* zmq socket join delay */
    }
#endif /* __LEGACY_XDCOMMS__ */
    request_get_metadata.trailer.seq = req_counter;
#ifndef __LEGACY_XDCOMMS__
    if (req_counter == INT_MIN) {
        int tries_remaining = 5;
        while(tries_remaining != 0){
            my_xdc_asyn_send(psocket, &request_get_metadata, &t_tag , mycmap);
#ifndef __ONEWAY_RPC__
            *error = my_xdc_recv(ssocket, &response_get_metadata, &o_tag , mycmap);
            if (*error == -1){
                tries_remaining--;
                continue;
            }
#else
            *error = 0;
#endif /* __ONEWAY_RPC__ */
            break;  /* Reach here if received a response or __ONEWAY_RPC__ */
        }
#ifndef __ONEWAY_RPC__
        if (*error >= 0) req_counter = 1 + (response_get_metadata.trailer.seq >> 2);
#else
        req_counter++;
#endif /* __ONEWAY_RPC__ */
    }
#else /* __LEGACY_XDCOMMS__ */
    if (req_counter == INT_MIN) {
        int tries_remaining = 1;
        while(tries_remaining != 0){
            xdc_asyn_send(psocket, &request_get_metadata, &t_tag);
#ifndef __ONEWAY_RPC__
            *error = xdc_recv(ssocket, &response_get_metadata, &o_tag);
            if (*error == -1){
                tries_remaining--;
                continue;
            }
#else
            *error = 0;
#endif /* __ONEWAY_RPC__ */
            break;  /* Reach here if received a response or __ONEWAY_RPC__ */
        }
#ifndef __ONEWAY_RPC__
        if (*error >= 0) req_counter = 1 + (response_get_metadata.trailer.seq >> 2);
#else
        req_counter++;
#endif /* __ONEWAY_RPC__ */
    }
#endif /* __LEGACY_XDCOMMS__ */
    request_get_metadata.trailer.seq = req_counter;
#ifndef __LEGACY_XDCOMMS__
    int tries_remaining = 5;
    while(tries_remaining != 0){
        my_xdc_asyn_send(psocket, &request_get_metadata, &t_tag , mycmap);
#ifndef __ONEWAY_RPC__
        *error = my_xdc_recv(ssocket, &response_get_metadata, &o_tag , mycmap);
        if (*error == -1){
            tries_remaining--;
            continue;
        }
#else
        *error = 0;
#endif /* __ONEWAY_RPC__ */
        break;  /* Reach here if received a response or __ONEWAY_RPC__ */
    }
    zmq_close(psocket);
    zmq_close(ssocket);
    zmq_ctx_shutdown(ctx);
#else /* __LEGACY_XDCOMMS__ */
    int tries_remaining = 1;
    while(tries_remaining != 0){
        xdc_asyn_send(psocket, &request_get_metadata, &t_tag);
#ifndef __ONEWAY_RPC__
        *error = xdc_recv(ssocket, &response_get_metadata, &o_tag);
        if (*error == -1){
            tries_remaining--;
            continue;
        }
#else
        *error = 0;
#endif /* __ONEWAY_RPC__ */
        break;  /* Reach here if received a response or __ONEWAY_RPC__ */
    }
#endif /* __LEGACY_XDCOMMS__ */
    req_counter++;
#ifndef __ONEWAY_RPC__
    for(int i=0; i<1; i++) lat[i] = response_get_metadata.lat[i];
    for(int i=0; i<1; i++) lon[i] = response_get_metadata.lon[i];
    for(int i=0; i<1; i++) alt[i] = response_get_metadata.alt[i];
    for(int i=0; i<1; i++) ts[i] = response_get_metadata.ts[i];
    result = response_get_metadata.ret;
    return (result);
#else
    return 0;
#endif /* __ONEWAY_RPC__ */
}

#pragma cle begin ERR_HANDLE_RPC_GET_METADATA
#pragma clang attribute push (__attribute__((annotate("ERR_HANDLE_RPC_GET_METADATA"))), apply_to = any(function,type_alias,record,enum,variable(unless(is_parameter)),field))
int _err_handle_rpc_get_metadata(double lat[], double lon[], double alt[], double ts[]){
#pragma clang attribute pop
#pragma cle end ERR_HANDLE_RPC_GET_METADATA
	int err_num;
	int res = _rpc_get_metadata(lat, lon, alt, ts, &err_num);
	// err handling code goes here
	return res;
}
#pragma cle begin RPC_RUN_VIDEOPROC
#pragma clang attribute push (__attribute__((annotate("RPC_RUN_VIDEOPROC"))), apply_to = any(function,type_alias,record,enum,variable(unless(is_parameter)),field))
int _rpc_run_videoproc(int *error) {
#pragma clang attribute pop
#pragma cle end RPC_RUN_VIDEOPROC
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
    static int req_counter = INT_MIN;
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
    int result;
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
    ssocket = my_xdc_sub_socket_non_blocking(o_tag, ctx, 1000, (char*)INURI);
    sleep(1); /* zmq socket join delay */
#else
    if (!inited) {
        inited = 1;
        psocket = xdc_pub_socket();
        ssocket = xdc_sub_socket_non_blocking(o_tag, 1000);
        sleep(1); /* zmq socket join delay */
    }
#endif /* __LEGACY_XDCOMMS__ */
    request_run_videoproc.dummy = 0;
    request_run_videoproc.trailer.seq = req_counter;
#ifndef __LEGACY_XDCOMMS__
    if (req_counter == INT_MIN) {
        int tries_remaining = 5;
        while(tries_remaining != 0){
            my_xdc_asyn_send(psocket, &request_run_videoproc, &t_tag , mycmap);
#ifndef __ONEWAY_RPC__
            *error = my_xdc_recv(ssocket, &response_run_videoproc, &o_tag , mycmap);
            if (*error == -1){
                tries_remaining--;
                continue;
            }
#else
            *error = 0;
#endif /* __ONEWAY_RPC__ */
            break;  /* Reach here if received a response or __ONEWAY_RPC__ */
        }
#ifndef __ONEWAY_RPC__
        if (*error >= 0) req_counter = 1 + (response_run_videoproc.trailer.seq >> 2);
#else
        req_counter++;
#endif /* __ONEWAY_RPC__ */
    }
#else /* __LEGACY_XDCOMMS__ */
    if (req_counter == INT_MIN) {
        int tries_remaining = 1;
        while(tries_remaining != 0){
            xdc_asyn_send(psocket, &request_run_videoproc, &t_tag);
#ifndef __ONEWAY_RPC__
            *error = xdc_recv(ssocket, &response_run_videoproc, &o_tag);
            if (*error == -1){
                tries_remaining--;
                continue;
            }
#else
            *error = 0;
#endif /* __ONEWAY_RPC__ */
            break;  /* Reach here if received a response or __ONEWAY_RPC__ */
        }
#ifndef __ONEWAY_RPC__
        if (*error >= 0) req_counter = 1 + (response_run_videoproc.trailer.seq >> 2);
#else
        req_counter++;
#endif /* __ONEWAY_RPC__ */
    }
#endif /* __LEGACY_XDCOMMS__ */
    request_run_videoproc.dummy = 0;
    request_run_videoproc.trailer.seq = req_counter;
#ifndef __LEGACY_XDCOMMS__
    int tries_remaining = 5;
    while(tries_remaining != 0){
        my_xdc_asyn_send(psocket, &request_run_videoproc, &t_tag , mycmap);
#ifndef __ONEWAY_RPC__
        *error = my_xdc_recv(ssocket, &response_run_videoproc, &o_tag , mycmap);
        if (*error == -1){
            tries_remaining--;
            continue;
        }
#else
        *error = 0;
#endif /* __ONEWAY_RPC__ */
        break;  /* Reach here if received a response or __ONEWAY_RPC__ */
    }
    zmq_close(psocket);
    zmq_close(ssocket);
    zmq_ctx_shutdown(ctx);
#else /* __LEGACY_XDCOMMS__ */
    int tries_remaining = 1;
    while(tries_remaining != 0){
        xdc_asyn_send(psocket, &request_run_videoproc, &t_tag);
#ifndef __ONEWAY_RPC__
        *error = xdc_recv(ssocket, &response_run_videoproc, &o_tag);
        if (*error == -1){
            tries_remaining--;
            continue;
        }
#else
        *error = 0;
#endif /* __ONEWAY_RPC__ */
        break;  /* Reach here if received a response or __ONEWAY_RPC__ */
    }
#endif /* __LEGACY_XDCOMMS__ */
    req_counter++;
#ifndef __ONEWAY_RPC__
    result = response_run_videoproc.ret;
    return (result);
#else
    return 0;
#endif /* __ONEWAY_RPC__ */
}

#pragma cle begin ERR_HANDLE_RPC_RUN_VIDEOPROC
#pragma clang attribute push (__attribute__((annotate("ERR_HANDLE_RPC_RUN_VIDEOPROC"))), apply_to = any(function,type_alias,record,enum,variable(unless(is_parameter)),field))
int _err_handle_rpc_run_videoproc(){
#pragma clang attribute pop
#pragma cle end ERR_HANDLE_RPC_RUN_VIDEOPROC
	int err_num;
	int res = _rpc_run_videoproc(&err_num);
	// err handling code goes here
	return res;
}
#pragma cle begin RPC_SEND_CAMCMD
#pragma clang attribute push (__attribute__((annotate("RPC_SEND_CAMCMD"))), apply_to = any(function,type_alias,record,enum,variable(unless(is_parameter)),field))
int _rpc_send_camcmd(double pan,double tilt,double imptime,char mode,char stab, int *error) {
#pragma clang attribute pop
#pragma cle end RPC_SEND_CAMCMD
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
    static int req_counter = INT_MIN;
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
    int result;
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
    ssocket = my_xdc_sub_socket_non_blocking(o_tag, ctx, 1000, (char*)INURI);
    sleep(1); /* zmq socket join delay */
#else
    if (!inited) {
        inited = 1;
        psocket = xdc_pub_socket();
        ssocket = xdc_sub_socket_non_blocking(o_tag, 1000);
        sleep(1); /* zmq socket join delay */
    }
#endif /* __LEGACY_XDCOMMS__ */
    request_send_camcmd.pan = 0;
    request_send_camcmd.tilt = 0;
    request_send_camcmd.imptime = 0;
    request_send_camcmd.mode = 0;
    request_send_camcmd.stab = 0;
    request_send_camcmd.trailer.seq = req_counter;
#ifndef __LEGACY_XDCOMMS__
    if (req_counter == INT_MIN) {
        int tries_remaining = 5;
        while(tries_remaining != 0){
            my_xdc_asyn_send(psocket, &request_send_camcmd, &t_tag , mycmap);
#ifndef __ONEWAY_RPC__
            *error = my_xdc_recv(ssocket, &response_send_camcmd, &o_tag , mycmap);
            if (*error == -1){
                tries_remaining--;
                continue;
            }
#else
            *error = 0;
#endif /* __ONEWAY_RPC__ */
            break;  /* Reach here if received a response or __ONEWAY_RPC__ */
        }
#ifndef __ONEWAY_RPC__
        if (*error >= 0) req_counter = 1 + (response_send_camcmd.trailer.seq >> 2);
#else
        req_counter++;
#endif /* __ONEWAY_RPC__ */
    }
#else /* __LEGACY_XDCOMMS__ */
    if (req_counter == INT_MIN) {
        int tries_remaining = 1;
        while(tries_remaining != 0){
            xdc_asyn_send(psocket, &request_send_camcmd, &t_tag);
#ifndef __ONEWAY_RPC__
            *error = xdc_recv(ssocket, &response_send_camcmd, &o_tag);
            if (*error == -1){
                tries_remaining--;
                continue;
            }
#else
            *error = 0;
#endif /* __ONEWAY_RPC__ */
            break;  /* Reach here if received a response or __ONEWAY_RPC__ */
        }
#ifndef __ONEWAY_RPC__
        if (*error >= 0) req_counter = 1 + (response_send_camcmd.trailer.seq >> 2);
#else
        req_counter++;
#endif /* __ONEWAY_RPC__ */
    }
#endif /* __LEGACY_XDCOMMS__ */
    request_send_camcmd.pan = pan;
    request_send_camcmd.tilt = tilt;
    request_send_camcmd.imptime = imptime;
    request_send_camcmd.mode = mode;
    request_send_camcmd.stab = stab;
    request_send_camcmd.trailer.seq = req_counter;
#ifndef __LEGACY_XDCOMMS__
    int tries_remaining = 5;
    while(tries_remaining != 0){
        my_xdc_asyn_send(psocket, &request_send_camcmd, &t_tag , mycmap);
#ifndef __ONEWAY_RPC__
        *error = my_xdc_recv(ssocket, &response_send_camcmd, &o_tag , mycmap);
        if (*error == -1){
            tries_remaining--;
            continue;
        }
#else
        *error = 0;
#endif /* __ONEWAY_RPC__ */
        break;  /* Reach here if received a response or __ONEWAY_RPC__ */
    }
    zmq_close(psocket);
    zmq_close(ssocket);
    zmq_ctx_shutdown(ctx);
#else /* __LEGACY_XDCOMMS__ */
    int tries_remaining = 1;
    while(tries_remaining != 0){
        xdc_asyn_send(psocket, &request_send_camcmd, &t_tag);
#ifndef __ONEWAY_RPC__
        *error = xdc_recv(ssocket, &response_send_camcmd, &o_tag);
        if (*error == -1){
            tries_remaining--;
            continue;
        }
#else
        *error = 0;
#endif /* __ONEWAY_RPC__ */
        break;  /* Reach here if received a response or __ONEWAY_RPC__ */
    }
#endif /* __LEGACY_XDCOMMS__ */
    req_counter++;
#ifndef __ONEWAY_RPC__
    result = response_send_camcmd.ret;
    return (result);
#else
    return 0;
#endif /* __ONEWAY_RPC__ */
}

#pragma cle begin ERR_HANDLE_RPC_SEND_CAMCMD
#pragma clang attribute push (__attribute__((annotate("ERR_HANDLE_RPC_SEND_CAMCMD"))), apply_to = any(function,type_alias,record,enum,variable(unless(is_parameter)),field))
int _err_handle_rpc_send_camcmd(double pan, double tilt, double imptime, char mode, char stab){
#pragma clang attribute pop
#pragma cle end ERR_HANDLE_RPC_SEND_CAMCMD
	int err_num;
	int res = _rpc_send_camcmd(pan, tilt, imptime, mode, stab, &err_num);
	// err handling code goes here
	return res;
}
void _master_rpc_init() {
    _hal_init((char*)INURI, (char *)OUTURI);
}

