#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: al_session_daemon.sh,v 1.2 2003/07/30 17:39:54 marc Exp $
#
# PROVIDE: al_session_daemon
# REQUIRE: DAEMON
#
# To start albatross at startup, copy this script to /etc/rc.d and set
# albatross=YES in /etc/rc.conf.
#
# Addtionally you may set albatross_log to a file where to log stuff.

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcd_dir=`@DIRNAME@ $0`

name="al_session_daemon"
rcvar=$name
al_session_daemon_user="@ALBATROSS_USER@"
al_session_daemon_group="@ALBATROSS_GROUP@"

command="@PREFIX@/bin/al-session-daemon"
start_precmd="al_session_daemon_precmd"

start_cmd="$al_doit start"
stop_cmd="$al_doit stop"

al_session_daemon_precmd()
{
        if [ ! -d @RUNTIME_DIR@ ]
        then
                @MKDIR@ @RUNTIME_DIR@
                @CHMOD@ 0750 @RUNTIME_DIR@
                @CHOWN@ @PKG_USERS@ @RUNTIME_DIR@
        fi
        if [ ! -d @LOGDIR@ ]
        then
                @MKDIR@ @LOGDIR@
                @CHMOD@ 0750 @LOGDIR@
                @CHOWN@ @PKG_USERS@ @LOGDIR@
        fi
}

al_doit()
{
	: ${action:=start}
	case $1 in
	start)
		echo "Starting ${name}." 
		action=start
	;;
	stop)
		echo "Stopping ${name}.";
		action=stop
	;;
	esac
	if [ -z "${al_session_daemon_flags}" ]
	then
		al_session_daemon_flags="-l @LOGFILE@ -k @PIDFILE@"
	fi

	@SU@ -m ${al_session_daemon_user} -c "${command} ${al_session_daemon_flags} ${command_args} ${action}"
}

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	al_doit "$1"
else
	echo -n " ${name}"
	al_doit "$1"
fi
