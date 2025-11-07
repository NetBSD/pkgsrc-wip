#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: usbmuxd
# REQUIRE: DAEMON
# KEYWORD: shutdown

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="usbmuxd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
command_args="--user usbmux"
pidfile="/var/run/usbmuxd.pid"

load_rc_config $name
run_rc_command "$1"
