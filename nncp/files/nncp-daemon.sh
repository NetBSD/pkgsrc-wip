#!/bin/sh
#
# $NetBSD: nncp-daemon.sh,v 0.2 2022/02/02 dvol Exp $
#

# PROVIDE: nncp_daemon
# REQUIRE: DAEMON

. /etc/rc.subr

name="nncp_daemon"
nncp_daemon_rcname="nncp-daemon"
rcvar="nncp_daemon"
command="@PREFIX@/libexec/nncp-daemon"
procname="@PREFIX@/bin/nncp-daemon"
conf_file="@PKG_SYSCONFDIR@/nncp/nncp.hjson"
required_files="${conf_file}"
pidfile="@VARBASE@/run/nncp-daemon.pid"
stop_postcmd=nncp_daemon_remove_pidfile

nncp_daemon_remove_pidfile {
    rm -f "${pidfile}"
}

load_rc_config ${nncp_daemon_rcname}
run_rc_command ${1}

