#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: spawnfcgi.sh,v 1.1.1.1 2009/04/29 15:51:24 mjoellnir Exp $
#
# FastCGI process spawner
#

# PROVIDE: spawn-fcgi
# REQUIRE: DAEMON
# BEFORE:  LOGIN

if [ -f /etc/rc.subr ]; then
  . /etc/rc.subr
fi

name="spawnfcgi"
rcvar=${name}
command="@PREFIX@/bin/spawn-fcgi"
start_precmd="spawnfcgi_start_precmd"
stop_postcmd="spawnfcgi_stop_postcmd"
load_rc_config $name

pidfile="${spawnfcgi_pidfile:=@VARBASE@/run/spawnfcgi.pid}"
fcgiapp="${spawnfcgi_app:=@PREFIX@/libexec/cgi-bin/php}"
fcgiip="${spawnfcgi_ip:=127.0.0.1}"
fcgiport="${spawnfcgi_port:=9999}"
fcgiuser="${spawnfcgi_user:=www}"
fcgigroup="${spawnfcgi_group:=www}"

spawnfcgi_children="${spawnfcgi_children:=10}"

if /bin/test "`echo ${fcgiapp} | grep php`" = "${fcgiapp}" ; then
  fcgichildren="-C ${spawnfcgi_children}"
  procname=${fcgiapp}
else
  fcgichildren="-F ${spawnfcgi_children}"
fi

if /bin/test -n "${spawnfcgi_chroot}"; then
  fcgichroot="-c ${spawnfcgi_chroot}"
else
  fcgichroot=""
fi


spawnfcgi_start_precmd() {
  touch ${pidfile}
  chown ${fcgiuser}:${fcgigroup} ${pidfile}
}

spawnfcgi_stop_postcmd() {
  rm ${pidfile}
}


spawnfcgi_flags="-f ${fcgiapp} ${fcgichildren} -a ${fcgiip} -p ${fcgiport} -P ${pidfile} -u ${fcgiuser} -g ${fcgigroup} ${fcgichroot}" 

run_rc_command "$1"
