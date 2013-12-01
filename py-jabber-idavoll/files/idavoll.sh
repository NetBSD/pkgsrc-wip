#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: idavoll.sh,v 1.1 2013/12/01 21:09:50 schnoebe Exp $
#
#   startup script for the proxy65 file transfer proxy service for Jabber
#   uses the twistd application engine
#
# PROVIDE: idavoll
# REQUIRE: DAEMON s2s
#
#
#	Additional variables
#	    idavoll_jid		[Jabber ID of the service, default proxy65]
#	    idavoll_secret	[shared secret with the S2S]
#	    idavoll_rhost	[IP/Host of the Jabber service router]
#	    idavoll_rport	[port of the Jabber service router, def 6000]
#	    idavoll_ips		[proxy address:ports to be advertised/used]
#				[default :7777]
#
#	ex:
#	    idavoll_jid=proxy.jabber.example.org
#	    idavoll_secret=JabberSecret
#	    idavoll_rhost=jabber.example.org
#	    idavoll_ips=172.18.223.20:8010
#

name="idavoll"
rcvar=$name
command=@PREFIX@/bin/twistd
command_interpreter="@PYTHONBIN@"
pidfile="@JABBER_PIDDIR@/${name}.pid"
logfile="@JABBER_LOGDIR@/${name}.log"
command_args="-u @JABBER_USER@ --pidfile=${pidfile} -l ${logfile}"
command_args="${command_args} idavoll"

start_precmd="ensure_piddir && merge_args"

merge_args()
{
command_args="${command_args} ${idavoll_jid:+--jid=${idavoll_jid}}"
command_args="${command_args} ${idavoll_secret:+--secret=${idavoll_secret}}"
command_args="${command_args} ${idavoll_rhost:+--rhost=${idavoll_rhost}}"
command_args="${command_args} ${idavoll_rport:+--rport=${idavoll_rport}}"
command_args="${command_args} ${idavoll_ips:+--proxyips=${idavoll_ips}}"
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
	${command} ${command_args} ${idavoll_flags} 
fi
