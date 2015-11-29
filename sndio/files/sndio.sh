#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: sndio
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="sndio"
rcvar=$name
command="@PREFIX@/bin/sndiod"
pidfile="@VARBASE@/run/sndio/pid"
start_precmd=sndio_prestart

sndio_prestart() {
	dir="@VARBASE@/run/sndio"
	if @TEST@ ! -d $dir; then
		@MKDIR@ $dir
		@CHMOD@ 0755 $dir
		@CHOWN@ @DBUS_USER@:@DBUS_GROUP@ $dir
	fi
	@PREFIX@/bin/dbus-uuidgen --ensure
}

load_rc_config $name
run_rc_command "$1"
