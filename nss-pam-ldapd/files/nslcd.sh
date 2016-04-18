#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nslcd.sh Exp $
# PROVIDE: nslcd
# REQUIRE: DAEMON

$_rc_subr_loaded . /etc/rc.subr

name="nslcd"
rcvar="${name}"
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
extra_commands="reload"
pidfile="@PIDFILE@"

load_rc_config "$name"
run_rc_command "$1"
