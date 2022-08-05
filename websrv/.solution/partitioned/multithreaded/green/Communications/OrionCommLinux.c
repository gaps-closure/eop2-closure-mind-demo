#include "OrionComm.h"

#if defined(__linux__) || defined(__APPLE__)

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <termios.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>











// Quickly and easily constructs a sockaddr pointer for a bunch of different functions.
//   Call this function with Address == Port == 0 to access the pointer, or pass in
//   actual values to construct a new sockaddr.
#endif // __linux__
