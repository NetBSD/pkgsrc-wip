#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: dogecoind
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="dogecoind"
rcvar=$name
command="@PREFIX@/sbin/dogecoind"
pidfile="@VARBASE@/run/dogecoind.pid"
required_directory="@VARBASE@/dogecoin"
command_args="-daemon -conf=@PREFIX@/etc/dogecoin.conf -pid=${pidfile} -datadir=${required_directory}"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${dogecoin_flags} ${command_args}
fi
