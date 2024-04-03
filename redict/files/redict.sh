#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: redict
# REQUIRE: DAEMON NETWORKING
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="redict"
rcvar=$name
command="@PREFIX@/bin/redict-server"
redict_user="@REDICT_USER@"
redict_flags="@PKG_SYSCONFDIR@/redict.conf"

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	@SU@ -m ${redict_user} -c "${command}"
fi
