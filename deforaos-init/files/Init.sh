#!/bin/sh
#
# $NetBSD: Init.sh,v 1.1 2010/04/15 17:12:57 khorben Exp $
#
# PROVIDE: Init
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="Init"
rcvar=$name
command="/usr/local/bin/Init"
command_args="&"

load_rc_config $name
run_rc_command "$1"
