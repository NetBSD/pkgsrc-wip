#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbmaillmtpd.sh,v 1.2 2007/10/27 15:35:43 obache Exp $
#

# PROVIDE: dbmaillmtp mail
# REQUIRE: 

. /etc/rc.subr

name="dbmaillmtpd"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/dbmail.conf"
command="@PREFIX@/sbin/dbmail-lmtpd"
pidfile="@VARBASE@/run/dbmail-lmtpd.pid"

load_rc_config $name
run_rc_command "$1"
