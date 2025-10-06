#!@RCD_SCRIPTS_SHELL@
#
# PROVIDE: wendzelnntpd
# REQUIRE: DAEMON

if [ -f @SYSCONFBASE@/rc.subr ]; then
	. @SYSCONFBASE@/rc.subr
fi

name="wendzelnntpd"
rcvar="${name}"
command="@PREFIX@/sbin/wendzelnntpd"
command_args="-d"
required_files="@PKG_SYSCONFDIR@/wendzelnntpd/wendzelnntpd.conf"

load_rc_config $name
run_rc_command "$1"
