#!/bin/sh

# PROVIDE: dhcpcd
# REQUIRE: network mountcritlocal
# BEFORE:  NETWORKING

if [ -f /etc/rc.subr ]; then
        . /etc/rc.subr
fi

name="dhcpcd"
rcvar="${name}"
ifn="$2"
command="@PREFIX@/sbin/${name}"
command_args="${ifn}"
pidfile="@VARBASE@/run/${name}-${ifn}.pid"
start_precmd="dhcpcd_precmd"

dhcpcd_precmd()
{
	# Override for $ifn specific flags (see rc.subr for $flags setting)
	eval ifn_flags=\$${rcvar}_flags_${ifn}
	if [ -z "${flags}" -a -n "${ifn_flags}" ]; then
		rc_flags=${ifn_flags}
	fi

	# dhcpcd may need local binaries
	PATH=${PATH}:@PREFIX@/sbin
	export PATH
}

load_rc_config $rcvar
run_rc_command "$1"
