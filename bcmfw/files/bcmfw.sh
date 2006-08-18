#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: bcmfw.sh,v 1.1.1.1 2006/08/18 19:15:48 plunky Exp $
#

# PROVIDE: bcmfw
# REQUIRE: mountall
# BEFORE:  bluetooth

$_rc_subr_loaded . /etc/rc.subr

name="bcmfw"
rcvar=${name}
command="@PREFIX@/bin/${name}"
command_args="${bcmfw_args:-ugen0}"

load_rc_config ${name}
run_rc_command "$1"
