#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ypbind.sh,v 1.1 2004/01/27 23:46:30 jeremy-c-reed Exp $
#

# PROVIDE: ypbind
# REQUIRE: ypserv
# BEFORE:  DAEMON

. /etc/rc.subr

name="ypbind"
rcvar=$name
command="@PREFIX@/sbin/${name}"
start_precmd="ypbind_precmd"

ypbind_precmd()
{
	_domain=`domainname`
	if [ -z "$_domain" ]; then
		warn "domainname(1) is not set."
		return 1
	fi
}

load_rc_config $name
run_rc_command "$1"
