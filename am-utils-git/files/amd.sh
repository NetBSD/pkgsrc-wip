#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: amd.sh,v 1.1 2013/08/30 15:03:43 hfath Exp $
# PROVIDE: amd
# REQUIRE: rpcbind mountall ypbind
# BEFORE:  DAEMON

$_rc_subr_loaded . /etc/rc.subr

name="amd_pkgsrc"
rcvar=$name
command="@PREFIX@/sbin/amd"
reload_cmd="@PREFIX@/sbin/amq -f"
extra_commands="reload"

load_rc_config $name

command_args='-p -a '$amd_dir' -F @PKG_SYSCONFDIR@/amd.conf >@VARBASE@/run/amd.pid'
required_files="@PKG_SYSCONFDIR@/amd.conf"
required_dirs="$amd_dir"
required_vars="rpcbind"

load_rc_config_var rpcbind rpcbind

run_rc_command "$1"
