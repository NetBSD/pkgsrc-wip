#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: jabberd.sh,v 1.1.1.1 2003/06/12 04:01:38 xtraeme Exp $
#

# PROVIDE: jabberd
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="jabberd"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="/var/run/${help_name}.pid"
required_files="@PKG_SYSCONFDIR@/jabber.cfg"

load_rc_config $name
run_rc_command "$1"
