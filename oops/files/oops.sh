#!@RCD_SCRIPTS_SHELL@
#
#	$NetBSD: oops.sh,v 1.3 2011/04/12 20:40:34 shattered Exp $
#
# PROVIDE: oops
# REQUIRE: DAEMON

. /etc/rc.subr

name="oops"                      
rcvar=$name         
command="@PREFIX@/sbin/${name}"
ctl_command="@PREFIX@/sbin/${name}ctl"
pidfile="/var/run/${name}/${name}.pid"
required_files="@PREFIX@/etc/oops/oops.cfg"
extra_commands="reload graceful"
start_cmd=oops_start
stop_cmd=oops_stop
reload_cmd=oops_reload
graceful_cmd=oops_graceful

export PTHREAD_DIAGASSERT=AEl 

oops_start () {
	if [ ! -d /var/run/${name} ]; then
		mkdir /var/run/${name}
		chown oops /var/run/${name}
	fi
	$ctl_command start
}

oops_stop () {
	$ctl_command stop
}

oops_reload () {
	$ctl_command reconfigure
}

oops_graceful () {
	$ctl_command graceful
}
              
load_rc_config $name
run_rc_command "$1"
