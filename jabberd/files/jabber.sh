#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: jabber.sh,v 1.1.1.1 2003/05/09 18:44:35 xtraeme Exp $
#

# PROVIDE: jabberd
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="jabberd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/jabber.xml"

load_rc_config $name
run_rc_command "$1"
