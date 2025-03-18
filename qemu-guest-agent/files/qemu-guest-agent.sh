#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: qemu_guest_agent
# REQUIRE: DAEMON
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="qemu_guest_agent"
rcvar="${name}"
command="@PREFIX@/bin/qemu-ga"
command_args="-m isa-serial -p /dev/tty00 -r -t /var/run -f /var/run/${name}.pid"


load_rc_config $name
(run_rc_command "$1" &)
