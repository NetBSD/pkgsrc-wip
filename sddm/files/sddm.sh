#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sddm.sh,v 1.11 2025/09/27 19:14:16 st2135 Exp $
#
# PROVIDE: sddm
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown
#
# You will need to set some variables in /etc/rc.conf to start sddm:
#
# sddm=YES

$_rc_subr_loaded . /etc/rc.subr

name="sddm"
rcvar=$name
procname="@PREFIX@/bin/$name"
pidfile="@VARBASE@/run/$name.pid"
command="@PREFIX@/sbin/daemonize"
command_args="$command_args -p $pidfile"
command_args="$command_args $procname"

start_precmd=sddm_prestart

sddm_prestart() {
	dirs="@VARBASE@/lib/$name"
	if test ! -d $dir; then
		/bin/mkdir -p $dir
		/bin/chmod 0755 $dir
		/usr/sbin/chown sddm:sddm $dir
	fi
}

load_rc_config $name
run_rc_command "$1"
