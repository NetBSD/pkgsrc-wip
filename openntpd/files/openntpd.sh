#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: openntpd.sh,v 1.1.1.1 2004/07/16 20:41:08 ppostma Exp $
#

# PROVIDE: openntpd
# REQUIRE: DAEMON
# BEFORE:  LOGIN

. /etc/rc.subr

name="ntpd"
rcvar="openntpd"
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/ntpd.conf"

load_rc_config $name
run_rc_command "$1"
