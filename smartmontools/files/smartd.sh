#!/bin/sh
#
#	$NetBSD: smartd.sh,v 1.2 2004/06/28 15:45:05 shattered Exp $
#
# PROVIDE: smartd
# REQUIRE: DAEMON

. /etc/rc.subr

name="smartd"
rcvar=$name
command="/usr/pkg/sbin/${name}"
pidfile="/var/run/${name}.pid"
smartd_flags="-p $pidfile"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
