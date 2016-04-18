#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nslcd.sh Exp $
# PROVIDE: nslcd
# REQUIRE: DAEMON

$_rc_subr_loaded . /etc/rc.subr

name="pynslcd"
rcvar="${name}"
command="@PREFIX@/sbin/${name}"
command_interpreter="@PYTHONBIN@"
required_files="@PKG_SYSCONFDIR@/nslcd.conf"
extra_commands="reload"
pidfile="@PIDFILE@"

load_rc_config "$name"
run_rc_command "$1"
