# GAPS demo application

This is a demonstration application to showcase some features of the CLOSURE and MIND toolchains. The application processes video from a gimbal mounted Trillium camera, transcodes it (using FFMPEG libraries) and serves it to a browser (currently Firefox) using a webserver (based on Mongoose) to a browser. Position metadata from the camera and commands to the camera (based on the Orion SDK) from the browser are also proessed. The functionality is split into the video processing running on the A53 on the ZCU102 FPGA board and the webserver on a MicroBlaze softcore processor on the FPGA.

## For building and testing the application on hardware

First install Xilinx Petalinux tools 2021.1. In my case, it is under `~/gaps/misc/xilinx`.

```bash
cd ~/gaps
git clone git@github.com:gaps-closure/eop2-closure-mind-demo.git
git checkout main

cd ~/gaps/misc/xilinx/demo-images
source ../settings.sh 

petalinux-create -t project -s ~/gaps/eop2-closure-mind-demo/bsp/zcu102_peraton_a53_20220823.bsp -n a53
petalinux-create -t project -s ~/gaps/eop2-closure-mind-demo/bsp/zcu102_peraton_mb_20220823.bsp -n mb

cd a53
petalinux-build
petalinux-boot --qemu --kernel

cd ../mb
petalinux-build
petalinux-boot --qemu --kernel images/linux/linux.bin.ub

# gets copied to /srv/tftp/a53 and /srv/tftp/mb for reflashing ZCU102+ and booting A53 and MB

# Commands for generating BSP if you modify the projects
cd ../a53
petalinux-package --bsp --clean -p . --output ~/gaps/eop2-closure-mind-demo/bsp/zcu102_peraton_a53_20220823.bsp
cd ../mb
petalinux-package --bsp --clean -p . --output ~/gaps/eop2-closure-mind-demo/bsp/zcu102_peraton_mb_20220823.bsp
```

Now, get the ZCU102 to ZyncMP/U-Boot prompts, and reflash the hardware:

```
# A53 boot image via tftp from 10.109.23.126:/srv/tftp/a53 
setenv ipaddr 10.109.23.246
setenv serverip 10.109.23.126
sf probe 0 0 0
sf erase 0x1E40000 0x6040000
tftpboot 0x10000000 a53/image.ub
sf write 0x10000000 0x1E40000 0x6040000
reset

# MB boot image via tftp from 10.109.23.126:/srv/tftp/mb
setenv ipaddr 10.109.23.248
setenv serverip 10.109.23.126
sf probe 0 0 0
sf erase 0x100000 0x1E00000
tftpboot 0x90000000 mb/image.ub
sf write 0x90000000 0x100000 0x1E00000
reset
```

These instructions are for images created on jaga (10.109.23.126). 
The instructions for liono (10.109.23.128) are in [demo_notes_1_setup.txt](./demo_notes_1_setup.txt)
and are stored on the demo machine in /home/closure/Desktop/

Log into the A53 and MB and test as follows:

```
#######################################
# Test unpartitioned application on A53
#######################################
# Configure Trillium camera with static IP and also to send video to a53's IP address using Skylink
# Point firefox to p://<a53-addr>:8443

cd /opt/closure/websrv
MYADDR=<a53-addr> CAMADDR=<trillium-addr> ./websrv
```

### Test partitioned application on both A53 and MB

As with Unpartitioned case, configure Trillium camera with static IP 
and also to send video to a53's IP address using Skylink
Point firefox to http://<mb-addr>:8443 --  now web server runs on MB
Then use the instructions in:

[demo_notes_2_run_apps.txt](./demo_notes_2_run_apps.txt)

You can optionally specify XDCLOGLEVEL to 2 for QUIET and 0 for TRACE level verbose logs (kills performance). 

## Steps for local testing of partitioned code with pseudo driver on x86/Linux

