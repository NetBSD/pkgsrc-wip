#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: radicale
# REQUIRE: DAEMON
# KEYWORD: shutdown

$_rc_subr_loaded . /etc/rc.subr

name="radicale"
rcvar=$name

load_rc_config $name

command_interpreter="@PYTHONBIN@"

task="@PREFIX@/bin/${name}"
procname="${task}"
pidfile="@VARBASE@/run/${name}/${name}.pid"

command="@PREFIX@/sbin/daemonize"

command_args="-a \
    -p ${pidfile} \
    -u @RADICALE_USER@ \
    -e @RADICALE_LOGDIR@/${name}.log \
    -o @RADICALE_LOGDIR@/daemonize.stdout \
    ${task}"

required_files="@PKG_SYSCONFDIR@/config"

start_precmd="radicale_precmd"

radicale_precmd()
{
        if [ ! -e "@VARBASE@/run/${name}" ] ; then
                install -d -o @RADICALE_USER@ -g @RADICALE_GROUP@ \
		    -m 0750 "@VARBASE@/run/${name}"
        fi
}

load_rc_config ${name}
run_rc_command "$1"
