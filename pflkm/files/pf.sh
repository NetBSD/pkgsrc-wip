#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pf.sh,v 1.1 2004/06/09 09:47:14 ppostma Exp $
#
# PROVIDE: pf
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="pf"
rcvar=$name
command="@PREFIX@/sbin/pfctl"
config="@PREFIX@/etc/pf.conf"
start_cmd="${command} -e -f ${config}"
stop_cmd="${command} -d"
status_cmd="${command} -s info"

load_rc_config $name
run_rc_command "$1"
