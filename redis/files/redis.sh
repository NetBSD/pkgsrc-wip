#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: redis.sh,v 1.1.1.1 2010/12/05 17:24:18 zatmania Exp $
#
# PROVIDE: redis 
# REQUIRE: DAEMON network
# KEYWORD: shutdown

. /etc/rc.subr

name="redis"
rcvar=$name
command="@PREFIX@/bin/redis-server"
command_args="@PKG_SYSCONFDIR@/${name}.conf"

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	${command} ${command_args}
fi
