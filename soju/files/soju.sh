#!/bin/sh
#
# $NetBSD$
#
# PROVIDE: soju
# REQUIRE: DAEMON
#
# The following lines should be added to /etc/rc.conf:
#
# soju=YES
# soju_user="soju"

$_rc_subr_loaded . /etc/rc.subr

name="soju"
rcvar=$name
command="/usr/pkg/bin/soju"
required_files="/usr/pkg/etc/soju/config"
extra_commands="reload"
start_precmd=soju_prestart

soju_prestart() {
	dir="/var/run/soju"
	if test ! -d $dir; then
		/bin/mkdir -p $dir
		/bin/chmod 0700 $dir
		/usr/sbin/chown soju:soju $dir
	fi
}

load_rc_config $name
run_rc_command "$1"
