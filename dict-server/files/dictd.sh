#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dictd.sh,v 1.1 2006/07/05 23:21:50 cheusov Exp $
#
# PROVIDE: dictd
# REQUIRE: LOGIN

. /etc/rc.subr

name="dictd"
dictd_flags=${dictd_flags-"-s --facility user --pp '/usr/bin/m4 -P'"}
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/dictd.conf"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
