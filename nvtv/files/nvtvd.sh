#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nvtvd.sh,v 1.2 2003/06/07 17:50:21 cubidou Exp $
#

# PROVIDE: nvtvd
# REQUIRE: DAEMON

. /etc/rc.subr

name="nvtvd"
rcvar=$name
command="@PREFIX@/bin/nvtvd"

load_rc_config $name
run_rc_command "$1"
