#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: thy.sh,v 1.2 2003/09/30 10:38:27 algernon Exp $
#
# PROVIDE: thy
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

if [ -f @PKG_SYSCONFDIR@/thy.conf ]; then
	. @PKG_SYSCONFDIR@/thy.conf
fi

name="thy"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
command_args=${THY_OPTIONS}
pidfile=${THY_PIDFILE:-/var/run/thy.pid}
stop_postcmd="rm -f ${pidfile}"

if [ -f /etc/rc.subr ]; then
	load_rc_config ${name}
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	eval ${command} ${command_args}
fi

# arch-tag: cb56d479-9936-4a22-9c62-6d776430dd83
