#!/bin/sh
#
# $NetBSD: xtreemfs_dir.sh,v 1.1.1.1 2011/11/08 01:42:14 tnn2 Exp $
#

# PROVIDE: xtreemfs_dir
# REQUIRE: DAEMON NETWORKING
# BEFORE:  xtreemfs_mrc

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
elif [ -f @PREFIX@/etc/rc.subr ]; then
	. @PREFIX@/etc/rc.subr
else
	echo "$0: error: Please install pkgtools/rc.subr" 1>&2
	exit 1
fi

name="xtreemfs_dir"

rcvar="${name}"
pidfile="@VARBASE@/run/${name}.pid"
logfile="@VARBASE@/log/xtreemfs/${name}.log"
xtreemfs_dir_user="@XTREEMFS_USER@"
xtreemfs_dir_env="CLASSPATH=@CLASSPATH@"
command="@JAVA@"
command_args="org.xtreemfs.dir.DIR @PKG_SYSCONFDIR@/dirconfig.properties >> ${logfile} 2>&1 < /dev/null & echo \\\$! > ${pidfile}"
start_precmd="touch ${logfile} ${pidfile}; chown @XTREEMFS_USER@ ${pidfile} ${logfile}"

load_rc_config $name
run_rc_command "$1"
