#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sesman.sh,v 1.1 2011/07/14 14:34:05 mwilhelmy Exp $
#
# PROVIDE: sesman
# REQUIRE: DAEMON
# BEFORE:  xrdp

$_rc_subr_loaded . /etc/rc.subr

name="sesman"
rcvar=$name
command="@PREFIX@/bin/sesman"
required_files="@PKG_SYSCONFDIR@/sesman.ini"

load_rc_config $name
run_rc_command "$1"
