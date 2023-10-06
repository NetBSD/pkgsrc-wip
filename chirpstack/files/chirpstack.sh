#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: chirpstack
# REQUIRE: DAEMON
#
# Consider installing pkgtools/rc.subr in unprivileged.
#
# You will need to set some variables in @SYSCONFBASE@/rc.conf to start syncthing:
#
# chirpstack=YES

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="chirpstack"
rcvar=${name}
pidfile="@VARBASE@/run/${name}.pid"

command="@PREFIX@/bin/${name}"
command_args="--config @PKG_SYSCONFDIR@ > /dev/null 2>&1 &"

start_postcmd="chirpstack_postcmd"

chirpstack_postcmd()
{
	mkdir -p @VARBASE@/run
	echo $! > ${pidfile}
}

load_rc_config $name
run_rc_command "$1"
