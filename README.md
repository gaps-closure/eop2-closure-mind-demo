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

## Steps for local testing of partitioned code with pseudo driver on x86/Linux

```bash
sudo apt build-essential linux-headers-`uname -r`
sudo apt install cmake software-properties-common
sudo apt install libmbedtls-dev
sudo apt install zlib1g-dev liblzma-dev libbz2-dev 
sudo apt install libavformat-dev libavcodec-dev libavutil-dev libavfilter-dev 
sudo apt install libavdevice-dev libpostproc-dev libswscale-dev libswresample-dev

cd ~/gaps
git clone git@github.com:gaps-closure/xdcomms-dma.git
git checkout rk

git clone git@github.com:gaps-closure/eop2-closure-mind-demo.git
git checkout develop

cd ~/gaps/xdcomms-dma/api
make -f Makefile.pseudo

cd ~/gaps/eop2-closure-mind-demo/websrv/.solution/partitioned/multithreaded/green/
make -f ../../../makefiles/Makefile.pseudo 

cd ~/gaps/eop2-closure-mind-demo/websrv/.solution/partitioned/multithreaded/orange/
make -f ../../../makefiles/Makefile.pseudo 

cd ~/gaps/xdcomms-dma/pseudo
make clean; make
sudo ./sue_donimous_load

# In one window
cd ~/gaps/eop2-closure-mind-demo/websrv/.solution/partitioned/multithreaded/orange/
XDCLOGLEVEL=0 LD_LIBRARY_PATH=~/gaps/xdcomms-dma/api DMARXDEV=sue_donimous_rx0 DMATXDEV=sue_donimous_tx1 ./websrv

# In another window, use correct addresses 
cd ~/gaps/eop2-closure-mind-demo/websrv/.solution/partitioned/multithreaded/green/
XDCLOGLEVEL=0 LD_LIBRARY_PATH=~/gaps/xdcomms-dma/api DMARXDEV=sue_donimous_rx1 DMATXDEV=sue_donimous_tx0 MYADDR=10.50.0.1 CAMADDR=10.50.0.2 ./websrv
```
