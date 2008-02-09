#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: polipo.sh,v 1.1 2008/02/09 21:27:38 ishit Exp $
#
# PROVIDE: polipo
# REQUIRE: DAEMON
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="polipo"
rcvar="${name}"
command="@PREFIX@/bin/${name}"
command_args="-c @PKG_SYSCONFDIR@/polipo/config daemonise=true"
required_files="@PKG_SYSCONFDIR@/polipo/config"
start_cmd=polipo_start
purge_cmd="${command} -x"
extra_commands="purge"

polipo_start() {
	eval "${command} ${command_args}"
}

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${command_args}
fi
