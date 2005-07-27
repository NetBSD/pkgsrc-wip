#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sendmailx.sh,v 1.3 2005/07/27 16:04:23 adrian_p Exp $
#
# PROVIDE: sendmailx
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="sendmailx"
rcvar=$name
ctl_command="@PREFIX@/sbin/mcp"
conf_file="@PKG_SYSCONFDIR@/smx.conf"
required_files=$conf_file
extra_commands="restart"
start_cmd="sendmailx_start"
pidfile="@VARBASE@/run/${name}.pid"
logdir="@VARBASE@/log/smx/"
# restart_cmd="sendmailx_restart"

sendmailx_start()
{
	${ctl_command} -l -p ${pidfile} -L ${logdir} ${conf_file} &
}

load_rc_config $name
run_rc_command "$1"
