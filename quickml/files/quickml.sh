#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: quickml.sh,v 1.5 2011/05/08 10:08:22 obache Exp $
#
# PROVIDE: quickml
# REQUIRE: LOGIN
#
# Add the following lines to /etc/rc.conf to enable this service:
#
# quickml=YES

. /etc/rc.subr

name="quickml"
rcvar=$name
command="@PREFIX@/sbin/${name}"
command_interpreter="@RUBY@"
pidfile="@VARBASE@/run/${name}.pid"
required_files=@PKG_SYSCONFDIR@/quickmlrc

load_rc_config ${name}
run_rc_command "$1"
