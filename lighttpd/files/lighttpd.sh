#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: lighttpd.sh,v 1.3 2013/03/26 15:10:44 makoto Exp $
#
# PROVIDE: lighttpd
# REQUIRE: DAEMON

. /etc/rc.subr

name="lighttpd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
conf_file="@PKG_SYSCONFDIR@/${name}.conf"
required_files="${conf_file}"
extra_commands="reload"
command_args="-f ${conf_file}"

load_rc_config $name
run_rc_command $1
