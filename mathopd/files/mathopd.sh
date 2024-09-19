#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mathopd.sh,v 1.1.1.1 2005/01/13 06:45:32 ishit Exp $
#
# PROVIDE: mathopd 
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="mathopd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
command_args="-f @PKG_SYSCONFDIR@/${name}.conf"
required_files="@PKG_SYSCONFDIR@/${name}.conf"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${command_args}
fi
