#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nvtvd.sh,v 1.1 2003/05/03 11:20:39 cubidou Exp $
#

# PROVIDE: nvtvd
# REQUIRE: DAEMON

. /etc/rc.subr

name="nvtvd"
rcvar=$name
command="@PREFIX@/sbin/nvtvd"

load_rc_config $name
run_rc_command "$1"
