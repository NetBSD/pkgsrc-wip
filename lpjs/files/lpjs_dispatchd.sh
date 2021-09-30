#!@RCD_SCRIPTS_SHELL@
# $NetBSD: lpjs_dispatchd.sh,v 1.1 2018/04/22 21:31:09 bacon Exp $
#
# PROVIDE: lpjs_dispatchd
# REQUIRE: DAEMON munge
# KEYWORD: shutdown

. /etc/rc.subr

name="lpjs_dispatchd"
rcvar=${name}
command="@PREFIX@/sbin/lpjs_dispatchd"

load_rc_config $name
run_rc_command "$1"
