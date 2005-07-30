#!/bin/sh
#
# $NetBSD: acpid.sh,v 1.2 2005/07/30 18:07:12 poppnk Exp $
#

# PROVIDE: acpid
# REQUIRE: DAEMON

. /etc/rc.subr

name="acpid"
rcvar=$name
command="@PREFIX@/sbin/${name}"
command_args="-c @PKG_SYSCONFDIR@/acpid/"

load_rc_config $name
run_rc_command "$1"
