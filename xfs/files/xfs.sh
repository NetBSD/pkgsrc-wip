#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: xfs.sh,v 1.1.1.1 2011/10/17 02:36:15 makoto Exp $
#

# PROVIDE: xfs
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

$_rc_subr_loaded . /etc/rc.subr

name="xfs"
rcvar=$name
xfs_config="/etc/X11/fs/config"
command="@PREFIX@/bin/${name}"
command_args="-daemon -config ${xfs_config}"
pidfile="/var/run/${name}.pid"
required_files="${xfs_config}"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
