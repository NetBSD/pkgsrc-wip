#!@RCD_SCRIPTS_SHELL@
# $NetBSD: slurmd.sh,v 1.1 2015/03/27 20:09:56 outpaddling Exp $
#
# PROVIDE: slurmd
# REQUIRE: DAEMON munge
# KEYWORD: shutdown

. /etc/rc.subr

name="slurmd"
rcvar=${name}
command="@PREFIX@/sbin/slurmd"

slurmd_user="slurm"

load_rc_config $name
run_rc_command "$1"
