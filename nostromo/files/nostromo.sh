#!/bin/sh
#
# $NetBSD: nostromo.sh,v 1.1 2011/03/24 16:28:42 astforge Exp $
#

# PROVIDE: nostromo
# REQUIRE: DAEMON

. /etc/rc.subr

name="nostromo"
rcvar=$name
command="/usr/pkg/sbin/nhttpd"
required_files="/usr/pkg/nostromo/conf/nhttpd.conf"

load_rc_config $name
run_rc_command "$1"
