#!/bin/sh
#
# $NetBSD: cherokee.sh,v 1.2 2003/05/27 11:49:20 xtraeme Exp $
#

# PROVIDE: cherokee
# REQUIRE: DAEMON

. /etc/rc.subr

name="cherokee"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/$name.conf"

load_rc_config $name
run_rc_command "$1"
