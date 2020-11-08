#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: radicale.sh,v 1.1 2017/07/01 05:57:07 darcy Exp $
#
# PROVIDE: radicale
# REQUIRE: DAEMON
# KEYWORD: shutdown

$_rc_subr_loaded . /etc/rc.subr

name="radicale"
rcvar=$name

load_rc_config $name

: ${radicale_user:=@RADICALE_USER@}
: ${radicale_group:=@RADICALE_GROUP@}
: ${radicale_pidfile:="@VARBASE@/run/${name}.pid"}
: ${radicale_logfile:="@VARBASE@/log/${name}.log"}

command="@PREFIX@/bin/radicale"
command_args=" </dev/null >/dev/null 2>${radicale_logfile} & echo \$! >${radicale_pidfile}"
command_interpreter="@PYTHONBIN@"
required_files="@PKG_SYSCONFDIR@/radicale/config"

start_precmd="radicale_precmd"

radicale_precmd()
{
    @TOUCH@ ${radicale_logfile} && \
    @CHOWN@ ${radicale_user}:${radicale_group} ${radicale_logfile} && \
    @CHMOD@ 0750 ${radicale_logfile} && \
    @TOUCH@ ${radicale_pidfile} && \
    @CHOWN@ ${radicale_user}:${radicale_group} ${radicale_pidfile} && \
    @CHMOD@ 0750 ${radicale_pidfile}
}

run_rc_command "$1"
