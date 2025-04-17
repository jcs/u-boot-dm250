#!/bin/sh

set -e

if [ ! `id -u` = "0" ]; then
	echo "run me as root"
	exit 1
fi

# in case it's in usbplug mode already
xrock reset maskrom >/dev/null || true
sleep 1

xrock maskrom rk3128_ddr_300MHz_v2.12.bin rk3128_usbplug_v2.63.bin
# wait for ugen to reattach
sleep 3

xrock flash write 16384 uboot.img
xrock reset
