#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dovecot.sh,v 1.5 2005/08/19 16:38:26 tvierling Exp $
#

# PROVIDE: dovecot
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="dovecot"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/$name.conf"

load_rc_config $name
run_rc_command "$1"
