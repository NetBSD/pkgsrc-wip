#!/bin/sh
#
# $FreeBSD: ports/mail/quickml/files/quickml.in,v 1.2 2010/02/13 21:17:42 dougb Exp $
#

# PROVIDE: quickml
# REQUIRE: LOGIN
#
# Add the following lines to /etc/rc.conf.local or /etc/rc.conf
# to enable this service:
#
# quickml=YES

#. /etc/rc.subr
#
#name="quickml"
#rcvar=$name
#
#command="@PREFIX@/sbin/${name}-ctl"
#run_rc_command "$1"



name="quickml"
command="/usr/pkg/sbin/${name}-ctl"
$command "$1"
