#!@RCD_SCRIPTS_SHELL@
#
#
#
# PROVIDE: mackerelagent
# REQUIRE: DAEMON
#
# Add the following lines to /etc/rc.conf to enable this service:
#
# mackerelagent=YES

. /etc/rc.subr

name="mackerelagent"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
config="@PKG_SYSCONFDIR@/${name}.conf"
rootdir="@VARBASE@/lib/${name}"
command_args="supervise -conf=${config} -pidfile=${pidfile} -root=${rootdir} &"
mackerelagent_env="PATH=$PATH:@PREFIX@/bin:@PREFIX@/libexec/${name}"

load_rc_config ${name}
run_rc_command "$1"
