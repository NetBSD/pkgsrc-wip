#!@RCS_SCRIPTS_SHELL@
#
# $NetBSD: cherokee.sh,v 1.3 2003/07/14 17:55:30 xtraeme Exp $
#

# PROVIDE: cherokee
# REQUIRE: DAEMON

. /etc/rc.subr

name="cherokee"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/$name.conf"

load_rc_config $name
run_rc_command "$1"
