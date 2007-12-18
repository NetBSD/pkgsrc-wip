#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: yahoo-transport.sh,v 1.2 2007/12/18 00:27:34 schnoebe Exp $
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
required_files="@PKG_SYSCONFDIR@/yahoo-transport.xml"
yahoo_transport_user="@JABBER_USER@"
pidfile="@JABBER_PIDDIR@/yahoo-transport.pid"
logfile="@JABBER_LOGDIR@/yahoo-transport.log"
command_args=""
stop_postcmd="remove_pidfile"
start_precmd="ensure_piddir"

PID=${pidfile} 
export PID

ensure_piddir()
{
	mkdir -p @JABBER_PIDDIR@ @JABBER_LOGDIR@
	chown @JABBER_USER@ @JABBER_PIDDIR@ @JABBER_LOGDIR@
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
