#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: jabberd.sh,v 1.1 2003/06/05 14:03:28 xtraeme Exp $
#

# PROVIDE: jabberd
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="jabberd"
help_name="jabber"
rcvar=$name
command="@PREFIX@/sbin/${name}"
command_args="-B -H /var/spool/jabberd -c \$required_files"
pidfile="/var/run/${help_name}.pid"
required_files="@PKG_SYSCONFDIR@/jabber.xml"

load_rc_config $name
run_rc_command "$1"
