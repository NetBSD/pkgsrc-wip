#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: sftpgo
# REQUIRE: DAEMON
# KEYWORD: shutdown

name="sftpgo"

command="@PREFIX@/sbin/daemonize"

pidfile="@VARBASE@/run/${name}.pid"

task="@PREFIX@/bin/${name}"
task_args="serve --config-dir @VARBASE@/sftpgo --config-file @PKG_SYSCONFDIR@/sftpgo.json"

procname="${task}"

command_args="-p ${pidfile} \
	-u @SFTPGO_USER@ \
	-c @VARBASE@/${name} \
	-e @VARBASE@/${name}/${name}.stderr \
	-o @VARBASE@/${name}/${name}.stdout \
	${task} ${task_args}"

if [ -f @SYSCONFBASE@/rc.subr ]; then
    	. @SYSCONFBASE@/rc.subr

	rcvar=${name}
	pidfile="@VARBASE@/run/${name}.pid"

	load_rc_config ${name}
	run_rc_command "$1"
else
        @ECHO@ -n " ${name}"

	${command} ${command_args}
fi
