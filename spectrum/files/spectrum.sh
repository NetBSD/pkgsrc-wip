#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: spectrum.sh,v 1.2 2010/03/10 04:38:42 schnoebe Exp $
#
#   startup script for the spectrum jabber transport service
#
# PROVIDE: spectrum
# REQUIRE: DAEMON s2s
#

name="spectrum"
rcvar=$name
command=@PREFIX@/bin/spectrumctl
spectrum_user="@JABBER_USER@"
command_args=""

ensure_piddir()
{
	mkdir -p @JABBER_PIDDIR@ @JABBER_LOGDIR@
	chown @JABBER_USER@ @JABBER_PIDDIR@ @JABBER_LOGDIR@
}

remove_pidfile()
{
        if [ -f $pidfile ]; then
            rm -f $pidfile
        fi
}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	@SU@ ${yahoo_user} -c "${command} ${yahoo_transport_flags} ${command_args}"
fi
