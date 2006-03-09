#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: pop-before-smtp.sh,v 1.2 2006/03/09 14:44:48 obache Exp $
#
# PROVIDE: pop_before_smtp
# REQUIRE: DAEMON
#

. /etc/rc.subr

name="pop_before_smtp"
rcvar=${name}
command="@PREFIX@/sbin/pop-before-smtp"
pidfile="@VARBASE@/run/${name}.pid"
conffile="@PKG_SYSCONFDIR@/pop-before-smtp-conf.pl"
required_files=${conffile}

command_args="--config=${conffile} --daemon=${pidfile}"
command_interpreter=@PERL5@

load_rc_config ${name}
run_rc_command "$1"
