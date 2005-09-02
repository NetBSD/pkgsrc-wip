#!/bin/sh
#
# $NetBSD: gnump3d.sh,v 1.2 2005/09/02 17:06:42 poppnk Exp $
#

# PROVIDE: gnump3d
# REQUIRE: DAEMON LOGIN network
# KEYWORD: shutdown

. /etc/rc.subr

name="gnump3d"
rcvar=$name
start_cmd="gnump3d_start"
stop_cmd="gnump3d_stop"
command="@PREFIX@/bin/${name}"
command_args="--quiet"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/gnump3d/gnump3d.conf"
current_pid=`cat $pidfile`

gnump3d_start() {
	${command} ${command_args} 2>&1 > $pidfile &
	PID=$!
	sleep 1
	kill -s CONT $PID 2>/dev/null
	if [ $? = 0 ]; then
		echo "Starting ${name}."
		echo $PID > ${pidfile}
	else
		cat $pidfile
		echo $current_pid > ${pidfile}
	fi
}

gnump3d_stop() {
	kill -s CONT $current_pid 2>/dev/null
	if [ $? = 0 ]; then
		echo Stopping ${name}
		kill $current_pid
	else
		echo "${name} not running? (check ${pidfile})."
	fi
}

load_rc_config $name
run_rc_command "$1"
