#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: qico.sh,v 1.2 2011/04/12 20:40:35 shattered Exp $
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
