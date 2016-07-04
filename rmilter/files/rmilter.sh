#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: rmilter
# REQUIRE: DAEMON
# BEFORE: mail

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="rmilter"
rcvar=$name
command="@PREFIX@/sbin/rmilter"
pidfile="@VARBASE@/run/rmilter/${name}.pid"
command_args="-c @PKG_SYSCONFDIR@/rmilter.conf"
required_files="@PKG_SYSCONFDIR@/rmilter.conf"
start_precmd="rmilter_precmd"

rmilter_precmd()
{
	if [ ! -d @VARBASE@/run/rmilter ]; then
		@MKDIR@ @VARBASE@/run/rmilter
		@CHMOD@ 0755 @VARBASE@/run/rmilter
		@CHOWN@ @RMILTER_USER@:@RMILTER_GROUP@ @VARBASE@/run/rmilter
	fi

	if [ -f @VARBASE@/run/rmilter/${name}.sock ]; then
		@RM@ -f @VARBASE@/run/rmilter/${name}.sock
	fi
}

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${rmilter_flags} ${command_args}
fi

