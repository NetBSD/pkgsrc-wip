#! @RCD_SCRIPTS_SHELL@
#
# $NetBSD: milter-manager.sh,v 1.3 2010/04/09 12:57:25 obache Exp $
#

# PROVIDE: milter-manager
# REQUIRE: LOGIN
# BEFORE: mail
# KEYWORD: shutdown

. /etc/rc.subr

name="milter_manager"
rcvar=$name
command="@PREFIX@/sbin/milter-manager"
pidfile="@VARBASE@/run/milter-manager/milter-manager.pid"
command_args="--daemon"
extra_command="reload"

load_rc_config ${name}
run_rc_command "$1"
