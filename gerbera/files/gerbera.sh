#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#

# PROVIDE: gerbera
# REQUIRE: DAEMON

. /etc/rc.subr

name="gerbera"
rcvar=$name
load_rc_config_var gerbera_username gerbera_username
load_rc_config_var gerbera_groupname gerbera_groupname
command="@PREFIX@/bin/gerbera"
logfile="@VARBASE@/log/${name}.log"
pidfile="@PKG_HOME@/${name}.pid"
#command_args="-d -u ${gerbera_username:-@GERBERA_USER@} -g ${gerbera_groupname:-@GERBERA_USER@} -m @PKG_HOME@ -P ${pidfile} -l ${logfile} -c @PKG_SYSCONFDIR@/config.xml"
command_args="-m @PKG_HOME@ -l ${logfile} -c @PKG_SYSCONFDIR@/config.xml"
extra_commands="reload"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n "${name}"
	${command} ${gerbera_flags} ${command_args}
fi
