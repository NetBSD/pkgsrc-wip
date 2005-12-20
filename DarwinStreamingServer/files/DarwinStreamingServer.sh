#!/bin/sh
#
#
# PROVIDE: cupsd
# REQUIRE: DAEMON
#
# You will need to set some variables in /etc/rc.conf to start cupsd:
#
# DarwinStreamingServer=YES

if [ -f /etc/rc.subr ]; then
    . /etc/rc.subr
fi

name="DarwinStreamingServer"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
command_args="& sleep 2"
pidfile="/var/run/QuickTimeStreamingServer.pid"

if [ -f /etc/rc.subr ]; then
    load_rc_config $name
    run_rc_command "$1"
else
    echo -n " ${name}"
    ${command} ${command_args}
fi
