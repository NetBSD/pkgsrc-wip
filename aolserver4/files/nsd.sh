#!@RCD_SCRIPTS_SHELL@
#
# 
# PROVIDE: nsd
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="nsd"
rcvar=${name}
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/nsd.tcl"
nsd_flags="-t @PKG_SYSCONFDIR@/nsd.tcl -u nsadmin -g nsadmin"
nsd_user="root"
pidfile="/var/run/nsd/server1.pid"

# set defaults
if [ -r /etc/rc.conf ]
then
        . /etc/rc.conf
else
        eval ${rcvar}=YES
fi

nsd_doit ()
{

	case $1 in
	start)	
		if [ -f ${pidfile} ]
		then
			@ECHO@ "${name} already running as `cat ${pidfile}`"
		else
			@ECHO@ "Starting ${name}." 
			${command} ${nsd_flags}
		fi;;

	stop)		
		if [ -f ${pidfile} ]
		then  
			echo "Stopping ${name}."
			kill -TERM `cat ${pidfile}`
		fi;;
	restart)	
		if [ -f ${pidfile} ]
		then
			echo "Restarting ${name}."
			kill -TERM `cat ${pidfile}`
			sleep 5
			${command} ${nsd_flags}
		else
			echo "${name} not running?"
		fi;;
	esac

	${command} ${nsd_flags}
}

if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	nsd_doit "$1"
fi
