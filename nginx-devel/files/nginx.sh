#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nginx.sh,v 1.1.1.1 2008/03/27 18:54:57 rootcho Exp $
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
