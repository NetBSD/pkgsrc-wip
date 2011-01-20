#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ushare.sh,v 1.3 2011/01/20 08:27:11 obache Exp $
#
# PROVIDE: ushare
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="ushare"
rcvar=${name}
command="@PREFIX@/bin/${name}"
requre_files="@PKG_SYSCONFDIR@/ushare.conf"
command_args="--daemon"

load_rc_config ${name}
run_rc_command "$1"
