ifneq ($(VERBOSE), 1)
	V=@
endif

TARGET ?= x86

ifeq ($(TARGET), x86)
	CFLAGS+=-fPIC
else ifeq ($(TARGET), arm)
	PREFIX=arm-linux-gnueabi-
else ifeq ($(TARGET), arm64)
	PREFIX=aarch64-linux-gnu-
else ifeq ($(TARGET), tegra)
	PREFIX=aarch64-unknown-linux-gnu-
else ifeq ($(TARGET), arm64)
	PREFIX=aarch64-linux-gnu-
endif

CC?=$(PREFIX)gcc
AR?=$(PREFIX)ar
OBJ_DIR = $(TARGET)/obj

$(shell mkdir -p $(OBJ_DIR))
