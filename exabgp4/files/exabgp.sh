#!/bin/sh
#
# $NetBSD$
#

# PROVIDE: exabgp4
# REQUIRE: LOGIN

$_rc_subr_loaded . /etc/rc.subr

name="exabgp"
rcvar="${name}"
command="/usr/pkg/bin/${name}"
required_files="/usr/pkg/etc/exabgp/exabgp.env /usr/pkg/etc/exabgp/exabgp.conf"
command_args="-e ${required_files}"
pidfile="/var/run/${name}/${name}.pid"
command_interpreter="@PYTHONBIN@"

makepipe() {
	test -p /var/run/exabgp/exabgp.in || mkfifo /var/run/exabgp/exabgp.in
	test -p /var/run/exabgp/exabgp.out || mkfifo /var/run/exabgp/exabgp.out
	chown nobody /var/run/exabgp/exabgp.in /var/run/exabgp/exabgp.out
	chmod 600 /var/run/exabgp/exabgp.in /var/run/exabgp/exabgp.out
}

cleanpipe() {
	rm -f /var/run/exabgp/exabgp.in
	rm -f /var/run/exabgp/exabgp.out
}

start_precmd=makepipe
stop_postcmd=cleanpipe

load_rc_config $name
run_rc_command "$1"
