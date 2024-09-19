#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: punjab.sh,v 1.2 2009/02/17 00:46:43 schnoebe Exp $
#
#   startup script for the proxy65 file transfer proxy service for Jabber
#   uses the twistd application engine
#
# PROVIDE: proxy65
# REQUIRE: DAEMON s2s
#
#
#	Additional variables
#	    punjab_jid		[Jabber ID of the service, default proxy65]
#	    punjab_secret	[shared secret with the S2S]
#	    punjab_rhost	[IP/Host of the Jabber service router]
#	    punjab_rport	[port of the Jabber service router, def 6000]
#	    punjab_ips		[proxy address:ports to be advertised/used]
#				[default :7777]
#
#	ex:
#	    punjab_jid=proxy.jabber.example.org
#	    punjab_secret=JabberSecret
#	    punjab_rhost=jabber.example.org
#	    punjab_ips=172.18.223.20:8010
#

name="punjab"
rcvar=$name
command=@PREFIX@/bin/twistd
command_interpreter="@PYTHONBIN@"
pidfile="@JABBER_PIDDIR@/${name}.pid"
logfile="@JABBER_LOGDIR@/${name}.log"
command_args="-u @JABBER_USER@ --pidfile=${pidfile} -l ${logfile}"
command_args="${command_args} punjab"

start_precmd="ensure_piddir && merge_args"

merge_args()
{
command_args="${command_args} ${punjab_jid:+--jid=${punjab_jid}}"
command_args="${command_args} ${punjab_secret:+--secret=${punjab_secret}}"
command_args="${command_args} ${punjab_rhost:+--rhost=${punjab_rhost}}"
command_args="${command_args} ${punjab_rport:+--rport=${punjab_rport}}"
command_args="${command_args} ${punjab_ips:+--proxyips=${punjab_ips}}"
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
	${command} ${command_args} ${punjab_flags} 
fi
