#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: ppcoind
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="ppcoind"
rcvar=$name
command="@PREFIX@/sbin/ppcoind"
pidfile="@VARBASE@/run/ppcoind.pid"
required_directory="@VARBASE@/feathercoin"
command_args="-daemon -conf=@PREFIX@/etc/feathercoin.conf -pid=${pidfile} -datadir=${required_directory}"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${feathercoin_flags} ${command_args}
fi
