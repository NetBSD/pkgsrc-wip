#!/bin/sh
#
# $NetBSD: slim.sh,v 1.1.1.1 2007/03/12 22:07:08 ondratu Exp $
#

# PROVIDE: slim
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="slim"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
command_args="-d"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/slim.conf"

if [ -f /etc/rc.subr ]; then
	load_rc_config ${name}
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${slim_flags} ${command_args}
fi
