#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pymsnt.sh,v 1.7 2008/02/15 14:22:10 sebpierrel Exp $
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
command_args="-b"	# background/daemonize
pymsnt_user="@JABBER_USER@"
pidfile="@JABBER_PIDDIR@/${name}.pid"
logfile="@JABBER_LOGDIR@/${name}.log"
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
	@SU@ ${pymsnt_user} -c "${command} ${pymsnt_flags} ${command_args}"
fi
