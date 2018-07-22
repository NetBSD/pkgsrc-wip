#!@RCD_SCRIPTS_SHELL@

# PROVIDE: geomyidae
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="geomyidae"
rcvar=$name
command="@PREFIX@/sbin/geomyidae"
pidfile="@VARBASE@/run/${name}/pid"
start_precmd="geomyidae_precmd"

_geomyidae_user="@GEOMYIDAE_USER@"
_geomyidae_group="@GEOMYIDAE_GROUP@"
_geomyidae_rootdir="@GEOMYIDAE_ROOTDIR@"

command_args="-u \"${_geomyidae_user}\" -g \"${_geomyidae_group}\" -b \"${_geomyidae_rootdir}\""
required_dirs="${_geomyidae_rootdir}"

geomyidae_precmd()
{
	if [ ! -d "@VARBASE@/run/${name}" ]; then
		@MKDIR@ "@VARBASE@/run/${name}"
		@CHMOD@ 0700 "@VARBASE@/run/${name}"
	fi
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	${command} ${command_args} ${geomyidae_flags} 
fi
