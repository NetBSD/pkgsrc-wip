#!/bin/sh
#
# $NetBSD$
#

# PROVIDE: siproxd
# REQUIRE: DAEMON
# BEFORE:  LOGIN

$_rc_subr_loaded . /etc/rc.subr

name="siproxd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}/${name}.pid"
required_files="@PKG_SYSCONFDIR@/siproxd.conf"
start_precmd="siproxd_precmd"

siproxd_precmd()
{
        rc_flags="-p ${pidfile} $rc_flags"

        local piddir="$(dirname "${pidfile}")"
        mkdir -p "${piddir}"
        chown @SIPROXD_USER@:@SIPROXD_GROUP@ "${piddir}"
}

load_rc_config $name
run_rc_command "$1"
