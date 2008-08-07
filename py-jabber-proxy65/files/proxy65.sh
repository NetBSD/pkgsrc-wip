#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: proxy65.sh,v 1.1 2008/08/07 22:17:25 schnoebe Exp $
#
#   startup script for the PyAIMt AOL transport for Jabber
#   uses the twistd application engine
#
# PROVIDE: pyaimt
# REQUIRE: DAEMON s2s
#

name="proxy65"
rcvar=$name
command=@PREFIX@/bin/twistd
command_interpreter="@PYTHONBIN@"
pidfile="@JABBER_PIDDIR@/${name}.pid"
logfile="@JABBER_LOGDIR@/${name}.log"
command_args="-u @JABBER_USER@ --pidfile=${pidfile} -l ${logfile}"
command_args="${command_args} proxy65"
command_args="${command_args} "
stop_postcmd="remove_pidfile"
start_precmd="ensure_piddir"

ensure_piddir()
{
	mkdir -p @JABBER_PIDDIR@
	chown @JABBER_USER@ @JABBER_PIDDIR@
}

remove_pidfile()
{
        if [ -f $pidfile ]; then
            rm -f $pidfile
        fi
}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	@SU@ ${pyaimt_user} -c "${command} ${pyaimt_flags} ${command_args}"
fi
