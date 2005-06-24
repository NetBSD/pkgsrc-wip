#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: spamd.sh,v 1.1 2005/06/24 12:04:08 ppostma Exp $
#
# PROVIDE: spamd
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="spamd"
rcvar=$name
command="@PREFIX@/libexec/${name}"

spamd_postcmd()
{
	if [ -x @PREFIX@/libexec/spamd-setup ]; then
		@PREFIX@/libexec/spamd-setup
	fi
}

load_rc_config $name
run_rc_command "$1"
