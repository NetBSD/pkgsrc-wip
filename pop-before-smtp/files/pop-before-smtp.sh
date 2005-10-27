#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pop-before-smtp.sh,v 1.1.1.1 2005/10/27 05:24:34 obache Exp $
#
# PROVIDE: pop_before_smtp
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="pop_before_smtp"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
conffile="@PKG_SYSCONFDIR@/pop-before-smtp-conf.pl"
required_files=${conffile}

command_args="--config=${conffile} --daemon=${pidfile}"

load_rc_config ${name}
run_rc_command "$1"
