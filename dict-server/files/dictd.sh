#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dictd.sh,v 1.3 2006/07/18 20:43:11 cheusov Exp $
#
# PROVIDE: dictd
# REQUIRE: LOGIN

. /etc/rc.subr

name="dictd"
dictd_flags=${dictd_flags-"--pp '@PATH_TO_M4@ -P'"}
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/dictd.conf"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
