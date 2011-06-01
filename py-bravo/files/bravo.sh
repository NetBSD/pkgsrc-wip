#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: bravo.sh,v 1.1.1.1 2011/06/01 03:51:46 schnoebe Exp $
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
pidfile="@PIDDIR@/${name}.pid"
logfile="@LOGDIR@/${name}.log"
command_args="-u @BRAVO_USER@ --pidfile=${pidfile} -l ${logfile}"
command_args="${command_args} bravo -c ${required_files}"

# start_precmd="ensure_dirs"

# ensure_dirs()
# {
# 	ChatDir=$(sed -ne 's:.*<spool>\(.*\)</spool>.*:\1:p' ${required_files})
# 	mkdir -p @JABBER_PIDDIR@ ${ChatDir}
# 	chown @JABBER_USER@ @JABBER_PIDDIR@ ${ChatDir}
# }

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	ensure_piddir
	${command} ${command_args}
fi
