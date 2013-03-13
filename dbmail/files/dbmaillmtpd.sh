#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbmaillmtpd.sh,v 1.4 2013/03/13 21:33:00 tnn2 Exp $
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
