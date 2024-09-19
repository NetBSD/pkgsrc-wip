#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: quarkcoind
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="quarkcoind"
rcvar=$name
command="@PREFIX@/sbin/quarkcoind"
pidfile="@VARBASE@/run/quarkcoind.pid"
required_directory="@VARBASE@/quarkcoin"
command_args="-daemon -conf=@PREFIX@/etc/quarkcoin.conf -pid=${pidfile} -datadir=${required_directory}"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${quarkcoin_flags} ${command_args}
fi
