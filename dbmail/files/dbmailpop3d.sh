#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbmailpop3d.sh,v 1.4 2013/03/13 21:33:01 tnn2 Exp $
#

# PROVIDE: dbmailpop3 mail
# REQUIRE: 

. /etc/rc.subr

name="dbmailpop3d"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/dbmail.conf"
command="@PREFIX@/sbin/dbmail-pop3d"
pidfile="@VARBASE@/run/dbmail-pop3d.pid"

load_rc_config $name
run_rc_command "$1"
