#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: entrance.sh,v 1.1.1.1 2008/08/07 21:36:34 yazzy Exp $
#

# PROVIDE: entrance
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="entranced"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/entrance/entranced.pid"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
fi
