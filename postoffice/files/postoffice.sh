#!/bin/sh
#
# $NetBSD: postoffice.sh,v 1.3 2009/02/08 12:29:53 pbraun9 Exp $
#

# PROVIDE: postoffice
# REQUIRE: DAEMON

$_rc_subr_loaded . /etc/rc.subr

name="postoffice"
rcvar=$name
command="/usr/pkg/lib/${name}"
pidfile="/var/run/${name}.pid"
required_files="/usr/pkg/etc/${name}.cf"

load_rc_config $name
run_rc_command "$1"
