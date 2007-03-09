#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: polkitd.sh,v 1.1.1.1 2007/03/09 08:23:57 ondratu Exp $
#

# PROVIDE: policykit
# REQUIRE: DAEMON

. /etc/rc.subr

name="polkitd"
rcvar=$name
command="@PREFIX@/sbin/polkitd"
pidfile=/var/run/${name}.pid
required_files="@PKG_SYSCONFDIR@/dbus-1/system.d/PolicyKit.conf"

load_rc_config $name
run_rc_command "$1"
