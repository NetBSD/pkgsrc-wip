#!/bin/sh
#
# $NetBSD: arpd.sh,v 1.1.1.1 2003/04/07 10:11:55 adrian_p Exp $
#

# PROVIDE: arpd
# REQUIRE: DAEMON
# BEFORE:  honeyd

. /etc/rc.subr

name="arpd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"
