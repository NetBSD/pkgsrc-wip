#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: unrealircd.sh,v 1.1.1.1 2003/10/13 14:10:26 adrian_p Exp $
#
# PROVIDE: unrealircd
# REQUIRE: DAEMON
# KEYWORD: shutdown
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="unrealircd"
rcvar=$name
command="@PREFIX@/sbin/ircd"
required_files="@IRCD_HOME@/unrealircd.conf"
command_args=""

load_rc_config $name
run_rc_command "$1"
