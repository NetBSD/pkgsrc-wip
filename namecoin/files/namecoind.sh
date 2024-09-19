#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: namecoind
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

if [ -f @SYSCONFBASE@/rc.subr ]; then
	. @SYSCONFBASE@/rc.subr
fi

name="namecoind"
rcvar=$name
command="@PREFIX@/bin/namecoind"
pidfile="@VARBASE@/run/namecoind.pid"
required_directory="@VARBASE@/namecoin"
command_args="-daemon -conf=@PREFIX@/etc/namecoin.conf -pid=${pidfile} -datadir=${required_directory}"

if [ -f @SYSCONFBASE@/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${namecoin_flags} ${command_args}
fi
