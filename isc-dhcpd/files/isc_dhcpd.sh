#!/bin/sh
#
# $NetBSD: isc_dhcpd.sh,v 1.5 2004/07/08 15:12:25 jeremy-c-reed Exp $
# $Id: isc_dhcpd.sh,v 1.5 2004/07/08 15:12:25 jeremy-c-reed Exp $

# PROVIDE: dhcpd
# REQUIRE: DAEMON
# BEFORE:  LOGIN

. /etc/rc.subr

name="dhcpd"
rcvar="isc_dhcpd"
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/dhcp/${name}.conf @VARBASE@/db/dhcp/${name}.leases"

load_rc_config $name
run_rc_command "$1"
