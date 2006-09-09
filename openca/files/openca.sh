#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: openca.sh,v 1.1.1.1 2006/09/09 11:17:09 adrian_p Exp $
#
# PROVIDE: openca
# REQUIRE: DAEMON
# KEYWORD: shutdown
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="openca"
rcvar=${name}
start_precmd="openca_prestart"
required_files="@PKG_SYSCONFDIR@/openca_start @PKG_SYSCONFDIR@/openca_stop"
start_cmd="@PKG_SYSCONFDIR@/openca_start"
stop_cmd="@PKG_SYSCONFDIR@/openca_stop"

openca_prestart()
{
	if [ ! -h @PKG_SYSCONFDIR@/servers/common.conf ]; then
		cd @PKG_SYSCONFDIR@/servers && @LN@ -s node.conf common.conf
	fi
}

load_rc_config $name
run_rc_command "$1"
