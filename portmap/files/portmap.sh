#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: portmap.sh,v 1.1 2004/01/04 02:34:04 jeremy-c-reed Exp $
#

# PROVIDE: portmap
# REQUIRE: NETWORKING ntpdate syslogd named ppp

. /etc/rc.subr

name="portmap"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"
