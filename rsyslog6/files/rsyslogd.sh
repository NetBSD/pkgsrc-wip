#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: rsyslogd.sh,v 1.1.1.1 2011/04/14 09:44:42 bartoszkuzma Exp $
# NetBSD: syslogd,v 1.15 2004/10/11 13:29:52 lukem Exp
#

# PROVIDE: rsyslogd
# REQUIRE: mountcritremote sysdb wscons
# BEFORE:  SERVERS

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="rsyslogd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/rsyslog.conf"
start_precmd="rsyslogd_precmd"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
