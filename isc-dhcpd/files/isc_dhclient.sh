#!/bin/sh
#
# $NetBSD: isc_dhclient.sh,v 1.1 2004/04/18 17:22:13 mpasternak Exp $
# $Id: isc_dhclient.sh,v 1.1 2004/04/18 17:22:13 mpasternak Exp $

# PROVIDE: dhclient
# REQUIRE: network mountcritlocal
# BEFORE:  NETWORKING
#
#	Note that there no syslog logging of dhclient messages at boot because
#	dhclient needs to start before services that syslog depends upon do.
#

. /etc/rc.subr

name="dhclient"
rcvar="isc_dhclient"
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"
