#!/bin/sh
#
# $NetBSD: gnump3d.sh,v 1.1 2004/04/18 15:12:50 poppnk Exp $
#

# PROVIDE: gnump3d
# REQUIRE: DAEMON LOGIN network
# KEYWORD: shutdown

. /etc/rc.subr

name="gnump3d"
rcvar=$name
command="@PREFIX@/bin/${name} --background"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/gnump3d/gnump3d.conf"

load_rc_config $name
run_rc_command "$1"
