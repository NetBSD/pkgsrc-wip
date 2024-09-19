#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sshd.sh,v 1.16 2015/11/11 11:40:06 sevan Exp $
#
# PROVIDE: charybdis
# REQUIRE: DAEMON
#
# You will need to set some variables in /etc/rc.conf to start charybdis:
#
# charybdis=YES

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="charybdis"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="@CHARYBDIS_PID_DIR@/${name}.pid"
required_files="@PKG_SYSCONFDIR@/ircd.conf"
command_args="-pidfile ${pidfile}"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${command_args}
fi
