#!/bin/sh
#
# $NetBSD: shaper.sh,v 1.1.1.1 2004/10/18 13:01:08 poppnk Exp $
#

# PROVIDE: shaper
# REQUIRE: network
# KEYWORD: shutdown

. /etc/rc.subr

name="shaper"
rcvar=$name
command="@PREFIX@/sbin/shapecfg"
required_files="@PKG_SYSCONFDIR@/shaper.conf"

. @PREFIX@/etc/shaper.conf

shaper_start()
{
	for A in ${IFLIMIT} ; do
		IF=`echo ${A} | awk -F : '{print $1; }'`
		LI=`echo ${A} | awk -F : '{print $2; }'`
		echo "Shaping eth${IF} as shaper${IF} to ${LI}Bps."
		@PREFIX@/sbin/shapecfg attach shaper${IF} eth${IF}
		@PREFIX@/sbin/shapecfg speed shaper${IF} ${LI}
	done
}

shaper_stop()
{
	for A in ${IFLIMIT} ; do
		IF=`echo ${A} | awk -F : '{print $1; }'`
		ifconfig shaper${IF} down
	done
}

start_cmd="shaper_start"
stop_cmd="shaper_stop"

load_rc_config $name
run_rc_command "$1"
