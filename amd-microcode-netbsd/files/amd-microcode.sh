#!@RCD_SCRIPTS_SHELL@

# PROVIDE: microcode
# REQUIRE: mountall
#
# attempts microcode update on all CPU cores (for AMD x86)
#

$_rc_subr_loaded . /etc/rc.subr

name=microcode
rcvar=$name
start_cmd="microcode_start"
stop_cmd=":"

microcode_start()
{
	/usr/sbin/cpuctl ucode || true
}

load_rc_config $name
run_rc_command "$1"
