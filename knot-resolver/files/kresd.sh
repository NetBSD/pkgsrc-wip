#!/bin/sh
#
# $NetBSD: drixter $
#

# PROVIDE: kresd
# REQUIRE: DAEMON

. /etc/rc.subr

name="kresd"
rcvar="kresd_enable"

knotresolver_user="root"
knotresolver_command="@PREFIX@/sbin/kresd -n -c @PKG_SYSCONFDIR@/kresd.conf @PKG_SYSCONFDIR@/knot-resolver"

pidfile="/var/run/${name}.pid"
command="@PREFIX@/sbin/daemonize"
command_args="-p ${pidfile} -u ${knotresolver_user} -o /var/log/knotresolver.log -- ${knotresolver_command}"

procname="@PREFIX@/sbin/kresd"

load_rc_config $name
run_rc_command "$1"

