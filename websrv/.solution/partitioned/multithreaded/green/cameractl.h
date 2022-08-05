#ifndef CAMERACTL_H
#define CAMERACTL_H

#include <stdint.h>
#include <pthread.h>

#define MAX_FRAME_BUF   64000

struct llat_st {
  pthread_mutex_t flk;
  double          lat;
  double          lon;
  double          alt;
  double          ts;
  char            newf;
};

struct framebuf_st {
  pthread_mutex_t flk;
  char            newf;
  size_t          size;
  char            data[MAX_FRAME_BUF];
};


#endif // CAMERACTL_H

