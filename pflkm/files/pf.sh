#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pf.sh,v 1.4 2004/06/18 14:38:05 ppostma Exp $
#
# PROVIDE: pf
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="pf"
rcvar=$name
command="@PREFIX@/sbin/pfctl"
config="@PKG_SYSCONFDIR@/pf.conf"
start_cmd="${command} -e -f ${config}"
stop_cmd="${command} -d"
status_cmd="${command} -s info"
reload_cmd="${command} -f ${config}"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
