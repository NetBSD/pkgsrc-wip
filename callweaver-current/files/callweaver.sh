#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: callweaver.sh,v 1.1.1.1 2008/12/11 18:55:08 x400 Exp $
#
# PROVIDE: callweaver
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="callweaver"
rcvar=$name
command="@PREFIX@/bin/callweaver"
required_files="@PKG_SYSCONFDIR@/callweaver.conf"
extra_commands="reload"

stop_cmd="callweaver -r -x 'stop gracefully' >/dev/null"
reload_cmd="callweaver -r -x 'reload' >/dev/null"
callweaver_nice="-20"

load_rc_config $name
run_rc_command "$1"
