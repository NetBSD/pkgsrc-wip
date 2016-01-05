#!@RCD_SCRIPTS_SHELL@
#
# PROVIDE: bareos-sd
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="bareossd"
rcvar=$name
command="@PREFIX@/sbin/bareos-sd"
required_files="@BAREOS_ETCDIR@/bareos-sd.conf"
pidfile="@BAREOS_PIDDIR@/bareos-sd.9103.pid"
command_args="-c ${required_files} -u @BAREOS_SD_USER@ -g @BAREOS_GROUP@"
start_precmd="bareossd_precmd"

bareossd_precmd()
{
    if [ ! -d @BAREOS_PIDDIR@ ]; then
        mkdir -p -m 775 @BAREOS_PIDDIR@
    else
        chmod 775 @BAREOS_PIDDIR@
    fi
    chown @BAREOS_SD_USER@:@BAREOS_GROUP@ @BAREOS_PIDDIR@
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${bareossd_flags} -c ${required_files}
fi

