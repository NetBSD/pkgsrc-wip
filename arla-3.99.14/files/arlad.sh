#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: arlad.sh,v 1.1.1.1 2006/01/13 15:51:47 mreriksson Exp $
#
# PROVIDE: arlad
# REQUIRE: beforemountlkm
# KEYWORD: shutdown

. /etc/rc.subr

name="arlad"
rcvar=$name
command="/usr/pkg/libexec/${name}"
command_args="-z /dev/nnpfs0"
required_files="/dev/nnpfs0"

load_rc_config $name
run_rc_command "$1"
