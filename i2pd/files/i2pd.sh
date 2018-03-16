#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD $
#
# PROVIDE: i2pd
# REQUIRE: DAEMON NETWORKING
# KEYWORD: shutdown
#
# Variables in rc.conf to enable i2pd:
# 
# i2pd=YES

if test -f /etc/rc.subr
then
	. /etc/rc.subr
fi

name="i2pd"
rcvar=$name
command="@PREFIX@/bin/i2pd"
required_files="@PKG_SYSCONFIG@/i2pd.conf"
i2pd_user="i2pd"
i2pd_group="i2pd"
i2pd_flags="--conf=@PKG_SYSCONFIG@/i2pd.conf"
stop_cmd="i2pd_stop"

i2pd_stop()
{
	kill -INT `cat /var/run/i2pd/i2pd.pid`
}
