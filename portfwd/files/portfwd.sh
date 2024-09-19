#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: portfwd.sh,v 1.1 2015/06/28 01:33:35 mbowie Exp $
#

# PROVIDE: portfwd
# REQUIRE: NETWORK
# KEYWORD: shutdown

$_rc_subr_loaded . /etc/rc.subr

name="portfwd"
rcvar=$name
portfwd_config="@PREFIX@/etc/${name}.conf"
command="@PREFIX@/sbin/${name}"
command_args="-c ${portfwd_config}"
required_files="${portfwd_config}"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
