#!/bin/sh
#
# $NetBSD: cherokee.sh,v 1.1.1.1 2003/04/25 17:00:19 xtraeme Exp $
#

# PROVIDE: cherokee
# REQUIRE: DAEMON

. /etc/rc.subr

name="cherokee"
rcvar=$name
command="@PREFIX@/sbin/${name} &"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/$name.conf"

load_rc_config $name
run_rc_command "$1"
