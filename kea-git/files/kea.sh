#!/bin/sh
#
# $NetBSD$
#
# PROVIDE: kea
# REQUIRE: LOGIN
#
. /etc/rc.subr

name="kea"
rcvar=$name
keactrl="@PREFIX@/sbin/keactrl"
start_cmd="keactrl_exec"
stop_cmd="keactrl_exec"
reload_cmd="keactrl_exec"
status_cmd="keactrl_exec"
extra_commands="reload status"

keactrl_exec()
{
        ${keactrl} ${rc_arg}
}

load_rc_config $name
run_rc_command "$1"
