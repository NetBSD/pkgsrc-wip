#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pdns.sh,v 1.1 2006/05/04 20:31:53 anielski Exp $
#

# PROVIDE: pdns
# REQUIRE: DAEMON

. /etc/rc.subr

name="pdns"
rcvar=$name
command="@PREFIX@/sbin/pdns_server"
pidfile=/var/run/${name}.pid
required_files="@PKG_SYSCONFDIR@/pdns.conf"

load_rc_config $name
run_rc_command "$1"
