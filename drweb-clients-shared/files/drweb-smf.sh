#!/bin/sh
#
# $NetBSD: drweb-smf.sh,v 1.3 2003/09/14 00:43:09 bubuchka Exp $

# PROVIDE: drwebsmf
# REQUIRE: DAEMON
# BEFORE: LOGIN

. @RCD_SUBR@

name="drwebsmf"
rcvar=$name
command="@PREFIX@/sbin/drweb-smf"
procname="${command}"
start_precmd="drwebsmf_clean"
required_files="@PKG_SYSCONFDIR@/drweb-smf.conf"

drwebsmf_clean()
{
	if [ -e @DRW_SMF_SOCKFILE@ ]; then
		rm -f @DRW_SMF_SOCKFILE@
	fi
}

load_rc_config $name
run_rc_command "$1"