```bash
# Get development libraries once
sudo apt build-essential linux-headers-`uname -r`
sudo apt install cmake software-properties-common
sudo apt install libmbedtls-dev
sudo apt install zlib1g-dev liblzma-dev libbz2-dev 
sudo apt install libavformat-dev libavcodec-dev libavutil-dev libavfilter-dev 
sudo apt install libavdevice-dev libpostproc-dev libswscale-dev libswresample-dev

# Check out xdcomms-dma 
cd ~/gaps
git clone git@github.com:gaps-closure/xdcomms-dma.git
git checkout rk

# Check out websrv application
git clone git@github.com:gaps-closure/eop2-closure-mind-demo.git
git checkout main

# Build xdcomms-dma dynamic library -- fix code, redo as needed
cd ~/gaps/xdcomms-dma/api
make -f Makefile.pseudo

# Build the green executable 
cd ~/gaps/eop2-closure-mind-demo/websrv/.solution/partitioned/multithreaded/green/
make -f ../../../makefiles/Makefile.pseudo 

# Build the orange executable 
cd ~/gaps/eop2-closure-mind-demo/websrv/.solution/partitioned/multithreaded/green/
cd ~/gaps/eop2-closure-mind-demo/websrv/.solution/partitioned/multithreaded/orange/
make -f ../../../makefiles/Makefile.pseudo 

# Optionally build and test the driver once with dma-proxy-test
# This cleans, builds, loads, tests, unloads, cleans again
cd ~/gaps/xdcomms-dma/test
./run.sh

# Build and load the pseudo driver for use with websrv/xdcomms_dma testing
cd ~/gaps/xdcomms-dma/pseudo
make clean; make
sudo ./sue_donimous_load
lsmod | grep sue_donimous
ls /dev/sue_donim*
dmesg

# In one window run the orange application
cd ~/gaps/eop2-closure-mind-demo/websrv/.solution/partitioned/multithreaded/orange/
XDCLOGLEVEL=1 LD_LIBRARY_PATH=~/gaps/xdcomms-dma/api DMARXDEV=sue_donimous_rx0 DMATXDEV=sue_donimous_tx0 MYADDR=10.50.0.1 CAMADDR=10.50.0.2 ./websrv

# In one window run the green application
# In another window, use correct addresses 
cd ~/gaps/eop2-closure-mind-demo/websrv/.solution/partitioned/multithreaded/green/
XDCLOGLEVEL=1 LD_LIBRARY_PATH=~/gaps/xdcomms-dma/api DMARXDEV=sue_donimous_rx1 DMATXDEV=sue_donimous_tx1 ./websrv

# Unload the driver
cd ~/gaps/xdcomms-dma/pseudo
sudo ./sue_donimous_unload
lsmod | grep sue_donimous
ls /dev/sue_donim*
dmesg

```

## For cross-domain application development using the CLOSURE toolchain

The following development tools and libraries are required.
 * GNU gcc toolchain with libm and lpthread
 * libz, liblzma, llibbz2
 * mbedtls
 * ffmpeg
 * ProtoGen, if using an architecture other than what orion-sdk includes binaries for
   and you are generating the C from the XML protogen spec (no longer needed)
 * Ubuntu 20.04 Linux/x86 system with VSCode and Docker installed.

The prerequisties se can be installed using:
```
sudo apt install build-essential
sudo apt install libmbedtls-dev
sudo apt install zlib1g-dev liblzma-dev libbz2-dev
sudo apt install libavformat-dev libavcodec-dev libavutil-dev libavfilter-dev libavdevice-dev libpostproc-dev 
sudo apt install libswscale-dev libswresample-dev 
sudo apt install qt5-qmake     # orion-sdk build needs this, but our build no longer needs this
```

Additionally, we require mongoose and orion-sdk, which are now included in the sources.
To build the unpartitioned application:

```
cd websrv/plain
make
```

There is an annotated, refactored, and partitioned solution checked in the `.solution` directory, but for the process of using the CLOSURE toolchain, see the [documentation](https://gaps-closure.github.io/)


