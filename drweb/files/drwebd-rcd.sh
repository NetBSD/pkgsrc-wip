#!/bin/sh
#
# $NetBSD: drwebd-rcd.sh,v 1.1.1.1 2003/04/10 18:51:56 jmmv Exp $
#
# To start drwebd at startup, copy this script to /etc/rc.d and set
# drwebd=YES in /etc/rc.conf.

# PROVIDE: drwebd
# REQUIRE: LOGIN

. /etc/rc.subr

name="drwebd"
rcvar=$name
command="@PREFIX@/sbin/${name}-fbsd"
procname="${command}"
drw_inifile="@PKG_SYSCONFDIR@/drweb32.ini"
required_files="${drw_inifile}"
command_args="-ini:${drw_inifile}"

extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
