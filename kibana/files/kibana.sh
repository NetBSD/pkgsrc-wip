#!/bin/sh
#
# $NetBSD: kibana.sh,v 1.1 2015/02/22 20:10:34 mbowie Exp $
#

# PROVIDE: kibana
# REQUIRE: elasticsearch

$_rc_subr_loaded . /etc/rc.subr

name="kibana"
rcvar=${name}
command_interpreter=@PREFIX@/bin/node
required_files="@PKG_SYSCONFDIR@/${name}.yml"
pidfile="/var/run/${name}.pid"
start_cmd="kibana_startcmd"
stop_cmd="kibana_stop"
status_cmd="kibana_status"
extra_commands="status"

load_rc_config $name

kibana_startcmd()
{
	(CONFIG_PATH="${required_files}" NODE_ENV="production" \
		${command_interpreter} @KBDIR@/src/bin/${name}.js 2>&1 > /var/log/${name}.log & \
		echo -n ${!} >&3 & ) 3>${pidfile}
	kibana_status
}

kibana_stop()
{
	printf "Stopping ${name}"

	kibana_pid=$(check_pidfile ${pidfile} ${command_interpreter})
	if test -n "${kibana_pid}"; then
		kill -${sig_stop:-TERM} $kibana_pid
		wait_for_pids $pids
		rm ${pidfile}
	fi
	printf ".\n"
}

kibana_status()
{
	kibana_pid=$(check_pidfile ${pidfile} ${command_interpreter})
	if test -n "${kibana_pid}"; then
		echo "${name} running as pid ${kibana_pid}"
		return 0
	else
		echo "${name} not running"
		return 0
	fi
}

run_rc_command "$1"

