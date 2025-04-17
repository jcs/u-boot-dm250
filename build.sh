#!/bin/sh

set -e

export CROSS_COMPILE=arm-none-eabi-

gmake kingjim_dm250_defconfig
gmake -j4
tools/loaderimage --pack --uboot u-boot.bin uboot.img 0x60000000
