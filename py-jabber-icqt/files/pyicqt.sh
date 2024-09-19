#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pyicqt.sh,v 1.4 2008/02/18 21:24:57 sebpierrel Exp $
#
#   startup script for the PyICQt IM transport for Jabber
#   uses the twistd application engine
#
# PROVIDE: pyicqt
# REQUIRE: DAEMON s2s
#

name="pyicqt"
rcvar=$name
command_interpreter="@PYTHONBIN@"
required_files="@PKG_SYSCONFDIR@/pyicqt.xml"
command="@PREFIX@/bin/PyICQt"
pyicqt_user="@JABBER_USER@"
pidfile="@JABBER_PIDDIR@/${name}.pid"
logfile="@JABBER_LOGDIR@/${name}.log"
command_args="-l ${logfile} -c @PKG_SYSCONFDIR@/pyicqt.xml &"
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
	@SU@ -m ${pyicqt_user} -c "${command} ${pyicqt_flags} ${command_args}"
fi
