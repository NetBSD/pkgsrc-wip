#!/bin/sh
#
# $NetBSD: pcscd.sh,v 1.1.1.1 2005/07/20 21:07:06 udontknow Exp $
#
# PROVIDE: pcscd
# REQUIRE: DAEMON
# KEYWORD: shutdown 

if [ -f /etc/rc.subr ]
then
        . /etc/rc.subr
fi

name="pcscd"
rcvar=$name
command="@PREFIX@/sbin/pcscd"

load_rc_config $name
run_rc_command "$1"
