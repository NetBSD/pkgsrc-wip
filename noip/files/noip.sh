#!/bin/sh
#
# PROVIDE: noip
# REQUIRE: network

name="noip"
command="/usr/pkg/bin/${name}"
required_files="/usr/pkg/etc/no-ip.conf"

. /etc/rc.subr

load_rc_config $name
run_rc_command "$1"
