#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: $
#
# PROVIDE: hiawatha
# REQUIRE: DAEMON

pidfile=/usr/pkg/var/run/hiawatha.pid

name="hiawatha"
command="hiawatha"

cmd=${1:-start}

case ${cmd} in
	start)
		echo "Starting ${name}."
		${command}&
		echo $! > ${pidfile}
		;;

	stop)
		echo "Stopping ${name}."
		kill `cat ${pidfile}`
		rm ${pidfile}
		;;

	restart)
		( $0 stop )
		sleep 5
		$0 start
		;;

	*)
		echo 1>&2 "Usage: $0 [restart|start|stop]"
		exit 1
		;;
esac
exit 0
