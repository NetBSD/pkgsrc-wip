#!/bin/sh
#
# PROVIDE: actived
# REQUIRE: DAEMON
#
# News active file caching daemon for nnrpd
#

. /etc/rc.subr

name="actived"
rcvar=$name
command="/usr/pkg/sbin/actived"
pidfile="/var/news/run/${name}.pid"

start_cmd="actived_start"

actived_start()
{
	if [ -x $command ]; then
		echo 'Starting actived.'
		$command
	fi
}

load_rc_config $name
run_rc_command "$1"
