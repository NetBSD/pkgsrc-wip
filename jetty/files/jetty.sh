#! @RCD_SCRIPTS_SHELL@
#
# $NetBSD: jetty.sh,v 1.1.1.1 2006/07/17 20:47:29 unex_linija Exp $
#
# PROVIDE: jetty
# REQUIRE: DAEMON
#
# To start jetty at startup, copy this script to /etc/rc.d and set
# jetty=YES in /etc/rc.conf.

JETTY_HOME=@JETTY_HOME@

if [ -z "${JAVA_HOME}" ]
then
	JAVA_HOME="@JAVA_HOME@"
	export JAVA_HOME
fi

name="jetty"
rcvar=$name

# set defaults
if [ -r /etc/rc.conf ]
then
	. /etc/rc.conf
else
	eval ${rcvar}=YES
fi

# $flags from environment overrides ${rcvar}_flags
if [ -n "${flags}" ]
then
	eval ${rcvar}_flags="${flags}"
fi

CLASSPATH=${CLASSPATH}:${JETTY_HOME}/lib/org.mortbay.jetty.jar:${JETTY_HOME}/lib/javax.servlet.jar:${JETTY_HOME}/ext/jasper-runtime.jar:${JETTY_HOME}/ext/jasper-compiler.jar:${JETTY_HOME}/ext/xercesImpl.jar
export CLASSPATH

cmd=${1:-start}

checkyesno()
{
	eval _value=\$${1}
	case $_value in
	[Yy][Ee][Ss]|[Tt][Rr][Uu][Ee]|[Oo][Nn]|1)	return 0 ;;
	[Nn][Oo]|[Ff][Aa][Ll][Ss][Ee]|[Oo][Ff][Ff]|0)	return 1 ;;
	*)
		echo "\$${1} is not set properly."
		return 1
		;;
	esac
}

case ${cmd} in
start)
	echo "Starting ${name}."
	cd ${JETTY_HOME} && nohup ${JAVA_HOME}/bin/java -Djetty.home=${JETTY_HOME} -jar start.jar >/dev/null &
	;;
stop)
	echo "Stopping ${name}."
	cd ${JETTY_HOME} && nohup ${JAVA_HOME}/bin/java -Djetty.home=${JETTY_HOME} -jar stop.jar >/dev/null &
	;;
restart)
	$0 stop
	sleep 5
	$0 start
	;;
*)
	echo 1>&2 "Usage: $0 [start|restart|stop]"
	exit 1
	;;
esac
exit 0
