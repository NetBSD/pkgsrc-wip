#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: unrealircd.sh,v 1.3 2004/09/29 23:38:39 adrian_p Exp $
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
command_args="-u @IRCD_USER@:@IRCD_GROUP@"

load_rc_config $name
run_rc_command "$1"
