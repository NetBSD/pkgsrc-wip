#!/bin/sh
#
#	$NetBSD: smartd.sh,v 1.1 2004/05/10 23:25:35 shattered Exp $
#
# PROVIDE: smartd
# REQUIRE: DAEMON

. /etc/rc.subr

name="smartd"                      
rcvar=$name         
command="/usr/pkg/sbin/${name}"
pidfile="/var/run/${name}.pid"
smartd_flags="-p $pidfile"
              
load_rc_config $name
run_rc_command "$1"
