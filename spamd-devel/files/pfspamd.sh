#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pfspamd.sh,v 1.1.1.1 2007/04/10 18:27:25 jeremy-c-reed Exp $
#
# PROVIDE: pfspamd
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="pfspamd"
rcvar=$name
command="@PREFIX@/libexec/spamd"

pfspamd_postcmd()
{
	if [ -x @PREFIX@/libexec/spamd-setup ]; then
		@PREFIX@/libexec/spamd-setup
	fi
}

load_rc_config $name
run_rc_command "$1"
