#!@RCD_SCRIPTS_SHELL@
#
#	$NetBSD: exim.sh,v 1.2 2003/11/30 03:25:14 grantbeattie Exp $
#
# PROVIDE: mail
# REQUIRE: LOGIN

. /etc/rc.subr

name="exim"                      
exim_flags=${exim_flags-"-bd -q30m"}
rcvar=$name         
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PREFIX@/etc/exim/configure"
              
load_rc_config $name
run_rc_command "$1"
