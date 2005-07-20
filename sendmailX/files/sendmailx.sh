#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sendmailx.sh,v 1.2 2005/07/20 00:21:01 adrian_p Exp $
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
pidfile="/var/run/${name}.pid"
# restart_cmd="sendmailx_restart"

sendmailx_start()
{
	${ctl_command} -l -p ${pidfile} ${conf_files}
}

load_rc_config $name
run_rc_command "$1"
