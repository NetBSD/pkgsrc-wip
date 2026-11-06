#!/bin/sh
#
# $NetBSD: trafficserver,v 1.6 2020/09/08 12:52:18 martin Exp $
#

# PROVIDE: trafficserver
# REQUIRE: network CRITLOCALMOUNTED staticroute
# BEFORE:  NETWORKING

$_rc_subr_loaded . /etc/rc.subr

name="trafficserver"
rcvar=$name
pidfile="/var/run/trafficserver/${name}.pid"
start_cmd="/usr/pkg/sbin/daemonize -p /var/run/trafficserver/trafficserver.pid /usr/pkg/bin/traffic_server"
start_precmd="trafficserver_prestart"
command="/usr/pkg/bin/traffic_server"

trafficserver_prestart() {
	if [ ! -e  /var/run/trafficserver ]; then
		mkdir /var/run/trafficserver
	fi
}

load_rc_config $name
run_rc_command "$1"
