#!/bin/sh
#
# $NetBSD: ezbounce.sh,v 1.1.1.1 2003/04/20 06:27:44 xtraeme Exp $
#

# PROVIDE: ezbounce
# REQUIRE: DAEMON

. /etc/rc.subr

name="ezbounce"
rcvar=$name
command="@PREFIX@/sbin/${name} @PKG_SYSCONFDIR@/$name.conf"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/$name.conf"

load_rc_config $name
run_rc_command "$1"
