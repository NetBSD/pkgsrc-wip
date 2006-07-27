#!/bin/sh

#
# $NetBSD: samhain.sh,v 1.1.1.1 2006/07/27 20:40:32 bseklecki Exp $
#

# PROVIDE: samhain
# REQUIRE: LOGIN

. /etc/rc.subr

name="samhain"
rcvar=$name
pidfile=/var/run/samhain.pid
required_files="@PKG_SYSCONFDIR@/samhainrc @PREFIX@/var/samhain/samhain.db"

load_rc_config $name
run_rc_command "$1"
