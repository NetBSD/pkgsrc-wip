#!@RCD_SCRIPTS_SHELL@
#
# was
# $NetBSD: syslogd.sh,v 1.1 2004/04/09 07:50:33 jeremy-c-reed Exp $
#

# PROVIDE: syslogd
# REQUIRE: mountcritremote
# BEFORE:  SERVERS
# KEYWORD: shutdown

. /etc/rc.subr

name="syslogd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/syslog.conf"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
