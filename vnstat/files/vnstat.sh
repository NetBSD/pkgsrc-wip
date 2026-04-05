#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: vnstat
# REQUIRE: network mountcritlocal

$_rc_subr_loaded . /etc/rc.subr

name="vnstat"
rcvar=$name
command="@PREFIX@/sbin/${name}d"
pidfile="/var/run/${name}/${name}.pid"
command_args="-d"
required_files="@PKG_SYSCONFDIR@/${name}.conf"

load_rc_config $name
run_rc_command "$1"
