#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nfsd.sh,v 1.1 2003/12/30 03:27:50 jeremy-c-reed Exp $
#

# PROVIDE: nfsd
# REQUIRE: mountd

. /etc/rc.subr

name="nfsd"
rcvar="nfs_server"
command="@PREFIX@/sbin/rpc.${name}"
required_vars="mountd portmap"

load_rc_config $name
run_rc_command "$1"
