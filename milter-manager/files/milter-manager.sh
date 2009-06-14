#! @RCD_SCRIPTS_SHELL@

# PROVIDE: milter-manager
# REQUIRE: LOGIN
# BEFORE: mail
# KEYWORD: shutdown

. /etc/rc.subr

name="milter_manager"
rcvar=$name
command="@PREFIX@/sbin/milter-manager"
pidfile="@VARBASE@/run/milter-manager/milter-manager.pid"
command_args="--pid-file ${pidfile} --daemon --user-name @MILTER_MANAGER_USER@ --group-name @MILTER_MANAGER_GROUP@ --socket-group-name @MILTER_MANAGER_SOCKET_GROUP@"
extra_command="reload"

load_rc_config ${name}
run_rc_command "$1"
