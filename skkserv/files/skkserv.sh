#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: skkserv.sh,v 1.1.1.1 2010/07/16 10:49:01 ryo-on Exp $
#
# PROVIDE: skkserv
# REQUIRE: DAEMON

. /etc/rc.subr
 
name="skkserv"
rcvar=$name
command="@PREFIX@/libexec/${name}"

load_rc_config $name
run_rc_command "$1"
