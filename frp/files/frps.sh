#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: frps
# REQUIRE: DAEMON

. /etc/rc.subr

name="frps"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/frps.ini"
command="@PREFIX@/sbin/frps"
command_args="-c @PKG_SYSCONFDIR@/frps.ini < /dev/null > /dev/null 2>&1 &"

frp_user="@FRP_USER@"
frp_group="@FRP_GROUP@"

load_rc_config $name
run_rc_command "$1"
