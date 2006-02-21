#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pymsnt.sh,v 1.5 2006/02/21 19:02:20 schnoebe Exp $
#
#   startup script for the PyMSNt MSN transport for Jabber
#
# PROVIDE: pymsnt
# REQUIRE: DAEMON s2s
#

name="pymsnt"
rcvar=$name
command=@PREFIX@/bin/PyMSNt
command_interpreter="@PYTHONBIN@"
pymsnt_user="@JABBERD_USER@"
pidfile="@JABBERD_PIDDIR@/${name}.pid"
logfile="@JABBERD_LOGDIR@/${name}.log"
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
	@SU@ ${pymsnt_user} -c "${command} ${pymsnt_flags} ${command_args}"
fi
