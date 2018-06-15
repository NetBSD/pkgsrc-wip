#!@RCD_SCRIPTS_SHELL@
#
# maybe this should start after syslogd ??

# PROVIDE: klogd
# REQUIRE: syslogd
# BEFORE: nonlocalswap
# KEYWORD: shutdown

. /etc/rc.subr

name="klogd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"
