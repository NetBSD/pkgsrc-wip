#!/bin/sh
#
# $NetBSD: head/net/coturn/files/turnserver.sh
#
# PROVIDE: turnserver
# REQUIRE: LOGIN
# KEYWORD: shutdown
#
# Add the following lines to /etc/rc.conf.local or /etc/rc.conf
# to enable this service:
#
# turnserver (bool):		Set to NO by default.
#				Set it to YES to enable turnserver.
# turnserver_config (path):	Set to @PREFIX@/etc/turnserver.conf
#				by default.

. /etc/rc.subr

name="turnserver"
rcvar=$name

: ${turnserver:=no}
: ${turnserver_config=@PKG_SYSCONFDIR@/turnserver.conf}
: ${coturn_user:=@COTURN_USER@}
: ${coturn_group:=@COTURN_GROUP@}

load_rc_config $name

command="@PREFIX@/bin/${name}"
command_args="--daemon --proc-user ${coturn_user} --proc-group ${coturn_user} -c ${turnserver_config}"
required_files=${turnserver_config}

run_rc_command "$1"
