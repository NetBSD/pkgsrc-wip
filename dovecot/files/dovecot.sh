#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dovecot.sh,v 1.2 2003/05/06 21:13:27 lsed Exp $
#

# PROVIDE: dovecot
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="dovecot"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/$name.conf"

load_rc_config $name
run_rc_command "$1"
