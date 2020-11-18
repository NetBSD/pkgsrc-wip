#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: unit
# REQUIRE: DAEMON

. /etc/rc.subr

name="unit"
rcvar=${name}
command="@PREFIX@/sbin/${name}d"
pidfile="@VARBASE@/run/${name}.pid"
start_precmd="ulimit -n 2048"

load_rc_config $name
run_rc_command "$1"
