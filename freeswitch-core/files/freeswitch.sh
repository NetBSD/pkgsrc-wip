#!/bin/sh
#
# PROVIDE: freeswitch
# REQUIRE: LOGIN cleanvar
# KEYWORD: shutdown
#
# Add the following lines to /etc/rc.conf to enable freeswitch:
# freeswitch_enable:       Set it to "YES" to enable freeswitch.
#                          Default is "NO".
# freeswitch_flags:        Flags passed to freeswitch-script on startup.
#                          Default is "".
#
. /etc/rc.subr
name="freeswitch"
rcvar=${name}
load_rc_config $name
: ${freeswitch="NO"}
: ${freeswitch_pidfile="${VARBASE}/run/freeswitch/freeswitch.pid"}
start_cmd=${name}_start
stop_cmd=${name}_stop
pidfile=${freeswitch_pidfile}
freeswitch_start() {
       /usr/pkg/bin/freeswitch ${freeswitch_flags}
       echo -n "Starting FreeSWITCH: "
}
freeswitch_stop() {
       /usr/pkg//bin/freeswitch -stop
}
run_rc_command "$1"

