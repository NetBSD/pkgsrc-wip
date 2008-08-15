#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: proxy65.sh,v 1.3 2008/08/15 17:07:24 schnoebe Exp $
#
#   startup script for the proxy65 file transfer proxy service for Jabber
#   uses the twistd application engine
#
# PROVIDE: proxy65
# REQUIRE: DAEMON s2s
#
#
#	Additional variables
#	    proxy65_jid		[Jabber ID of the service, default proxy65]
#	    proxy65_secret	[shared secret with the S2S]
#	    proxy65_rhost	[IP/Host of the Jabber service router]
#	    proxy65_rport	[port of the Jabber service router, def 6000]
#	    proxy65_ips		[proxy address:ports to be advertised/used]
#				[default :7777]
#
#	ex:
#	    proxy65_jid=proxy.jabber.example.org
#	    proxy65_secret=JabberSecret
#	    proxy65_rhost=jabber.example.org
#	    proxy65_ips=172.18.223.20:8010
#

name="proxy65"
rcvar=$name
command=@PREFIX@/bin/twistd
command_interpreter="@PYTHONBIN@"
pidfile="@JABBER_PIDDIR@/${name}.pid"
logfile="@JABBER_LOGDIR@/${name}.log"
command_args="-u @JABBER_USER@ --pidfile=${pidfile} -l ${logfile}"
command_args="${command_args} proxy65"

start_precmd="ensure_piddir && merge_args"

merge_args()
{
command_args="${command_args} ${proxy65_jid:+--jid=${proxy65_jid}}"
command_args="${command_args} ${proxy65_secret:+--secret=${proxy65_secret}}"
command_args="${command_args} ${proxy65_rhost:+--rhost=${proxy65_rhost}}"
command_args="${command_args} ${proxy65_rport:+--rport=${proxy65_rport}}"
command_args="${command_args} ${proxy65_ips:+--proxyips=${proxy65_ips}}"
}

ensure_piddir()
{
	mkdir -p @JABBER_PIDDIR@
	chown @JABBER_USER@ @JABBER_PIDDIR@
}

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	ensure_piddir
	${command} ${command_args} ${pyaimt_flags} 
fi
