#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dansguardian.sh,v 1.1.1.1 2004/03/27 22:49:31 xtraeme Exp $
#
# PROVIDE: dansguardian
# REQUIRE: DAEMON LOGIN
# KEYWORD: shutdown

. /etc/rc.subr

name="dansguardian"
rcvar=$name
command="/usr/pkg/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/etc/${name}/${name}.conf"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
