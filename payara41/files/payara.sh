#! @RCD_SCRIPTS_SHELL@
#
# $NetBSD: payara.sh,v 1.0 2017/01/23 11:23:24 pkgsrc Exp $
#
# PROVIDE: payara
# REQUIRE: DAEMON
#

if [ -r /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="payara"
rcvar=$name
command="@PAYARA_HOME@/bin/asadmin"
pidfile="@VARBASE@/run/payara/payara.pid"
payara_user="@PAYARA_USER@"
payara_group="@PAYARA_GROUP@"
start_cmd="${name}_start"
stop_cmd="${name}_stop"
restart_cmd="${name}_restart"
start_precmd="payara_precmd"

PREFIX=@PREFIX@

if [ -z "${JAVA_HOME}" ]; then
	JAVA_HOME="@JAVA_HOME@"
	export JAVA_HOME
	PATH=${PATH}:${JAVA_HOME}/bin
	export PATH
fi

PAYARA_HOME=@PAYARA_HOME@
PAYARA_PID=${pidfile}
export PAYARA_HOME
export PAYARA_PID

if [ -n "${payara_classpath}" ]
then
	CLASSPATH=${CLASSPATH}:${payara_classpath}
fi
export CLASSPATH

payara_precmd()
{
	if [ ! -d @VARBASE@/run/payara ]; then
		@MKDIR@ @PAYARA_RUN_DIR@
		@CHMOD@ 0750 @PAYARA_RUN_DIR@
		@CHOWN@ ${payara_user}:${payara_group} @PAYARA_RUN_DIR@
	fi
}

payara_start()
{
	@SU@ ${payara_user} -c "${command} start-domain"
}

payara_stop()
{
	rc_pid=$(check_pidfile $pidfile "${JAVA_HOME}/bin/java")
	@SU@ ${payara_user} -c "${command} stop-domain"
	wait_for_pids $rc_pid
}

payara_restart()
{
    @SU@ ${payara_user} -c "${command} stop-domain"
    @SU@ ${payara_user} -c "${command} start-domain"
}


if [ -f /etc/rc.subr ]
then
	load_rc_config "$name"
	run_rc_command "$1"
else
	echo -n ' ${name}'
	exec ${command} ${payara_flags} ${command_args}
fi
