#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: linuxigd.sh,v 1.1.1.1 2005/03/13 12:48:22 obache Exp $
#
# PROVIDE: linuxidg
# REQUIRE: ipnat
#
# set linuxigd_flags="ext_if int_if" in rc.conf

. /etc/rc.subr

name="linuxigd"
rcvar=${name}
command="@PREFIX@/bin/upnpd"
required_vars="ipnat"

start_precmd="route_add_cmd"
stop_postcmd="route_del_cmd"

route_add_cmd()
{
	if [ ! -z "$linuxigd_intaddr" ]; then
		route add -net 239.0.0.0 -netmask 255.0.0.0 ${linuxigd_intaddr}
	fi
}

route_del_cmd()
{
	if [ ! -z "$linuxigd_intaddr" ]; then
		route delete -net 239.0.0.0 -netmask 255.0.0.0 ${linuxigd_intaddr}
	fi
}

load_rc_config ${name}
run_rc_command "$1"
