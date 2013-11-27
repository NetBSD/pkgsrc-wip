#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: lldpd.sh,v 1.1 2013/11/27 04:12:35 makoto Exp $
#

# PROVIDE: lldpd
# REQUIRE: DAEMON
# BEFORE:  LOGIN

. /etc/rc.subr

name="lldpd"
rcvar="lldpd"
command="@PREFIX@/sbin/${name}"
#required_files="@PKG_SYSCONFDIR@/lldpd.conf"

load_rc_config $name
run_rc_command "$1"
