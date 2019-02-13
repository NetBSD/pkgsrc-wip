#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: gitea
# REQUIRE: DAEMON

. /etc/rc.subr

name="gitea"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/app.ini"
pidfile="/dev/null"
command="@PREFIX@/sbin/gitea"
command_args="--config @PKG_SYSCONFDIR@/app.ini web &"

gitea_env="GITEA_WORK_DIR=@GITEA_SHARE_DIR@"
gitea_env="${gitea_env} GITEA_CUSTOM=@PKG_SYSCONFDIR@"
gitea_env="${gitea_env} HOME=@GITEA_USER_HOME@"
gitea_env="${gitea_env} USER=@GITEA_USER@"

gitea_user="@GITEA_USER@"
gitea_group="@GITEA_GROUP@"

# gitea's pidfile creation seems to not work...
check_pidfile()
{
	pid=$(pgrep -U "${gitea_user}" /sbin/gitea$)
	echo -n "${pid}"
}

load_rc_config $name
run_rc_command "$1"
