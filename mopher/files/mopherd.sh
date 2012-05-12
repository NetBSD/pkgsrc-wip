#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mopherd.sh,v 1.1.1.1 2012/05/12 13:29:06 pebog Exp $
#
# PROVIDE: mopherd
# REQUIRE: DAEMON
# BEFORE:  mail

$_rc_subr_loaded . /etc/rc.subr

name=mopherd
rcvar=$name
pidfile=@VARBASE@/run/$name.pid
command=@PREFIX@/sbin/$name
command_args="-p $pidfile"

load_rc_config $name
run_rc_command "$1"
