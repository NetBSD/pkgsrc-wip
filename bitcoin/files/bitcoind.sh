#!/bin/sh
#
# $NetBSD: bitcoind.sh,v 1.1 2013/12/21 14:53:09 noud4 Exp $
#

# PROVIDE: bitcoind
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="bitcoind"
rcvar=$name
command="/usr/pkg/sbin/bitcoind"
pidfile="/var/run/bitcoind.pid"
required_directory="/var/bitcoin"
command_args="-daemon -pid=${pidfile} -datadir=${required_directory}"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${bitcoin_flags} ${command_args}
fi
