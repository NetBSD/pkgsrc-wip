#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: sndio
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="sndio"
rcvar=${name}
command="@PREFIX@/bin/sndiod"

load_rc_config ${name}
run_rc_command "$1"
