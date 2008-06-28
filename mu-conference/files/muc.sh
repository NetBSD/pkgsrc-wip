#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: muc.sh,v 1.2 2008/06/28 03:34:47 schnoebe Exp $
#
# PROVIDE: muc
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="muc"
rcvar=$name
command="@PREFIX@/bin/mu-conference"
required_files="@PKG_SYSCONFDIR@/${name}.xml"
extra_commands="reload"
muc_user="@JABBER_USER@"
command_args="-c ${required_files} > /dev/null 2>&1 &"
pidfile="@JABBER_PIDDIR@/`basename ${command}`.pid"
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
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${muc_flags} ${command_args}
fi
