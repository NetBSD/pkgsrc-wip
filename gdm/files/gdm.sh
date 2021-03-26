#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: gdm.sh,v 1.4 2015/06/06 00:53:44 krytarowski Exp $
#

# PROVIDE: gdm
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="gdm"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
command_args="&"
pidfile="/var/run/gdm/${name}.pid"
procname="@PREFIX@/sbin/gdm"
required_files="@PKG_SYSCONFDIR@/custom.conf"
extra_commands="reload"

if [ -f /etc/rc.subr ]; then
	load_rc_config ${name}
	PATH=@PREFIX@/bin:$PATH run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${gdm_flags} ${command_args}
fi
