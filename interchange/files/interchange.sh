#! /bin/sh
#
# $NetBSD: interchange.sh,v 1.1.1.1 2004/01/26 18:32:55 schnoebe Exp $
#
# PROVIDE: interchange
# REQUIRE: DAEMON

name="interchange"
userid="@ICUSER@"
groupid="@ICGROUP@"
command="@PREFIX@/interchange/bin/interchange"
pidfile="/var/run/interchange.pid"
rundir="/var/run/interchange"
confdir="@PREFIX@/interchange"
conffile="@PREFIX@/etc/interchange.cfg"
logfile="/var/log/interchange.log"
command_args="--quiet \
		--configfile ${conffile} \
		--pidfile ${pidfile} \
		--logfile ${logfile} \
		--confdir ${rundir} \
		PIDFile=${pidfile} \
		ErrorFile=${logfile} \
		SocketPerms=0660 \
		SocketFile=/var/run/interchange/socket"

cmd=${1:-start}

case ${cmd} in
start)
	if [ -x ${command} -a -f ${conffile} ]; then
		echo "Starting ${name}."
		if [ -d ${rundir} ] ; then
		    :
		else
		    mkdir -p ${rundir}
		fi
		touch ${logfile} ${pidfile}
		chown ${userid}.${groupid} ${logfile} ${pidfile} ${rundir}
		chmod 644 ${logfile} ${pidfile}
		chmod 755 ${rundir}
		su ${userid} -c "${command} ${command_args} --start"
	fi
	;;
stop)
	if [ -x ${command} -a -f ${pidfile} ]; then
		echo "Stopping ${name}."
		su ${userid} -c "${command} ${command_args} --stop"
	fi
	;;
restart)
	( $0 stop )
	sleep 5
	$0 start
	;;
*)
	if [ -x ${command} ]; then
		su ${userid} -c "${command} ${command_args} ${cmd}"
	fi
	;;
esac
exit 0
