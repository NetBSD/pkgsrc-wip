#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: suricata
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

: ${suricata_conf:=@PKG_SYSCONFDIR@/suricata/suricata.yaml}

name="suricata"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
required_files="${suricata_conf}"
command_args="-D --pcap"

if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	if [ -f /etc/rc.conf ]; then
		. /etc/rc.conf
	fi
	case $1 in
	start)
		start_cmd="${command} ${suricata_flags} ${command_args}"
		if [ -x ${command} -a -f ${suricata_conf} ] ; then
			${start_cmd}
		fi
		;;
	stop)
		${stop_cmd}
		;;
	*)
		@ECHO@ "Usage: $0 {start|stop}" 1>&2
		exit 64
		;;
	esac
fi
