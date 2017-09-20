#!/bin/sh
#
# $NetBSD$
#

# PROVIDE: minerd
# REQUIRE: DAEMON

. /etc/rc.subr

name="minerd"
rcvar=$name
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/minerd.conf"
minerd_flags="-B -S -c @PKG_SYSCONFDIR@/minerd.conf"

load_rc_config $name
run_rc_command "$1"
