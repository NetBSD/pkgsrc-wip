#!/bin/sh
#
# $NetBSD$
#

# PROVIDE: preload
# REQUIRE: DAEMON
# BEFORE:  LOGIN

$_rc_subr_loaded . /etc/rc.subr

name="preload"
rcvar=$name
command="/usr/pkg/sbin/${name}"

load_rc_config $name
run_rc_command "$1"
