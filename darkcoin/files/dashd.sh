#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: dashd
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="dashd"
rcvar=$name
command="@PREFIX@/sbin/dashd"
pidfile="@VARBASE@/run/dashd.pid"
required_directory="@VARBASE@/dash"
command_args="-daemon -conf=@PREFIX@/etc/dash.conf -pid=${pidfile} -datadir=${required_directory}"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${dash_flags} ${command_args}
fi
