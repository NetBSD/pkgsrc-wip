#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: s2s.sh,v 1.2 2004/03/17 02:41:33 xtraeme Exp $
#
# PROVIDE: s2s
# REQUIRE: DAEMON c2s

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="s2s"
rcvar=$name
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/${name}.xml"
extra_commands="reload"
command_args="-D 2>&1 > @JABBERD_LOGDIR@/${name}.log &"
s2s_user="@JABBERD_USER@"
pidfile="@JABBERD_PIDDIR@/${name}.pid"
stop_postcmd="remove_pidfile"

remove_pidfile()
{
        if [ -f @JABBERD_PIDDIR@/${name}.pid ]; then
            rm -f @JABBERD_PIDDIR@/${name}.pid
        fi
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${s2s_flags} ${command_args}
fi
