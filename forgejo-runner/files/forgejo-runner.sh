#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD$
#
# PROVIDE: forgejo-runner
# REQUIRE: DAEMON
#
# You will need to set some variables in @SYSCONFBASE@/rc.conf to start forgejo-runner:
#
# forgejo_runner=YES

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="forgejo_runner"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/config.yaml"
command="@PREFIX@/bin/forgejo-runner"
command_args="--config @PKG_SYSCONFDIR@/config.yaml daemon > /dev/null &"

forgejo_runner_env="HOME=@FORGEJO_RUNNER_USER_HOME@"
forgejo_runner_env="${forgejo_runner_env} PATH=@PREFIX@/bin:$PATH"

forgejo_runner_user="@FORGEJO_RUNNER_USER@"
forgejo_runner_group="@FORGEJO_RUNNER_GROUP@"

cd /

load_rc_config $name
run_rc_command "$1"
