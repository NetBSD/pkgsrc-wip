#!/bin/sh
#
# PROVIDE: noip2
# REQUIRE: network

name="noip2"
command="/usr/pkg/bin/${name}"
required_files="/usr/pkg/etc/no-ip2.conf"

. /etc/rc.subr

load_rc_config $name
run_rc_command "$1"
