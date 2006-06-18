#!@RCD_SCRIPTS_SHELL@
#
# PROVIDE: boinc
# REQUIRE: LOGIN

. /etc/rc.subr

name="boinc"
rcvar=$name
boinc_user="@BOINC_USER@"
boinc_group="@BOINC_GROUP@"
boinc_flags="-daemon"
boinc_command="/usr/pkg/bin/boinc_client"
start_precmd="boinc_precmd"
start_cmd="boinc_start"
stop_cmd="boinc_stop"
required_dirs="@BOINC_DIR@"
pidfile="/var/run/$name.pid"

boinc_precmd()
{
	mkdir -p $required_dirs
	chgrp $boinc_group $required_dirs
	chmod 775 $required_dirs
}

boinc_start()
{
	if [ ! -d "$required_dirs" ]; then
		warn "$required_dirs is not a directory."
		if [ -z $rc_force ]; then
			return 1
		fi
	fi
	if [ ! -r "$required_dirs" ]; then
		warn "$required_dirs is not readable."
		if [ -z $rc_force ]; then
			return 1
		fi
	fi
	pid=`cat $pidfile`
  	if test -n "`ps ax | awk '/$pid/ { if ($1 == $pid) print $0 }'`"
	then
		return 3
	fi
	#daemon -p $pidfile chroot -u $boinc_user -g $boinc_group $required_dirs ${boinc_command} ${rc_flags}
	su - $boinc_user -c "cd $required_dirs && ${boinc_command} ${rc_flags} &"
	echo $! > $pidfile
}

boinc_stop()
{
	killall boinc_client
	return 0
	if [ -r "$pidfile" ]; then
		kill `cat $pidfile`
	fi
}

load_rc_config $name
run_rc_command "$1"
