#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: jabberd.sh,v 1.4 2003/09/28 18:13:51 xtraeme Exp $
#

# PROVIDE: jabberd
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="jabberd"
rcvar=$name
command="@PREFIX@/bin/${name}"
command_args="-D"
required_files="@PKG_SYSCONFDIR@/jabberd.cfg"
jabberd_user="jabberd"
jabberd_group="jabberd"

load_rc_config $name
run_rc_command "$1"
