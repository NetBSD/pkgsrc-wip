#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nginx.sh,v 1.2 2008/04/05 00:42:18 rootcho Exp $
#
# PROVIDE: nginx
# REQUIRE: DAEMON

. /etc/rc.subr

name="nginx"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
pidfile="@VARBASE@/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"
