#!/bin/sh
#
# ripd is part of the quagga routing beast
#
# PROVIDE: ripd
# REQUIRE: zebra
##

PATH=/sbin:/bin:/usr/sbin:/usr/bin:/usr/pkg/sbin:/usr/pkg/bin
export PATH

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="staticd"
rcvar=$name
required_files="/usr/pkg/etc/frr/${name}.conf"
command="/usr/pkg/sbin/${name}"
command_args="-d"

socket_dir=/var/run/frr
pidfile="${socket_dir}/${name}.pid"

load_rc_config $name
run_rc_command "$1"
