#!/bin/sh
#
# $NetBSD: pdns.sh,v 1.1.1.1 2003/06/27 02:47:12 poppnk Exp $
#

# PROVIDE: pdns
# REQUIRE: DAEMON

. /etc/rc.subr

name="pdns"
rcvar=$name
command="@PREFIX@/sbin/pdns_server"
pidfile=/var/run/${name}.pid
required_files="@PKG_SYSCONFDIR@/pdns.conf"

load_rc_config $name
run_rc_command "$1"
