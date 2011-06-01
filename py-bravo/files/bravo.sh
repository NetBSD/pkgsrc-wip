#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: bravo.sh,v 1.3 2011/06/01 04:33:02 schnoebe Exp $
#
#   startup script for the proxy65 file transfer proxy service for Jabber
#   uses the twistd application engine
#
# PROVIDE: bravo
# REQUIRE: DAEMON
#

name="bravo"
rcvar=$name
command=@PREFIX@/bin/twistd
command_interpreter="@PYTHONBIN@"
required_files="@PKG_SYSCONFDIR@/bravo.ini"
pidfile="@BRAVO_PIDDIR@/${name}.pid"
logfile="@BRAVO_LOGDIR@/${name}.log"
command_args="-u @BRAVO_USER@ -g @BRAVO_GROUP@ --pidfile=${pidfile}"
command_args="${command_args} -l ${logfile} -d @BRAVO_RUNDIR@ ${name}"

start_precmd="ensure_dirs"

ensure_dirs()
{
	mkdir -p @BRAVO_RUNDIR@
	chown @BRAVO_USER@ @BRAVO_RUNDIR@
}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	ensure_piddir
	${command} ${command_args}
fi
