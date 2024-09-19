#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: hal.sh,v 1.3 2015/09/25 16:26:16 richard Exp $
#
# PROVIDE: hal
# REQUIRE: dbus
# KEYWORD: shutdown

. /etc/rc.subr

name="hal"
rcvar=$name
command="@PREFIX@/sbin/hald"
start_precmd=hal_prestart

hal_prestart() {
	/usr/bin/mkfifo -m 600 /tmp/halfifo
	(echo "ping" > /tmp/halfifo)&
	@MKDIR@ -m 0755 $dir "@VARBASE@/cache/hald" "@PKG_HOME.haldaemon@"
	@CHOWN@ -R @HAL_USER@:@HAL_GROUP@ "@PKG_HOME.haldaemon@" "@VARBASE@/cache/hald"
	sleep 3
}

load_rc_config $name
run_rc_command "$1"
