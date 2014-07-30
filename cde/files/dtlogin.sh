#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dtlogin.sh,v 1.2 2014/07/30 09:44:55 obache Exp $
#
# PROVIDE: dtlogin
# REQUIRE: DAEMON LOGIN
# KEYWORD: shutdown
#

. /etc/rc.subr

name="dtlogin"
rcvar=$name
command="@PREFIX@/dt/bin/dtlogin"
command_args="-daemon"
pidfile="@VARBASE@/dt/Xpid"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
