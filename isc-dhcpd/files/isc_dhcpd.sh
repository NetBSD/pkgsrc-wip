#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: isc_dhcpd.sh,v 1.7 2005/03/04 15:25:28 hfath Exp $
# $Id: isc_dhcpd.sh,v 1.7 2005/03/04 15:25:28 hfath Exp $

# PROVIDE: dhcpd
# REQUIRE: DAEMON
# BEFORE:  LOGIN

if [ -f /etc/rc.subr ]; then
        . /etc/rc.subr
fi

name="dhcpd"
rcvar="isc_dhcpd"
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/dhcp/${name}.conf @VARBASE@/db/dhcp/${name}.leases"

if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -f /etc/rc.d/DAEMON ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	case ${1:-start} in
	start)
		if [ -x ${command} ]
		then
			for _f in $required_files; do
                                if [ ! -r "${_f}" ]; then
                                        @ECHO@ 1>&2 "$0: WARNING: ${_f} is not readable."
				fi
			done
			@ECHO@ "Starting ${name}."
			eval ${start_precmd}
			eval ${command} ${isc_dhcpd_flags} ${command_args}
		fi
		;;
	stop)
		if [ -f ${pidfile} ]; then
			pid=`@HEAD@ -1 ${pidfile}`
			@ECHO@ "Stopping ${name}."
			kill -TERM ${pid}
			@RM@ -f ${pidfile}
		else
			@ECHO@ "${name} not running?"
		fi
		;;
	restart)
		( $0 stop )
		sleep 1
		$0 start
		;;
	status)
		if [ -f ${pidfile} ]; then
			pid=`@HEAD@ -1 ${pidfile}`
			@ECHO@ "${name} is running as pid ${pid}."
		else
			@ECHO@ "${name} is not running."
		fi
		;;
	esac
fi
