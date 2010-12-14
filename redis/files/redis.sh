#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: redis.sh,v 1.2 2010/12/14 13:31:05 fhajny Exp $
#
# PROVIDE: redis 
# REQUIRE: DAEMON network
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="redis"
rcvar=$name
command="@PREFIX@/bin/redis-server"
redis_user="@REDIS_USER@"
command_args="@PKG_SYSCONFDIR@/${name}.conf"

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	@SU@ -m ${redis_user} -c "${command} ${command_args}"
fi
