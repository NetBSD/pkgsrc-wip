#!/bin/sh
#
# $NetBSD: postoffice.sh,v 1.1 2006/09/28 21:47:31 elge Exp $
#
# PROVIDE: postoffice
# REQUIRE: DAEMON

$_rc_subr_loaded . /etc/rc.subr

name="postoffice"
rcvar=$name
command="/usr/pkg/libexec/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PREFIX@/etc/${name}.cf"
start_precmd="postoffice_precmd"

postoffice_precmd()
{
	rc_flags="-C@PREFIX@/etc/${name}.cf $rc_flags"
	return 0
}

load_rc_config $name
run_rc_command "$1"
