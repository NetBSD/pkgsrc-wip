#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nagios.sh,v 1.3 2006/01/03 10:26:21 absd Exp $
#
# PROVIDE: nagios
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="nagios"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="@VARBASE@/run/${name}/${name}.lock"
start_precmd="nagios_make_rundir"
config="@PKG_SYSCONFDIR@/${name}.cfg"

command_args="-d $config"
 
test_cmd="nagios_test"
extra_commands="test"

nagios_make_rundir()
{   
        mkdir -p "@VARBASE@/var/run/${name}"
	chown @NAGIOSADM_USER@:@NAGIOSADM_GROUP@ "@VARBASE@/var/run/${name}/rw"
}

nagios_test()
{
	$command -v $config
}

load_rc_config $name
run_rc_command "$1"
