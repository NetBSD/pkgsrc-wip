#!/bin/sh
#
# $NetBSD: honeydarpd.sh,v 1.1 2003/07/09 15:41:43 adrian_p Exp $
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
