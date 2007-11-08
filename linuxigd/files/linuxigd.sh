#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: linuxigd.sh,v 1.4 2007/11/08 05:09:33 obache Exp $
#
# PROVIDE: linuxidg
# REQUIRE: ipnat
# KEYWORD: shutdown
#
# set linuxigd_flags="ext_if int_if" in rc.conf

. /etc/rc.subr

name="linuxigd"
rcvar=${name}
command="@PREFIX@/sbin/upnpd"
required_vars="ipnat"

load_rc_config ${name}
run_rc_command "$1"
