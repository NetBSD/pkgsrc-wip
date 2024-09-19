#!@RCD_SCRIPTS_SHELL@
#
# PROVIDE: smsd
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="smsd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
command_args="&"
required_files="@PKG_SYSCONFDIR@/smsd.conf"
start_precmd="smsd_precmd"

if [ -f "${required_files}" ]; then
	pidfile_=`@AWK@ '/^#/ {next}; /^pidfile[ 	]/ {r = $3};
			END {print r}' ${required_files}`
	if [ -n "${pidfile_}" ]; then
		pidfile=${pidfile_}
	fi
	smsd_user=`@AWK@ '/^#/ {next}; /^user[ 	]/ {r = $3};
			END {print r}' ${required_files}`
	device=`@AWK@ '/^#/ {next}; /^device[ 	]/ {r = $3};
			END {print r}' ${required_files}`
	logfile=`@AWK@ '/^#/ {next}; /^logfile[ 	]/ {r = $3};
			END {print r}' ${required_files}`
fi

smsd_precmd()
{
	if [ -n "${smsd_user}" -a -n "${device}" ]; then
    		@CHOWN@ ${smsd_user} ${device}
	fi
	if [ -n "${smsd_user}" -a -n "${pidfile}" ]; then
    		@TOUCH@ ${pidfile}
    		@CHOWN@ ${smsd_user} ${pidfile}
	fi
	if [ -n "${smsd_user}" -a -n "${logfile}" ]; then
    		@TOUCH@ ${logfile}
    		@CHOWN@ ${smsd_user} ${logfile}
	fi
}

if [ -f /etc/rc.subr -a -f /etc/rc.conf \
     -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${command_args}
fi
