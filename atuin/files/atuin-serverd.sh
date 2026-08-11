#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: atuin_server
# REQUIRE: DAEMON
# KEYWORD: shutdown

$_rc_subr_loaded . /etc/rc.subr

name="atuin_server"
rcvar=$name
pidfile="@VARBASE@/run/${name}.pid"
command="@PREFIX@/bin/atuin-server"
command_args="start"

atuin_server_user="@ATUIN_USER@"
atuin_server_group="@ATUIN_GROUP@"
atuin_server_dbdir="@VARBASE@/db/atuin_server"
atuin_server_logfile="${atuin_server_dbdir}/atuin-server.log"

start_precmd="atuin_server_precmd"
start_cmd="atuin_server_start"
stop_cmd="atuin_server_stop"

atuin_server_precmd()
{
	if [ ! -d "${atuin_server_dbdir}" ]; then
		install -d -o ${atuin_server_user} -g ${atuin_server_group} \
			-m 0750 "${atuin_server_dbdir}"
	fi
}

atuin_server_start()
{
	if [ -f "${pidfile}" ] && kill -0 "$(cat ${pidfile})" 2>/dev/null; then
		echo "${name} already running as pid $(cat ${pidfile})."
		return 1
	fi
	echo "Starting ${name}."
	# atuin-server only runs in the foreground, so background it here and
	# capture the child PID from inside su (where $! is atuin-server itself,
	# not the su process).
	pid=$(su -m ${atuin_server_user} -c \
	    "ATUIN_CONFIG_DIR=@PKG_SYSCONFDIR@ ${command} ${command_args} \
	     >> ${atuin_server_logfile} 2>&1 & echo \$!")
	echo ${pid} > ${pidfile}
}

atuin_server_stop()
{
	if [ ! -f "${pidfile}" ]; then
		echo "${name} not running (no ${pidfile})."
		return 1
	fi
	echo "Stopping ${name}."
	kill "$(cat ${pidfile})" && rm -f "${pidfile}"
}

load_rc_config $name
run_rc_command "$1"
