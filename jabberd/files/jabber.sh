#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: jabber.sh,v 1.2 2003/05/12 13:13:23 xtraeme Exp $
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
