#!/bin/sh
#
# PROVIDE: modutils
# REQUIRE: root
# BEFORE: tty

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="modutils"
rcvar=$name
depmod_command="@PREFIX@/sbin/depmod"
modprobe_command="@PREFIX@/sbin/modprobe"
start_cmd="modutils_start"
stop_cmd=":"

modutils_start()
{
	if [ -x ${depmod_command} -a -x ${modprobe_command} ]; then
		# make module dependencies
		${depmod_command} -a

		if [ -f @PKG_SYSCONFDIR@/modules ]; then
			# load modules from /etc/modules
			# add a linefeed, just in case it was missing
			echo -n "Loading kernel modules: "
			(cat @PKG_SYSCONFDIR@/modules; echo) |
			while read module args; do
				case "$module" in
					\#*|"") continue
						;;
				esac
				echo -n "$module "
				${modprobe_command} $module $args
			done
			echo
		fi
		
	fi
}

load_rc_config $name
run_rc_command "$1"
