#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbmailimapd.sh,v 1.4 2013/03/13 21:33:00 tnn2 Exp $
#

# PROVIDE: dbmailimap mail
# REQUIRE: 

. /etc/rc.subr

name="dbmailimapd"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/dbmail.conf"
command="@PREFIX@/sbin/dbmail-imapd"
pidfile="@VARBASE@/run/dbmail-imapd.pid"

load_rc_config $name
run_rc_command "$1"
