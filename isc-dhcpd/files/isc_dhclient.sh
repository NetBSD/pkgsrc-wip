#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: isc_dhclient.sh,v 1.3 2005/03/03 11:02:26 hfath Exp $
# $Id: isc_dhclient.sh,v 1.3 2005/03/03 11:02:26 hfath Exp $

# PROVIDE: dhclient
# REQUIRE: network mountcritlocal
# BEFORE:  NETWORKING
#
#	Note that there no syslog logging of dhclient messages at boot because
#	dhclient needs to start before services that syslog depends upon do.
#

if [ -f /etc/rc.subr ]; then
        . /etc/rc.subr
fi

name="dhclient"
rcvar="isc_dhclient"
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
        run_rc_command "$1"
else
        @ECHO@ -n " ${name}"
        ${command} ${isc_dhclient_flags}
fi
