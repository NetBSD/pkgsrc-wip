#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: isc_dhcpd.sh,v 1.6 2005/03/03 11:02:26 hfath Exp $
# $Id: isc_dhcpd.sh,v 1.6 2005/03/03 11:02:26 hfath Exp $

# PROVIDE: dhcpd
# REQUIRE: DAEMON
# BEFORE:  LOGIN

if [ -f /etc/rc.subr ]; then
        . /etc/rc.subr
fi

name="dhcpd"
rcvar="isc_dhcpd"
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/dhcp/${name}.conf @VARBASE@/db/dhcp/${name}.leases"

if [ -f /etc/rc.subr ]; then
        load_rc_config $name
        run_rc_command "$1"
else
        @ECHO@ -n " ${name}"
        ${command} ${isc_dhcpd_flags}
fi
