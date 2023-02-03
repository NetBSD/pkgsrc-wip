#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: incron
# REQUIRE: DISKS

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="incron"
rcvar="$name"
command="@PREFIX@/sbin/incrond"
pidfile="@VARBASE@/run/incrond.pid"

load_rc_config "$name"
run_rc_command "$1"
