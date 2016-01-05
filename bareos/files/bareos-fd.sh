#!@RCD_SCRIPTS_SHELL@
#
# PROVIDE: bareos-fd
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="bareosfd"
rcvar=$name
command="@PREFIX@/sbin/bareos-fd"
required_files="@BAREOS_ETCDIR@/bareos-fd.conf"
pidfile="@BAREOS_PIDDIR@/bareos-fd.9102.pid"
command_args="-c ${required_files} -g @BAREOS_GROUP@"
start_precmd="bareosfd_precmd"

bareosfd_precmd()
{
    if [ ! -d @BAREOS_PIDDIR@ ]; then
        mkdir -p -m 775 @BAREOS_PIDDIR@
    else
        chmod 775 @BAREOS_PIDDIR@
    fi
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${bareosfd_flags} -c ${required_files}
fi

