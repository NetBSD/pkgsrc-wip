#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: upimapproxy.sh,v 1.1.1.1 2004/06/24 23:42:55 adrian_p Exp $
#

# PROVIDE: upimapproxy
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="upimapproxy"
rcvar=$name
command="@PREFIX@/sbin/in.imapproxyd"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/imapproxy.conf"
stop_cmd="upimapproxy_stop"
sig_stop="-INT"

upimapproxy_stop()
{
	pids="`check_process in.imapproxyd`"
	if [ -n "$pids" ]; then
		for pid in $pids; do
			kill $sig_stop $pid
		done
	fi
}

load_rc_config $name
run_rc_command "$1"
