#!/bin/sh
#
# $NetBSD: nncp-caller.sh,v 0.2 2022/02/02 dvol Exp $
#

# PROVIDE: nncp_caller
# REQUIRE: DAEMON

. /etc/rc.subr

name="nncp_caller"
nncp_caller_rcname="nncp-caller"
rcvar="nncp_caller"
command="@PREFIX@/libexec/nncp-caller"
procname="@PREFIX@/bin/nncp-caller"
conf_file="@PKG_SYSCONFDIR@/nncp/nncp.hjson"
required_files="${conf_file}"
pidfile="@VARBASE@/run/nncp-caller.pid"
stop_postcmd=nncp_caller_remove_pidfile

nncp_caller_remove_pidfile {
    rm -f "${pidfile}"
}

load_rc_config ${nncp_caller_rcname}
run_rc_command ${1}

