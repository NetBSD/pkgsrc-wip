#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dovecot.sh,v 1.3 2003/05/13 04:16:28 lsed Exp $
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
