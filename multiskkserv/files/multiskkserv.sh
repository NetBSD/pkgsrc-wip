#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: multiskkserv.sh,v 1.1.1.1 2010/08/18 10:23:12 ryo-on Exp $
#
# PROVIDE: multiskkserv
# REQUIRE: DAEMON

. /etc/rc.subr
 
name="multiskkserv"
rcvar=$name
command="@PREFIX@/sbin/${name}"

multiskkserv_flags="@PREFIX@/share/skk/SKK-JISYO.L.cdb &"

load_rc_config $name
run_rc_command "$1"
