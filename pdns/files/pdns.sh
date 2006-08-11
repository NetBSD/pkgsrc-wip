#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pdns.sh,v 1.3 2006/08/11 14:25:40 ghen Exp $
#

# PROVIDE: pdns
# REQUIRE: DAEMON

. /etc/rc.subr

name="pdns"
rcvar=$name
command="@PREFIX@/sbin/pdns_server"
command_args="--daemon=yes"
pidfile=/var/run/${name}.pid
required_files="@PKG_SYSCONFDIR@/pdns.conf"

load_rc_config $name
run_rc_command "$1"
