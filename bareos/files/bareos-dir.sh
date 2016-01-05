#!@RCD_SCRIPTS_SHELL@
#
# PROVIDE: bareos-dir
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="bareosdir"
rcvar=$name
command="@PREFIX@/sbin/bareos-dir"
required_files="@BAREOS_ETCDIR@/bareos-dir.conf"
pidfile="@BAREOS_PIDDIR@/bareos-dir.9101.pid"
command_args="-c ${required_files} -u @BAREOS_DIR_USER@ -g @BAREOS_GROUP@"
start_precmd="bareosdir_precmd"

bareosdir_precmd()
{
    if [ ! -d @BAREOS_PIDDIR@ ]; then
        mkdir -p -m 775 @BAREOS_PIDDIR@
    else
        chmod 775 @BAREOS_PIDDIR@
    fi
    chown @BAREOS_DIR_USER@:@BAREOS_GROUP@ @BAREOS_PIDDIR@
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${bareosdir_flags} -c ${required_files}
fi

