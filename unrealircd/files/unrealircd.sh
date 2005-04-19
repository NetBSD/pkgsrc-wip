#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: unrealircd.sh,v 1.4 2005/04/19 22:20:18 adrian_p Exp $
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
rcvar=${name}
command="@PREFIX@/sbin/ircd"
required_files="@IRCD_HOME@/unrealircd.conf"
unrealircd_user="@IRCD_USER@"
unrealircd_group="@IRCD_GROUP@"

load_rc_config $name
run_rc_command "$1"
