#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: gkrellmd.sh,v 1.1.1.1 2003/04/03 15:09:28 cubidou Exp $
#

# PROVIDE: gkrellmd
# REQUIRE: DAEMON

. /etc/rc.subr

name="gkrellmd"
rcvar=$name
command="@PREFIX@/bin/gkrellmd"
gkrellmd_flags="-d"

load_rc_config $name
run_rc_command "$1"
