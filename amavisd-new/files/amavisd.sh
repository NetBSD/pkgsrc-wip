#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: amavisd.sh,v 1.4 2004/08/06 04:57:03 jcd Exp $
#
# PROVIDE: amavisd
# REQUIRE: DAEMON
# BEFORE:  mail
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="amavisd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
command_interpreter="@PERL5@"
pidfile="@AMAVIS_DIR@/amavisd.pid"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
required_dirs="@AMAVIS_DIR@"
: ${amavisd_user="@AMAVIS_USER@"}

start_precmd="amavisd_precmd"

amavisd_precmd()
{
	@RM@ -f @AMAVIS_DIR@/amavisd.sock
}

if [ -f /etc/rc.subr -a -f /etc/rc.conf \
     -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	eval ${start_precmd}          
	${command} ${amavisd_flags} ${command_args}
fi
