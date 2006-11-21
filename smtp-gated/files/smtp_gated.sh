#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: smtp_gated.sh,v 1.1.1.1 2006/11/21 14:26:07 bartoszkuzma Exp $
#

# PROVIDE: smtp_gated
# BEFORE: mail
# REQUIRE: DAEMON LOGIN

. /etc/rc.subr

name="smtp_gated"
rcvar=$name
pidfile="@VARBASE@/run/smtp-gated/smtp-gated.pid"
command="@PREFIX@/sbin/smtp-gated"
extra_commands="reload"
config_file="@PKG_SYSCONFDIR@/smtp-gated.conf"
required_files="${config_file}"

smtp_gated_group="@SMTP_GATED_GROUP@"
smtp_gated_user="@SMTP_GATED_USER@"
smtp_gated_dirs="@VARBASE@/spool/smtp-gated @VARBASE@/spool/smtp-gated/lock @VARBASE@/spool/smtp-gated/msg @VARBASE@/run/smtp-gated"

start_cmd="${command} ${config_file}"
start_precmd="smtp_gated_prestart"
status_cmd="${command} -s"
reload_cmd="${command} -r ${config_file}"

smtp_gated_prestart()
{
	for dir in ${smtp_gated_dirs}
	do
		@MKDIR@ -p ${dir}
		@CHOWN@ -R ${smtp_gated_user}:${smtp_gated_group} ${dir}
	done
}

if [ -f /etc/rc.subr -a -f /etc/rc.conf ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${config_file}
fi
