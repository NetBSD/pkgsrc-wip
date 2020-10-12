#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: nats-server
# REQUIRE: DAEMON LOGIN mountall
# KEYWORD: shutdown
#
# You will need to set some variables in /etc/rc.conf to start nats-server:
#
# natsserver=YES
#
# The following variables are optional:
#
# natsserver_pidfile="/path/to/p.pid"	path to nats-server PID file
#					default:
#					@NATS_HOMEDIR@/nats-server.pid
# natsserver_logfile="/path/to/p.log"	path to nats-server log file
#					default:
#					@NATS_LOGFILE@
# natsserver_user="natssrv"		the username for nats-server daemon
# natsserver_group="natssrv"		the group for nats-server daemon

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="nats-server"
rcvar="natsserver"
command="@PREFIX@/bin/nats-server"
: ${natsserver_pidfile:="@NATS_HOMEDIR@/nats-server.pid"}
: ${natsserver_logfile:="@NATS_LOGFILE@"}
: ${natsserver_user:="natssrv"}
: ${natsserver_group:="natssrv"}

start_cmd="natssrv_start"
stop_cmd="natssrv_stop"

natssrv_start()
{
	@ECHO@ "Starting ${name}."
	ulimit -n 4096
	cd @NATS_HOMEDIR@
	/usr/bin/su ${natsserver_user}:${natsserver_group} \
	   -c "${command} -P ${natsserver_pidfile} \
	   -l ${natsserver_logfile} &"
}

natssrv_stop()
{
	local pidfile

	pidfile="${natsserver_pidfile}"
	if [ -r "${pidfile}" ]; then
		echo "Stopping ${name}."
		kill `/bin/cat ${pidfile}`
		/bin/rm "${pidfile}"
	fi
}

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	pidfile="${natsserver_pidfile}"
	run_rc_command "$1"
else
	if [ -f /etc/rc.conf ]; then
		. /etc/rc.conf
	fi
	pidfile="${natsserver_pidfile}"
	case "$1" in
	stop)
		natssrv_stop
		;;
	*)
		eval ${start_cmd}
		;;
	esac
fi
