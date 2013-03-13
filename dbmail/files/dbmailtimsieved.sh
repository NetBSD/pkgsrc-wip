#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbmailtimsieved.sh,v 1.4 2013/03/13 21:33:01 tnn2 Exp $
#

# PROVIDE: dbmailtimsieved mail
# REQUIRE: 

. /etc/rc.subr

name="dbmailtimsieved"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/dbmail.conf"
command="@PREFIX@/sbin/dbmail-timsieved"
pidfile="@VARBASE@/run/dbmail-timsieved.pid"

load_rc_config $name
run_rc_command "$1"
