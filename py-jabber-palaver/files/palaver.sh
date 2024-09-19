#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: palaver.sh,v 1.3 2008/08/26 21:03:47 schnoebe Exp $
#
#   startup script for the proxy65 file transfer proxy service for Jabber
#   uses the twistd application engine
#
# PROVIDE: palaver
# REQUIRE: DAEMON s2s
#

name="palaver"
rcvar=$name
command=@PREFIX@/bin/twistd
command_interpreter="@PYTHONBIN@"
required_files="@PKG_SYSCONFDIR@/palaver.xml"
pidfile="@JABBER_PIDDIR@/${name}.pid"
logfile="@JABBER_LOGDIR@/${name}.log"
command_args="-u @JABBER_USER@ --pidfile=${pidfile} -l ${logfile}"
command_args="${command_args} palaver -c ${required_files}"

start_precmd="ensure_dirs"

ensure_dirs()
{
	ChatDir=$(sed -ne 's:.*<spool>\(.*\)</spool>.*:\1:p' ${required_files})
	mkdir -p @JABBER_PIDDIR@ ${ChatDir}
	chown @JABBER_USER@ @JABBER_PIDDIR@ ${ChatDir}
}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	ensure_piddir
	${command} ${command_args} ${pyaimt_flags} 
fi
