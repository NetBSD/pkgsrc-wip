#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# agentcc - Agent Command Center, OpenAI-compatible LLM gateway
#
# PROVIDE: agentcc
# REQUIRE: NETWORK
# KEYWORD: shutdown
#
# You will need to set some variables in @PKG_SYSCONFDIR@/rc.conf to start
# agentcc:
#
#   agentcc=YES
#   agentcc_log=@VARBASE@/log/agentcc.log   # optional (default)

. @SYSCONFBASE@/rc.subr

name="agentcc"
rcvar=$name

command="@PREFIX@/bin/agentcc"
command_args="--config @PKG_SYSCONFDIR@/agentcc.conf"
pidfile="@VARBASE@/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/agentcc.conf"

: ${agentcc_log:=@VARBASE@/log/agentcc.log}

# The gateway does not daemonize or write its own pidfile; run it in the
# background and record the pid so stop/status/restart work.
agentcc_start()
{
	if [ -f "${pidfile}" ] && checkyesno "${name}"; then
		if check_pidfile "${pidfile}" "${command}"; then
			echo "${name} is already running (pid $(cat "${pidfile}"))."
			return 0
		fi
		rm -f "${pidfile}"
	fi

	local logdir
	logdir=$(dirname "${agentcc_log}")
	if [ ! -d "${logdir}" ]; then
		install -d -o "${agentcc_user:-root}" -g "${agentcc_group:-wheel}" "${logdir}"
	fi

	echo "Starting ${name}."
	${command} ${command_args} >>"${agentcc_log}" 2>&1 &
	echo $! > "${pidfile}"
}

agentcc_stop()
{
	if [ ! -f "${pidfile}" ]; then
		echo "${name} is not running."
		return 0
	fi
	echo "Stopping ${name}."
	kill $(cat "${pidfile}") 2>/dev/null
	rm -f "${pidfile}"
}

agentcc_status()
{
	if [ -f "${pidfile}" ] && check_pidfile "${pidfile}" "${command}"; then
		echo "${name} is running as pid $(cat "${pidfile}")."
	else
		echo "${name} is not running."
	fi
}

start_cmd="agentcc_start"
stop_cmd="agentcc_stop"
status_cmd="agentcc_status"
restart_cmd="agentcc_restart"

agentcc_restart()
{
	agentcc_stop
	sleep 1
	agentcc_start
}

load_rc_config $name
run_rc_command "$1"
