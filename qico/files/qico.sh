#!/bin/sh
#
# $NetBSD: qico.sh,v 1.1.1.1 2003/09/17 18:07:11 xtraeme Exp $
#
# PROVIDE: qico
# REQUIRE: DAEMON
# KEYWORD: shutdown

if test -x @PREFIX@/bin/qico; then
	if test $# -eq 0; then
		echo -n ' qico'
		su -m uucp -c "@PREFIX@/bin/qico -d" >/dev/null
		exit 0
	fi

	case "$1" in
	start )
		echo -n ' qico'
		su -m uucp -c "@PREFIX@/bin/qico -d" >/dev/null
		exit 0
		;;
	stop )
		su -m uucp -c "@PREFIX@/bin/qico -q"
		exit 0
		;;
	restart )
		$0 stop
		sleep 2
		exec $0 start
		;;
	* )
		echo "Usage: $0 (start|stop|restart)"
		exit 1
		;;
	esac
fi

exit 0
