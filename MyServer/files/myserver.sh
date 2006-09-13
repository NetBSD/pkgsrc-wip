#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: myserver.sh,v 1.1.1.1 2006/09/13 13:55:07 bartoszkuzma Exp $
#
# KEYWORD: shutdown
# PROVIDE: myserver
# REQUIRE: DAEMON
#

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="myserver"
rcvar=${name}
command="@PREFIX@/bin/myserver"
start_cmd="myserver_start"

myserver_start() {
	if [ -f /etc/rc.subr ]; then
		@ECHO@ "Starting myserver."
	else
		@ECHO@ " ${name}"
	fi

	${command} SERVICE
}

if [ -f /etc/rc.subr ]; then
	load_rc_config ${name}
	run_rc_command "${1}"
else
	myserver_start
fi
