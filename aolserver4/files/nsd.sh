#!@RCD_SCRIPTS_SHELL@
#
# 
# PROVIDE: nsd
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="nsd"
rcvar=${name}
command="@PREFIX@/bin/${name}"
required_files="@PKG_SYSCONFDIR@/nsd.tcl"
nsd_flags="-t @PKG_SYSCONFDIR@/nsd.tcl -u nsadmin -g nsadmin"
nsd_user="root"

# set defaults
if [ -r /etc/rc.conf ]
then
        . /etc/rc.conf
else
        eval ${rcvar}=YES
fi

nsd_doit ()
{

	case $1 in
	start)		@ECHO@ "Starting ${name}." ;;
	stop)		@ECHO@ "Stopping ${name}." ;;
	restart)	@ECHO@ "Restarting ${name}." ;;
	esac

	${command} ${nsd_flags}
}

if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	nsd_doit "$1"
fi
