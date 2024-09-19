#!@RCD_SCRIPTS_SHELL@
#

# PROVIDE: bindgraph
# REQUIRE: DAEMON

$_rc_subr_loaded . /etc/rc.subr

name="@PKGBASE@"
rcvar=${name}
command_interpreter="@PERL5@"
command="@PREFIX@/sbin/bindgraph"
command_args="--daemon ${bindgraph_flags}"

load_rc_config $name
run_rc_command "$1"
