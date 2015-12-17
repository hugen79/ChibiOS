#! /bin/sh
DFU_UTIL=dfu-util
$DFU_UTIL -d 0483:df11 -a 0 -s 0x08003000:leave -D build/ch.bin
