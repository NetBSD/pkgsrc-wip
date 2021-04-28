#!@SMF_METHOD_SHELL@
#
# $NetBSD$
#
# Init script for mysqld.
#

. /lib/svc/share/smf_include.sh

PIDFILE="@VARBASE@/run/mariadb/mariadb.pid"

ulimit -n 10240

case "$1" in
start)
	@LOCALBASE@/sbin/mysqld --user=@MARIADB_USER@ \
		--basedir=@LOCALBASE@ \
		--datadir=@MARIADB_DATADIR@ \
		--pid-file=${PIDFILE} \
		--log-error=@VARBASE@/log/mariadb/error.log &
	;;
stop)
	[ -f ${PIDFILE} ] && kill `@HEAD@ -1 ${PIDFILE}`
	;;
*)
	echo "Usage: $0 {start|stop}" >&2
	exit 1
	;;
esac

exit $SMF_EXIT_OK
