#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: honk
# REQUIRE: NETWORKING DAEMON
# KEYWORD: chrootdir

if @TEST@ -f @SYSCONFBASE@/rc.subr; then
	. @SYSCONFBASE@/rc.subr
fi

name="honk"
rcvar=${name}
command="@PREFIX@/bin/honk"
command_args="start"

start_precmd="honk_precmd"

honk_precmd()
{
	if ! @TEST@ -d @HONK_DATA@; then
		@MKDIR@ -m 0755 @HONK_DATA@
	fi
	if ! @TEST@ -d @HONK_DATA@/views; then
		@CP@ -R @EGDIR@/views @HONK_DATA@
	fi
}

load_rc_config $name
run_rc_command "$1"
