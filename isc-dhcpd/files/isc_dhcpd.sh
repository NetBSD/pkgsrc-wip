#!/bin/sh
#
# $NetBSD: isc_dhcpd.sh,v 1.3 2004/04/18 20:18:15 mpasternak Exp $
# $Id: isc_dhcpd.sh,v 1.3 2004/04/18 20:18:15 mpasternak Exp $

# PROVIDE: dhcpd
# REQUIRE: DAEMON
# BEFORE:  LOGIN

. /etc/rc.subr

name="dhcpd"
rcvar="isc_dhcpd"
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PREFIX@/etc/dhcp/${name}.conf /var/db/dhcp/${name}.leases"

load_rc_config $name
run_rc_command "$1"
