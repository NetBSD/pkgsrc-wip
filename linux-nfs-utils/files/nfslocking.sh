#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nfslocking.sh,v 1.1 2003/12/30 03:27:50 jeremy-c-reed Exp $
#

# todo: not tested yet

# PROVIDE: nfslocking
# REQUIRE: nfsd
# BEFORE:  DAEMON

. /etc/rc.subr

arg=$1

start_precmd='checkyesno nfs_server || checkyesno nfs_client ||
		[ -n "$rc_force" ]'
stop_precmd=$start_precmd
status_precmd=$start_precmd

name="statd"
rcvar=$name
command="@PREFIX@/sbin/rpc.${name}"
load_rc_config $name
run_rc_command "$arg"

name="lockd"
rcvar=$name
command="@PREFIX@/rpc.${name}"
load_rc_config $name
run_rc_command "$arg"
