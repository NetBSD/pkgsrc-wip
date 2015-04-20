#!@RCD_SCRIPTS_SHELL@
# $NetBSD: slurmd.sh,v 1.2 2015/04/20 13:08:37 outpaddling Exp $
#
# PROVIDE: slurmd
# REQUIRE: DAEMON munge
# KEYWORD: shutdown

. /etc/rc.subr

name="slurmd"
rcvar=${name}
command="@PREFIX@/sbin/slurmd"

slurmd_user="root"

load_rc_config $name
run_rc_command "$1"
