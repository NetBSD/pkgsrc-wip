#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: honeydarpd.sh,v 1.4 2003/11/25 15:16:31 adrian_p Exp $
#

# PROVIDE: honeydarpd
# REQUIRE: DAEMON
# BEFORE:  honeyd

. /etc/rc.subr

name="honeydarpd"
rcvar=$name
command="@PREFIX@/sbin/honeyd-arpd"
pidfile="/var/run/honeyd-arpd.pid"

load_rc_config $name
run_rc_command "$1"
