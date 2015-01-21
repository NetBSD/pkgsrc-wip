#!/bin/sh

# REQUIRE: DAEMON
# PROVIDE: zabbix_proxy

. /etc/rc.subr

name="zabbix_proxy"
rcvar=${name}
command="${prefix:-"/usr/pkg"}/sbin/${name}"

load_rc_config ${name}
run_rc_command "$1"
