#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dbus.sh,v 1.10 2016/05/22 23:02:24 youri Exp $
#
# PROVIDE: dbus
# REQUIRE: DAEMON
# KEYWORD: shutdown

. /etc/rc.subr

name="dbus"
rcvar="@DBUS_RCVAR@"
command="@PREFIX@/bin/dbus-daemon"
command_args="--system --fork"
pidfile="@VARBASE@/run/dbus/@DBUS_SYSTEM_PID_FILE_SH@"
start_precmd="dbus_prestart"
stop_postcmd="dbus_poststop"

dbus_prestart() {
	dbdir="@VARBASE@/db/dbus"
	if @TEST@ ! -d $dbdir; then
		@MKDIR@ $dbdir
	fi
	dir="@VARBASE@/run/dbus"
	if @TEST@ ! -d $dir; then
		@MKDIR@ $dir
# On other systems /var/run/dbus root:wheel works fine
		@CHMOD@ 0755 $dir
		@CHOWN@ @DBUS_VAR_RUN_USER_SH@:@DBUS_VAR_RUN_GROUP_SH@ $dir
	elif @TEST@ -f $pidfile; then
		@RM@ -f $pidfile
	fi
	@PREFIX@/bin/dbus-uuidgen --ensure
}

dbus_poststop() {
	@RM@ -f $pidfile
	[ ! -d $dbdir ] || @RMDIR@ $dbdir
}

load_rc_config $name
run_rc_command "$1"
