#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: bitlbee.sh,v 1.1.1.1 2003/06/25 15:35:55 xtraeme Exp $
#

# PROVIDE: bitlbee
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="bitlbee"
rcvar=$name
command="@PREFIX@/sbin/${name}"
command_args="-d"
bitlbee_user="bitlbee"

load_rc_config $name
run_rc_command "$1"
