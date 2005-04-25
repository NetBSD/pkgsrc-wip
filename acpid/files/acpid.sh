#!/bin/sh
#
# $NetBSD: acpid.sh,v 1.1 2005/04/25 13:36:33 poppnk Exp $
#

# PROVIDE: acpid
# REQUIRE: DAEMON

. /etc/rc.subr

name="acpid"
rcvar=$name
command="@PREFIX@/sbin/${name}"
command_args="-c @PKG_SYSCONFDIR@/acpid/"

run_rc_command "$1"
