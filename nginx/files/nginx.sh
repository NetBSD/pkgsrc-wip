#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nginx.sh,v 1.4 2009/01/20 20:18:42 anielski Exp $
#
# PROVIDE: nginx
# REQUIRE: DAEMON

. /etc/rc.subr

name="nginx"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
pidfile="@VARBASE@/run/${name}.pid"
start_precmd="ulimit -n 2048"

load_rc_config $name
run_rc_command "$1"
