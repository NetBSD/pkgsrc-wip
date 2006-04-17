#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: yahoo-transport.sh,v 1.1.1.1 2006/04/17 02:30:38 schnoebe Exp $
#
#   startup script for the Yahoo transport for Jabber
#
# PROVIDE: yahoo-transport
# REQUIRE: DAEMON s2s
#

name="yahoo_transport"
rcvar=$name
command=@PREFIX@/@TRANSPORTDIR@/yahoo.py
command_interpreter="@PYTHONBIN@"
required_files="@PKG_SYSCONFDIR@/yahoo-transport.ini"
yahoo_user="@JABBERD_USER@"
pidfile="@JABBERD_PIDDIR@/${name}.pid"
logfile="@JABBERD_LOGDIR@/${name}.log"
command_args=""
stop_postcmd="remove_pidfile"
start_precmd="ensure_piddir"

PID=${pidfile} 
export PID

ensure_piddir()
{
	mkdir -p @JABBERD_PIDDIR@
	chown @JABBERD_USER@ @JABBERD_PIDDIR@
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
	@SU@ ${yahoo_user} -c "${command} ${yahoo_transport_flags} ${command_args}"
fi
