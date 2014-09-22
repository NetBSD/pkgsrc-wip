#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: darkcoind.sh,v 1.1 2014/09/22 11:17:11 othyro Exp $
#

# PROVIDE: darkcoind
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="darkcoind"
rcvar=$name
command="@PREFIX@/sbin/darkcoind"
pidfile="@VARBASE@/run/darkcoind.pid"
required_directory="@VARBASE@/darkcoin"
command_args="-daemon -conf=@PREFIX@/etc/darkcoin.conf -pid=${pidfile} -datadir=${required_directory}"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${darkcoin_flags} ${command_args}
fi
