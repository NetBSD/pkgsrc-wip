#!@RCD_SCRIPTS_SHELL@
# $NetBSD: lpjs_compd.sh,v 1.1 2018/04/22 21:31:09 bacon Exp $
#
# PROVIDE: lpjs_compd
# REQUIRE: DAEMON munge
# KEYWORD: shutdown

. /etc/rc.subr

name="lpjs_compd"
rcvar=${name}
command="@PREFIX@/sbin/lpjs_compd"

lpjs_compd_user="root"

load_rc_config $name
run_rc_command "$1"
