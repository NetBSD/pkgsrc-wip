#!@RCD_SCRIPTS_SHELL@
#
#	$NetBSD: bird.sh,v 1.3 2013/11/14 14:01:10 kralian Exp $
#
# PROVIDE: bird
# REQUIRE: DAEMON NETWORKING

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="bird"
rcvar="${name}"
command="@PREFIX@/sbin/${name}"

load_rc_config $name
run_rc_command "$1"
