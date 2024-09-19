#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pdnsd.sh,v 1.1 2007/03/03 22:07:35 cheusov Exp $
#
# PROVIDE: pdnsd
# REQUIRE: LOGIN

. /etc/rc.subr

name="pdnsd"
pidfile="/var/run/${name}.pid"
pdnsd_flags=${pdnsd_flags-"-d -p $pidfile"}
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/pdnsd.conf"

load_rc_config $name
run_rc_command "$1"
