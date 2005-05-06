#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: lprsrv.sh,v 1.1 2005/05/06 08:58:00 hfath Exp $
#
# PROVIDE: lprsrv
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="lprsrv"
rcvar=$name
command="@PREFIX@/libexec/ppr/bin/${name}"
required_files="@PKG_SYSCONFDIR@/ppr.conf"
extra_commands="reload"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} -s printer ${lprsrv_flags}
fi
