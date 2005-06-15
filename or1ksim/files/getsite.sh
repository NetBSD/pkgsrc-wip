#!/bin/sh


if ! test -f $1; then
	wget  -O $1 "http://www.opencores.org/cvsget.cgi/or1k/or1ksim?tag=stable_0_1_x&do_download=now"
fi
