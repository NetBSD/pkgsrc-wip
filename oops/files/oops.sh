#!/bin/sh
#
#	$NetBSD: oops.sh,v 1.1 2004/09/22 20:25:22 shattered Exp $
#
# PROVIDE: oops
# REQUIRE: DAEMON

. /etc/rc.subr

name="oops"                      
rcvar=$name         
command="@PREFIX@/sbin/${name}"
ctl_command="@PREFIX@/sbin/${name}ctl"
pidfile="/var/run/${name}/${name}.pid"
required_files="@PREFIX@/etc/oops/oops.cfg"
extra_commands="reload graceful"

export PTHREAD_DIAGASSERT=AEl 

start_cmd () {
	$ctl_command start
}

stop_cmd () {
	$ctl_command stop
}

reload_cmd () {
	$ctl_command reconfigure
}

graceful_cmd () {
	$ctl_command graceful
}
              
load_rc_config $name
run_rc_command "$1"
