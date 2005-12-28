#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pyaimt.sh,v 1.1.1.1 2005/12/28 01:21:50 schnoebe Exp $
#
#   startup script for the PyAIMt AOL transport for Jabber
#   uses the twistd application engine
#
# PROVIDE: pyaimt
# REQUIRE: DAEMON s2s
#

name="pyaimt"
rcvar=$name
command_interpreter="@PYTHONBIN@"
required_files="@PKG_SYSCONFDIR@/pyaimt.xml"
command="@PREFIX@/@TRANSPORTDIR@/PyAIMt.py"
pyaimt_user="@JABBERD_USER@"
pidfile="@JABBERD_PIDDIR@/${name}.pid"
logfile="@JABBERD_LOGDIR@/${name}.log"
command_args="-b -l ${logfile} -c ${required_files}"
stop_postcmd="remove_pidfile"
start_precmd="ensure_piddir"

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
	@SU@ ${pyaimt_user} -c "${command} ${pyaimt_flags} ${command_args}"
fi
