#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sddm.sh,v 1.1 2025/12/30 04:00:09 gutteridge Exp $
#
# PROVIDE: sddm
# REQUIRE: DAEMON LOGIN wscons dbus
# KEYWORD: shutdown

$_rc_subr_loaded . /etc/rc.subr

name="sddm"
rcvar=$name
procname="@LOCALBASE@/bin/$name"
pidfile="@VARBASE@/run/$name.pid"
command="@LOCALBASE@/sbin/daemonize"
command_args="$command_args -p $pidfile"
command_args="$command_args $procname"
start_precmd=sddm_prestart
start_cmd=sddm_start

sddm_prestart() {
	dirs="@VARBASE@/lib/$name"
	if test ! -d $dir; then
		mkdir -p $dir
		chmod 0755 $dir
		chown sddm:sddm $dir
	fi
}

sddm_start()
{
	@ECHO@ "Starting ${name}."

	(
		for i in $(seq 1 60); do
			pgrep -f '^/usr/libexec/getty ' >/dev/null && break
			sleep 1
		done
		$command $command_args
	) &
}

load_rc_config $name
run_rc_command "$1"
