#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dancer-ircd.sh,v 1.2 2003/07/14 14:37:05 xtraeme Exp $
#

# PROVIDE: dancer-ircd
# REQUIRE: DAEMON

. /etc/rc.subr

name="dancer-ircd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/ircd.conf"
dancer_ircd_user="dancer_ircd"
dancer_ircd_group="dancer_ircd"

load_rc_config $name
run_rc_command "$1"
