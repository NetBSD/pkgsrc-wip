#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pflogd.sh,v 1.1 2004/06/09 09:47:14 ppostma Exp $
#
# PROVIDE: pflogd
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="pflogd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
start_precmd="/sbin/ifconfig pflog0 up"

load_rc_config $name
run_rc_command "$1"
