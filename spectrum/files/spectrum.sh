#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: spectrum.sh,v 1.3 2010/07/26 03:16:03 schnoebe Exp $
#
#   startup script for the spectrum jabber transport service
#
# PROVIDE: spectrum
# REQUIRE: DAEMON s2s
#

name="spectrum"
rcvar="$name"
procname="$name"
command=@PREFIX@/bin/spectrumctl

ensure_piddir()
{
	mkdir -p @JABBER_PIDDIR@ @JABBER_LOGDIR@
	chown @JABBER_USER@ @JABBER_PIDDIR@ @JABBER_LOGDIR@
}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} $1
fi
