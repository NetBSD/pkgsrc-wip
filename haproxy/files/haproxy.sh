#!/bin/sh
#
# $NetBSD: haproxy.sh,v 1.1.1.1 2009/08/12 20:03:07 shindenmorr Exp $
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

load_rc_config $name
run_rc_command "$1"
