#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: zetacoind
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="zetacoind"
rcvar=$name
command="@PREFIX@/sbin/zetacoind"
pidfile="@VARBASE@/run/zetacoind.pid"
required_directory="@VARBASE@/zetacoin"
command_args="-daemon -conf=@PREFIX@/etc/zetacoin.conf -pid=${pidfile} -datadir=${required_directory}"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${zetacoin_flags} ${command_args}
fi
