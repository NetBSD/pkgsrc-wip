#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ppr-papd.sh,v 1.1 2005/05/06 08:58:00 hfath Exp $
#
# PROVIDE: ppr-papd
# REQUIRE: DAEMON

## Conflicts with Netatalk papd!
## What ca n we do about the PID file?

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="ppr-papdd"
rcvar=$name
command="@PREFIX@/libexec/ppr/bin/papd"
required_files="@PKG_SYSCONFDIR@/ppr.conf"
extra_commands="reload"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${ppr-papd_flags}
fi
