#!/bin/sh
#
# $NetBSD: xinetd.sh,v 1.1 2004/07/10 17:27:08 poppnk Exp $
#

# PROVIDE: xinetd
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="xinetd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/xinetd.conf"

load_rc_config $name
run_rc_command "$1"
