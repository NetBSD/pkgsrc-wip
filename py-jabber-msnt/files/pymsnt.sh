#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pymsnt.sh,v 1.1.1.1 2005/11/05 02:25:42 schnoebe Exp $
#
#   startup script for the PyMSNt MSN transport for Jabber
#   uses the twistd application engine
#
# PROVIDE: pymsnt
# REQUIRE: DAEMON s2s
#

name="pymsnt"
rcvar=$name
command=@PREFIX@/bin/twistd
required_files="@PREFIX@/@TRANSPORTDIR@/PyMSNt.tac"
pymsnt_user="@JABBERD_USER@"
pidfile="@JABBERD_PIDDIR@/${name}.pid"
logfile="@JABBERD_LOGDIR@/${name}.log
command_args="--pidfile ${pidfile} -oy ${required_files} -l ${logfile}"
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
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	@SU@ ${pymsnt_user} -c "${command} ${pymsnt_flags} ${command_args}"
fi
