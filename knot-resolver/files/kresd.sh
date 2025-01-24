#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: knot-resolver
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="kresd"
rcvar=$name
command="@PREFIX@/sbin/daemonize "
command_args="-p ${pidfile} @PREFIX@/sbin/${name} -c @PKG_SYSCONFDIR@/knot-resolver/${name}.conf -c @PKG_SYSCONFDIR@/../lib/knot-resolver/distro-preconfig.lua -n"
required_files="@PKG_SYSCONFDIR@/knot-resolver/${name}.conf"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${command_args}
fi
