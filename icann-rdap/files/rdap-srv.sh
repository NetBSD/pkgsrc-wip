#!@RCD_SCRIPTS_SHELL@
#
#
# PROVIDE: rdap-srv

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="rdap-srv"
rcvar="${name}"
command="@PREFIX@/bin/${name}"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${rdap-srv_flags} ${command_args}
fi
