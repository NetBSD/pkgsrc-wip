#!@SH@
#
# $NetBSD: drweb-smf.sh,v 1.5 2003/10/27 20:26:59 bubuchka Exp $

# PROVIDE: drweb_smf
# REQUIRE: DAEMON
# BEFORE: LOGIN

. @RCD_SUBR@

name="drweb_smf"
rcvar=$name
command="@PREFIX@/sbin/drweb-smf"
procname="${command}"
start_precmd="drweb_smf_clean"
required_files="@PKG_SYSCONFDIR@/drweb-smf.conf"

drweb_smf_clean()
{
	if [ -e @DRW_SMF_SOCKFILE@ ]; then
		rm -f @DRW_SMF_SOCKFILE@
	fi
}

load_rc_config $name
run_rc_command "$1"
