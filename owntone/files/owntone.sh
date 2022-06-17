#!/bin/sh
 
# PROVIDE: owntone
# REQUIRE: avahidaemon dbus
 
# Add the following lines to /etc/rc.conf to enable `owntone':
#
# owntone_enable="YES"
# owntone_flags="<set as needed>"
 
. /etc/rc.subr
 
name="owntone"
rcvar=$name
 
command="/usr/pkg/sbin/owntone"
command_args="-P /var/run/owntone.pid"
pidfile="/var/run/owntone.pid"
required_files="/usr/pkg/etc/owntone.conf"
 
# read configuration and set defaults
load_rc_config "$name"
: ${owntone_enable="NO"}
 
run_rc_command "$1"
