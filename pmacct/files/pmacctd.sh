#!/bin/sh
#
# $NetBSD: pmacctd.sh,v 1.1 2015/02/09 19:50:28 mbowie Exp $
#

# PROVIDE: pmacctd
# REQUIRE: NETWORK

$_rc_subr_loaded . /etc/rc.subr

name="pmacctd"
rcvar=${name}
command=@PREFIX@/sbin/${name}
required_files="@PKG_SYSCONFDIR@/${name}.conf"
pidfile="/var/run/${name}.pid"
command_args="-p ${pidfile} -f ${required_files}"

load_rc_config $name

run_rc_command "$1"

