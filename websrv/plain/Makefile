PROG    ?= websrv
SRCS     = $(wildcard *.c)
CFLAGS   = -I ./Communications -I ./Utils -I ./mongoose \
           -Wno-unused-result -Wno-deprecated-declarations \
           -D_GNU_SOURCE -DMG_ENABLE_MBEDTLS=1 -DMG_ENABLE_MD5=1 -DMG_ENABLE_LINES=1 \
           -DORION_COMM_=1
LDFLAGS  = -L ./Communications -lOrionComm -L ./Utils -lOrionUtils \
           -lavformat -lavcodec -lavutil -lswscale -lswresample \
           -lmbedtls -lmbedcrypto -lmbedx509 \
           -lz -lpthread -lm
SLIBS    = Utils/libOrionUtils.a Communications/libOrionComm.a mongoose/libmongoose.a
COMSRCS  = $(wildcard Communications/*.c)
UTISRCS  = $(wildcard Utils/*.c)
MGSRCS   = $(wildcard mongoose/*.c)
COMOBJS := $(COMSRCS:%.c=%.o)
UTIOBJS := $(UTISRCS:%.c=%.o)
MGOBJS  := $(MGSRCS:%.c=%.o)

$(PROG): $(SRCS) $(SLIBS)
	$(CC) $(CFLAGS) -o $(PROG) $^ $(LDFLAGS) 

Utils/libOrionUtils.a: $(UTIOBJS)
	$(AR) -crs $@ $^
	rm -f $^

Communications/libOrionComm.a: $(COMOBJS)
	$(AR) -crs $@ $^
	rm -f $^

mongoose/libmongoose.a: $(MGOBJS)
	$(AR) -crs $@ $^
	rm -f $^

clean:
	rm -rf $(PROG) $(SLIBS) *.o */*.o 

