#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: honeydarpd.sh,v 1.2 2003/07/14 17:55:30 xtraeme Exp $
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
