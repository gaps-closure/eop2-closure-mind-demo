# Demonstration application for ZCU102 with Trillium camera

## Prerequisites

The following development tools and libraries are required.
 * GNU gcc toolchain with libm and lpthread
 * libz, liblzma, llibbz2
 * mbedtls
 * ffmpeg
 * ProtoGen, if using an architecture other than what orion-sdk includes binaries for
   and you are generating the C from the XML protogen spec (no longer needed)

The prerequisties se can be installed using:
```
sudo apt install build-essential
sudo apt install libmbedtls-dev
sudo apt install zlib1g-dev liblzma-dev libbz2-dev
sudo apt install libavformat-dev libavcodec-dev libavutil-dev libavfilter-dev libavdevice-dev libpostproc-dev 
sudo apt install libswscale-dev libswresample-dev 
sudo apt install qt5-qmake     # orion-sdk build needs this, but no longer need
```

Additionally, we require mongoose and orion-sdk, which are included in the sources.

# Building

```
cd orion-sdk
make
cd ../demoapp/plain
make
```
