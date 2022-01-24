#!/bin/sh
# $NetBSD: lpjs_dispatchd.sh,v 1.1 2018/04/22 21:31:09 bacon Exp $
#
# PROVIDE: lpjs_dispatchd
# REQUIRE: DAEMON munge
# KEYWORD: shutdown

$_rc_subr_loaded . /etc/rc.subr

name="lpjs_dispatchd"
rcvar=${name}
command="@PREFIX@/sbin/$name"
start_cmd="lpjs_start"
stop_cmd="lpjs_stop"
sig_stop="-INT"

lpjs_start()
{
    echo "Starting $name..."
    $command --daemonize
}

lpjs_stop()
{
    echo "Stopping $name..."
    pkill $sig_stop $name
}

load_rc_config $name
run_rc_command "$1"
