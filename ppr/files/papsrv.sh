#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: papsrv.sh,v 1.1 2005/05/06 08:58:00 hfath Exp $
#
# PROVIDE: papsrv
# REQUIRE: DAEMON

# Old PPR pap server
# Run only if its configfile exists.
 
if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="papsrv"
rcvar=$name
command="@PREFIX@/libexec/ppr/bin/${name}"
required_files="@PKG_SYSCONFDIR@/ppr.conf @PKG_SYSCONFDIR@/papsrv.conf"
extra_commands="reload"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${papsrv_flags}
fi
