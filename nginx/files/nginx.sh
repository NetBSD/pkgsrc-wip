#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nginx.sh,v 1.3 2008/05/06 11:32:22 rootcho Exp $
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
