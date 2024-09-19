#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: primed
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="primed"
rcvar=$name
command="@PREFIX@/sbin/primed"
pidfile="@VARBASE@/run/primed.pid"
required_directory="@VARBASE@/primecoin"
command_args="-daemon -conf=@PREFIX@/etc/primecoin.conf -pid=${pidfile} -datadir=${required_directory}"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${primecoin_flags} ${command_args}
fi
