#!/bin/sh
#
# $NetBSD: ezbounce.sh,v 1.2 2003/06/25 15:43:16 xtraeme Exp $
#

# PROVIDE: ezbounce
# REQUIRE: DAEMON

. /etc/rc.subr

name="ezbounce"
rcvar=$name
command="@PREFIX@/sbin/${name} @PKG_SYSCONFDIR@/$name.conf"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/$name.conf"
ezbounce_user="ezbounce"

load_rc_config $name
run_rc_command "$1"
