#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: proxy65.sh,v 1.2 2008/08/13 04:56:31 schnoebe Exp $
#
#   startup script for the proxy65 file transfer proxy service for Jabber
#   uses the twistd application engine
#
# PROVIDE: proxy65
# REQUIRE: DAEMON s2s
#
#
#	additional items that _must_ be set as part of proxy65_flags
#		--jid=		[Jabber ID of the service, default proxy65]
#		--secret=	[shared secret with the S2S]
#		--rhost=	[IP/Host of the Jabber service router]
#		--rport=	[port of the Jabber service router, def 6000]
#		--proxyips=	[proxy address:ports to be advertised/used]
#				[default :7777]
#
#	ex:
#		proxy6_flags="--jid=proxy.jabber.example.org \
#				--secret=JabberSecret \
#				--rhost=jabber.proxy.org \
#				--rport=5347 \
#				--proxyips=172.17.233.23:8010"
#
#

name="proxy65"
rcvar=$name
command=@PREFIX@/bin/twistd
command_interpreter="@PYTHONBIN@"
pidfile="@JABBER_PIDDIR@/${name}.pid"
logfile="@JABBER_LOGDIR@/${name}.log"
command_args="-u @JABBER_USER@ --pidfile=${pidfile} -l ${logfile}"
command_args="${command_args} proxy65"
stop_postcmd="remove_pidfile"
start_precmd="ensure_piddir"

ensure_piddir()
{
	mkdir -p @JABBER_PIDDIR@
	chown @JABBER_USER@ @JABBER_PIDDIR@
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
	ensure_piddir
	${command} ${command_args} ${pyaimt_flags} 
fi
