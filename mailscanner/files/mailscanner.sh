#!@RCD_SCRIPTS_SHELL@
#
#	$NetBSD: mailscanner.sh,v 1.1.1.1 2004/06/11 09:42:59 grantbeattie Exp $
#
# PROVIDE: mailscanner
# REQUIRE: LOGIN

. /etc/rc.subr

name="mailscanner"
rcvar=$name
start_cmd="@PREFIX@/bin/check_mailscanner"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/${MAILSCANNER}.conf"

load_rc_config $name
run_rc_command "$1"
