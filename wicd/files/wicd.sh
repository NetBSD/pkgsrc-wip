#!/bin/sh

prog="$0"
arg="$1"
name="wicd"
wicd="/usr/pkg/sbin/wicd"
wired_conf="/usr/pkg/etc/wicd/wired-settings.conf"
pidfile="/var/run/wicd/wicd.pid"

if [ ! -x ${wicd} ]; then
	echo "${wicd} not found..."
	exit 2
fi

case $arg in
	start)
		if ps aux | grep -q [w]icd-daemon.py; then
			echo $name 'is running, you need to stop it first!'
			echo "Ex: $prog stop"
			exit 1
		fi
		# fix bug
        	if [ -f $wired_conf ]; then
                	sed -i 's/^\[\]$//' $wired_conf
        	fi
		echo "Starting ${name}."
		${wicd}
		;;
	stop)
		echo "Stopping ${name}."
		if [ -s $pidfile ]; then
			kill $(cat $pidfile) 2>/dev/null
			rm -f $pidfile  2>/dev/null
		else
			pkill -f python.*wicd-daemon.py 2>/dev/null
			killall wicd-client 2>/dev/null
		fi
		;;
	restart)
		$prog stop
		sleep 5
		$prog start
		;;
	*)
		echo "Usage: $0 {start|stop|restart}"
    		exit 1
		;;
esac
