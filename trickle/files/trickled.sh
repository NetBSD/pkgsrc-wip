#!/bin/sh
# $Id: trickled.sh,v 1.1 2003/06/05 00:00:43 xtraeme Exp $
# $NetBSD: trickled.sh,v 1.1 2003/06/05 00:00:43 xtraeme Exp $
#

# PROVIDE: trickled
# REQUIRE: DAEMON

. /etc/rc.subr

name="trickled"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/trickled.conf"

load_rc_config $name
run_rc_command "$1"
