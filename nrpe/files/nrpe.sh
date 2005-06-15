#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nrpe.sh,v 1.1.1.1 2005/06/15 06:23:26 ura Exp $
#
# PROVIDE: nrpe
# REQUIRE: DAEMON
# KEYWORD: shutdown

# To start nrpe at startup, copy this script to /etc/rc.d and set
# nrpe="YES" in /etc/rc.conf.

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name=nrpe
rcvar=$name
command="@PREFIX@/sbin/nrpe"
required_files="@PREFIX@/etc/nagios/nrpe.cfg"
command_args="-c ${required_files} -d"
pidfile="@VARBASE@/run/${name}.pid"

load_rc_config ${name}
run_rc_command "$1"
