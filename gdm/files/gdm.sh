#!/bin/sh
#
# $NetBSD: gdm.sh,v 1.1.1.1 2004/01/10 04:11:20 minskim Exp $
#

# PROVIDE: gdm
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

. /etc/rc.subr

name="gdm"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PREFIX@/etc/gdm/gdm.conf"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
