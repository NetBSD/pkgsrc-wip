#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: haproxy.sh,v 1.1.1.1 2011/10/31 23:34:07 morr Exp $
#

# PROVIDE: haproxy
# REQUIRE: network

$_rc_subr_loaded . /etc/rc.subr

name="haproxy"
rcvar=$name
command="/usr/pkg/sbin/${name}"
conf_file="/usr/pkg/etc/${name}.cfg"
required_files="${conf_file}"
command_args="-f $conf_file"
pid_file="/var/run/haproxy-private.pid"
extra_commands="reload"

haproxy_reload()
{
        ${command} -f ${conf_file} -p ${pid_file} -sf $(cat ${pid_file})
}

load_rc_config $name
run_rc_command "$1"
