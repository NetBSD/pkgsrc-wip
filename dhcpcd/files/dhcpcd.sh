#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dhcpcd.sh,v 1.1.1.1 2008/01/18 23:34:01 hoka_adam Exp $
#

# PROVIDE: dhclient
# REQUIRE: network mountcritlocal
# BEFORE:  NETWORKING
#
#	Note that there no syslog logging of dhclient messages at boot because
#	dhclient needs to start before services that syslog depends upon do.
#

if [ -f /etc/rc.subr ]; then
        . /etc/rc.subr
fi

name="dhcpcd"
rcvar="${name}"
ifn="$2"
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/dhcpcs-${ifn}.pid"
start_precmd="dhcpcd_precmd"

dhcpcd_precmd()
{
	# Override for $ifn specific flags (see rc.subr for $flags setting)
	specific=`get_if_var $ifn dhcpcd_flags_IF`
	if [ -z "$flags" -a -n "$specific" ]; then
		rc_flags=$specific
	fi

	# dhcpcd may need local binaries
	PATH=${PATH}:%%PREFIX%%/sbin
	export PATH
}

load_rc_config $rcvar
run_rc_command "$1"
