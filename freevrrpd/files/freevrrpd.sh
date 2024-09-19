#!/bin/sh
#
# $Id: freevrrpd.sh,v 1.1 2005/05/04 13:15:01 spetit Exp $
#
# PROVIDE: freevrrpd
# KEYWORD: shutdown
#
# You will need to set the following variable in /etc/rc.conf to 
# start FreeVRRPd:
#
# freevrrpd=YES 

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="freevrrpd"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/freevrrpd.conf"
command="@PREFIX@/sbin/${name}"
command_args="-f ${required_files}"
pidfile="@VARBASE@/run/${name}.pid"
extra_commands="reload"

if [ -f /etc/rc.subr ]; then
	load_rc_config ${name}
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${command_args}
fi
