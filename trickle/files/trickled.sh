#!@RCS_SCRIPTS_SHELL@
# $Id: trickled.sh,v 1.3 2003/07/14 17:45:57 xtraeme Exp $
# $NetBSD: trickled.sh,v 1.3 2003/07/14 17:45:57 xtraeme Exp $
#

# PROVIDE: trickled
# REQUIRE: DAEMON

. /etc/rc.subr

name="trickled"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/trickled.conf"

load_rc_config $name
run_rc_command "$1"
