#!/bin/sh
#
# $NetBSD: dnsmasq.sh,v 1.1.1.1 2003/07/24 14:16:32 poppnk Exp $
#

# PROVIDE: dnsmasq
# REQUIRE: DAEMON SERVERS

. /etc/rc.subr

name="dnsmasq"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"

load_rc_config $name
run_rc_command "$1"

