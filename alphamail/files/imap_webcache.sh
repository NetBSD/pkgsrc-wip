#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: imap_webcache.sh,v 1.1.1.1 2008/02/12 11:36:29 shattered Exp $
#
# AlphaMail IMAP cache daemon
#
# PROVIDE: imap_webcache
# REQUIRE: DAEMON
# BEFORE: apache
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="imap_webcache"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
command_args="--pidfile $pidfile"

if [ -f /etc/rc.subr -a -f /etc/rc.conf \
     -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${command_args}
fi
