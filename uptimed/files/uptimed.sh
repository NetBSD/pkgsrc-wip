#!/bin/sh
#
# $NetBSD: uptimed.sh,v 1.1.1.1 2007/02/27 22:54:17 dzoe Exp $
#
# PROVIDE: uptimed
# REQUIRE: DAEMON

. /etc/rc.subr

name="uptimed"
rcvar=$name
command="/usr/pkg/sbin/${name}"
conf_file="/usr/pkg/etc/${name}.conf"
required_files="${conf_file}"
extra_commands=""
command_args=""

load_rc_config $name
run_rc_command $1
