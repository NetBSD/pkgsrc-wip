#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: jabberd.sh,v 1.3 2003/07/14 17:03:48 xtraeme Exp $
#

# PROVIDE: jabberd
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="jabberd"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="/var/run/${help_name}.pid"
required_files="@PKG_SYSCONFDIR@/jabberd.cfg"
jabberd_user="jabberd"
jabberd_group="jabberd"

load_rc_config $name
run_rc_command "$1"
