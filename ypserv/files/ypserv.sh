#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ypserv.sh,v 1.1 2004/01/27 23:38:15 jeremy-c-reed Exp $
#

# PROVIDE: ypserv
# REQUIRE: portmap

. /etc/rc.subr

name="ypserv"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_vars="portmap"
start_precmd="ypserv_precmd"

ypserv_precmd()
{
	_domain=`domainname`
	if [ -z "$_domain" ]; then
		warn "domainname(1) is not set."
		return 1
	fi

	if [ ! -d /var/yp/$_domain/. ]; then
		warn "/var/yp/$_domain is not a directory."
		return 1
	fi
}

load_rc_config $name
run_rc_command "$1"
