#!/bin/sh
#
# $NetBSD: maradns.sh,v 1.1.1.1 2003/05/22 11:05:12 poppnk Exp $
#

# PROVIDE: maradns
# REQUIRE: DAEMON

. /etc/rc.subr

name="maradns"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/mararc"

load_rc_config $name
run_rc_command "$1"
