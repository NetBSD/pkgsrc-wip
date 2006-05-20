#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mt_daapd.sh,v 1.1.1.1 2006/05/20 18:42:28 airhead Exp $
#

# PROVIDE: mt_daapd
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="mt_daapd"
rcvar=$name
command="@PREFIX@/sbin/mt-daapd"
required_files="@PKG_SYSCONFDIR@/mt-daapd.conf"
command_args="</dev/null >/dev/null 2>&1 &"

load_rc_config $name
run_rc_command "$1"
