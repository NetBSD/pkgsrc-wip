#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD
#

# PROVIDE: pts
# REQUIRE: DAEMON LOGIN network

. /etc/rc.subr

name="pts"
rcvar=$name
procname="perl:"
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PREFIX@/share/pts/pts.ini"

load_rc_config $name
run_rc_command "$1"
