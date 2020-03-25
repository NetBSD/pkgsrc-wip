#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: mariadb
# REQUIRE: DAEMON LOGIN mountall
# KEYWORD: shutdown
#
# You will need to set some variables in /etc/rc.conf to start MariaDB:
#
# mariadb=YES
#
# The following variables are optional:
#
#       mysqld_user="mysql"		# user to run mysqld as
#       mysqld_datadir="/path/to/home"	# path to MariaDB database directory
#	mysqld_pidfile="/path/to/p.pid"	# path to MariaDB PID file

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="mysqld"
rcvar="mariadb"
command="@PREFIX@/bin/mysqld_safe"
procname="@PREFIX@/sbin/${name}"
: ${mysqld_user:=@MYSQL_USER@}
: ${mysqld_group:=@MYSQL_GROUP@}
: ${mysqld_datadir:=@MYSQL_DATADIR@}
: ${mysqld_pidfile:=@MYSQL_PIDFILE@}

extra_commands="initdb"
initdb_cmd="mysqld_initdb"
start_precmd="mysqld_precmd"
start_cmd="mysqld_start"

mysqld_precmd()
{
	if [ ! -d ${mysqld_datadir}/mysql ]; then
		${initdb_cmd}
	fi
}

mysqld_initdb()
{
	initdb="@PREFIX@/bin/mysql_install_db"
	if [ ! -x ${initdb} ]; then
		return 1
	fi
	if [ -f ${mysqld_datadir}/mysql/host.frm ]; then
		@ECHO@ "The MariaDB database has already been initialized."
		@ECHO@ "Skipping database initialization."
	else
		@ECHO@ "Initializing MariaDB database system tables."
		${initdb} --force --user=${mysqld_user} \
			  --datadir=${mysqld_datadir} || return 1
		if [ -d ${mysqld_datadir} ]; then
			@CHOWN@ -R ${mysqld_user}:${mysqld_group} \
				${mysqld_datadir}
		fi
	fi
}

mysqld_start()
{
	for f in $required_files; do
		if [ ! -r "$f" ]; then
			@ECHO@ 1>&2 "$0: WARNING: $f is not readable"
			if [ -z $rc_force ]; then
				return 1
			fi
		fi
	done
	@ECHO@ "Starting ${name} (MariaDB)."
	ulimit -n 4096
	cd @PREFIX@
	${command} --user=${mysqld_user} --datadir=${mysqld_datadir} \
		   --pid-file=${mysqld_pidfile} ${mysqld_flags} \
		   ${thread_flags} &
}

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	pidfile="${mysqld_pidfile}"
	run_rc_command "$1"
else
	if [ -f /etc/rc.conf ]; then
		. /etc/rc.conf
	fi
	pidfile="${mysqld_pidfile}"
	case "$1" in
	initdb)
		eval ${initdb_cmd}
		;;
	stop)
		if [ -r "${pidfile}" ]; then
			@ECHO@ "Stopping ${name} (MariaDB)."
			kill `@CAT@ ${pidfile}`
		fi
		;;
	*)
		eval ${start_precmd}
		eval ${start_cmd}
		;;
	esac
fi
