#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: amavisd.sh,v 1.3 2004/04/19 03:42:09 jcd Exp $
#
# PROVIDE: amavisd
# REQUIRE: DAEMON
# BEFORE:  mail
#
# To start spread at startup, copy this script to /etc/rc.d and set
# spread=YES in /etc/rc.conf.
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

rcd_dir=`@DIRNAME@ $0`

name="amavisd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
command_interpreter="@PERL5@"
pidfile="@AMAVISDIR@/amavisd.pid"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
required_dirs="@AMAVISDIR@"

start_cmd="amavisd_doit start"
stop_cmd="amavisd_doit stop"
start_precmd="amavisd_precmd"

amavisd_precmd()
{
    @RM@ -f @AMAVISDIR@/amavis*.sock
}

amavisd_doit ()
{
	case $1 in
	start)	
	if [ -e @AMAVISDIR@/use.milter ]; then
		@SU@ @AMAVISUSER@ -c "@PREFIX@/sbin/amavis-milter -D -p @AMAVISDIR@/amavis-milter.sock"
	fi
	@SU@ @AMAVISUSER@ -c "@PREFIX@/sbin/amavisd > /dev/null 2>&1" && echo -n ' amavisd'
	;;
	stop)
	milter_pid=	
	amavisd_pid=`@CAT@ ${pidfile}`
	if [ -e @AMAVISDIR@/use.milter ]; then
		milter_pid=$(check_process @PREFIX@/sbin/amavis-milter )
		kill $milter_pid
		#killall -u @AMAVISUSER@ amavis-milter >/dev/null 2>&1
	fi
	if [ -e $pidfile ]; then
		@SU@ @AMAVISUSER@ -c "kill ${amavisd_pid}"
	fi

	wait_for_pids $milter_pid $amavisd_pid
	;;
	esac

}

if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	amavisd_doit "$1"
fi
