#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: xrdp
# REQUIRE: DAEMON

$_rc_subr_loaded . /etc/rc.subr

name="xrdp"
rcvar=$name
command="@PREFIX@/sbin/xrdp"

load_rc_config $name
run_rc_command "$1"
