#!/bin/sh
#
# $NetBSD: nncp-toss.sh,v 0.2 2022/02/02 dvol Exp $
#

# PROVIDE: nncp_toss
# REQUIRE: DAEMON

. /etc/rc.subr

name="nncp_toss"
nncp_toss_rcname="nncp-toss"
rcvar="nncp_toss"
command="@PREFIX@/libexec/nncp-toss"
procname="@PREFIX@/bin/nncp-toss"
conf_file="@PKG_SYSCONFDIR@/nncp/nncp.hjson"
required_files="${conf_file}"
nncp_toss_flags="--cycle 60"
pidfile="@VARBASE@/run/nncp-toss.pid"
stop_postcmd=nncp_toss_remove_pidfile

nncp_toss_remove_pidfile {
    rm -f "${pidfile}"
}

load_rc_config ${nncp_toss_rcname}
run_rc_command ${1}

