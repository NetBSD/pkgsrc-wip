#!/bin/sh

id=$1
type=$2
cmajor=$3
bmajor=$4

if [ $cmajor != -1 ]
then
	rm -f /dev/kqemu
	mknod -u 0 -g 0 -m 660 /dev/kqemu c $cmajor 0
fi
