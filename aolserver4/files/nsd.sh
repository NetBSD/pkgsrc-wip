#!@RCD_SCRIPTS_SHELL@
#
# 

. /etc/rc.subr

name="nsd"
rcvar=${name}
command="@PREFIX@/bin/${name}"
nsd_flags="-t @PKG_SYSCONFDIR@/nsd.tcl -u nsadmin -g nsadmin"
nsd_user="root"

# set defaults
if [ -r /etc/rc.conf ]
then
        . /etc/rc.conf
else
        eval ${rcvar}=YES
fi

run_rc_command "$1"
