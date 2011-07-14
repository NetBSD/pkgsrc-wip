#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: xrdp.sh,v 1.1 2011/07/14 14:34:05 mwilhelmy Exp $
#
# PROVIDE: xrdp
# REQUIRE: DAEMON

$_rc_subr_loaded . /etc/rc.subr

name="xrdp"
rcvar=$name
command="@PREFIX@/bin/xrdp"
required_files="@PKG_SYSCONFDIR@/xrdp.ini"

load_rc_config $name
run_rc_command "$1"
