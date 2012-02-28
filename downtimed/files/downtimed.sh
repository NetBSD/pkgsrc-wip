#! /bin/sh

# REQUIRE: DAEMON

. /etc/rc.subr

name=downtimed
rcvar=downtimed
command=/usr/pkg/sbin/downtimed

load_rc_config downtimed
run_rc_command "$1"
