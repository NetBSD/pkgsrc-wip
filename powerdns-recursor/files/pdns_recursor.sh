#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pdns_recursor.sh,v 1.1.1.1 2006/08/15 13:15:00 ondratu Exp $
#

# PROVIDE: pdns_recursor
# REQUIRE: DAEMON

. /etc/rc.subr

name="pdns_recursor"
rcvar=$name
command="@PREFIX@/sbin/pdns_recursor"
command_args="--daemon=yes --config-dir=@PKG_SYSCONFDIR@  >/dev/null 2>&1"
pidfile=/var/run/${name}.pid
required_files="@PKG_SYSCONFDIR@/recursor.conf"

load_rc_config $name
run_rc_command "$1"
