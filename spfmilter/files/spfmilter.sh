#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: spfmilter.sh,v 1.1.1.1 2004/09/01 16:02:12 adrian_p Exp $
#
# PROVIDE: spfmilter
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="spfmilter"
rcvar=$name
command="@PREFIX@/bin/$name"
pidfile="/var/run/$name.pid"
command_args="-t -p ${pidfile}"

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${spfmilter_flags} ${command_args}
fi
