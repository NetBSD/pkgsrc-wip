#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: honeyd.sh,v 1.1.1.1 2003/11/25 12:49:53 adrian_p Exp $
#

# PROVIDE: honeyd
# REQUIRE: DAEMON
# AFTER:  honeydarpd

. /etc/rc.subr

name="honeyd"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="/var/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"
