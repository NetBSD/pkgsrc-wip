#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: jabberd.sh,v 1.4 2003/10/08 00:17:29 xtraeme Exp $
#

# PROVIDE: jabberd
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="jabberd"
help_name="jabber"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/jabber.xml"
command_args="-B -H @JABBERD_SPOOLDIR@ -c $required_files"
pidfile="@JABBERD_PIDDIR@/${help_name}.pid"
jabberd_user="@JABBERD_USER@"
jabberd_group="@JABBERD_GROUP@"

load_rc_config $name
run_rc_command "$1"
