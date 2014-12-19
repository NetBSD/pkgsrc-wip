#!/bin/sh

# REQUIRE: DAEMON
# PROVIDE: zabbix_agentd

. /etc/rc.subr

name="zabbix_agentd"
rcvar=${name}
command="${prefix:-"/usr/pkg"}/sbin/${name}"

load_rc_config ${name}
run_rc_command "$1"
