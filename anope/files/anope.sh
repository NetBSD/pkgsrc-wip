#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: anope
# REQUIRE: DAEMON

. /etc/rc.subr

name="anope"
rcvar=${name}
command="@PREFIX@/bin/anope"
command_args="--confdir=@PKG_SYSCONFDIR@/anope"
command_args="${command_args} --dbdir=@PREFIX@/anope/data"
command_args="${command_args} --localedir=@PREFIX/@PKGLOCALEDIR@/locale"
command_args="${command_args} --logdir=@PREFIX@/anope/logs"
command_args="${command_args} --modulesdir=@PREFIX@/lib/anope"
required_files="@PKG_SYSCONFDIR@/anope/services.conf"
pidfile="@PREFIX@/anope/${name}.pid"

anope_user="@ANOPE_USER@"
anope_group="@ANOPE_GROUP@"

load_rc_config $name
run_rc_command "$1"
