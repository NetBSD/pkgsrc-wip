#!/bin/sh
#
# $NetBSD: xinetd.sh,v 1.2 2004/07/10 18:06:26 poppnk Exp $
#

# PROVIDE: xinetd
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="xinetd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
command_args="-pidfile /var/run/${name}.pid"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/xinetd.conf"

load_rc_config $name
run_rc_command "$1"
