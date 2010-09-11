#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: multiskkserv.sh,v 1.2 2010/09/11 08:32:12 obache Exp $
#
# PROVIDE: multiskkserv
# REQUIRE: DAEMON

. /etc/rc.subr
 
name="multiskkserv"
rcvar=$name
command="@PREFIX@/sbin/${name}"

multiskkserv_flags="@SKKJISYOCDBDIR@/share/skk/SKK-JISYO.L.cdb &"

load_rc_config $name
run_rc_command "$1"
