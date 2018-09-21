#!@RCD_SCRIPTS_SHELL@

# PROVIDE: miniircd
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="miniircd"
rcvar=$name
command="@PREFIX@/sbin/miniircd"
command_interpreter="@PYTHONBIN@"
pidfile="@VARBASE@/run/${name}/pid"
command_args="-d --pid-file=${pidfile}"
start_precmd="miniircd_precmd"
stop_postcmd="miniircd_postcmd"

miniircd_flags=${miniircd_flags-"--setuid @MINIIRCD_USER@:@MINIIRCD_GROUP@"}

miniircd_precmd()
{
	if [ ! -d "@VARBASE@/run/${name}" ]; then
		@MKDIR@ "@VARBASE@/run/${name}"
		@CHMOD@ 0700 "@VARBASE@/run/${name}"
		@CHOWN@ @MINIIRCD_USER@:@MINIIRCD_GROUP@ "@VARBASE@/run/${name}"
	fi
}

miniircd_postcmd()
{
	@RM@ "${pidfile}"
}

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	${command} ${miniircd_flags} ${command_args} 
fi
