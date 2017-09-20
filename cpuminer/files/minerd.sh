#!/bin/sh
#
# $NetBSD$
#

# PROVIDE: minerd
# REQUIRE: DAEMON

. /etc/rc.subr

name="minerd"
rcvar=$name
command="/usr/pkg/bin/${name}"
minerd_flags="-B"

load_rc_config $name
run_rc_command "$1"
