#!/bin/sh
#
# $NetBSD: cvsd.sh,v 1.1.1.1 2003/06/22 03:58:15 schnoebe Exp $
#
# PROVIDE: cvsd
# REQUIRE: DAEMON

if [ -e /etc/rc.subr ]
then
       . /etc/rc.subr
fi

name="cvsd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
required_files="@PREFIX@/etc/${name}.conf"
pidfile=$(awk '/^#/ {next}; /PidFile/ {print $2}' ${required_files})
# pidfile=/var/run/cvsd.pid
command_args=""              
                               # add more flags through ${${name}_flags}

if [ -e /etc/rc.subr ]
then
       load_rc_config $name
       run_rc_command "$1"
else
       echo -n ' ${name}'
       ${command} ${cvsd_flags} ${command_args}
fi
