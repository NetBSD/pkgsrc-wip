#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: rsyslogd.sh,v 1.1.1.1 2011/04/18 13:46:22 bartoszkuzma Exp $
# NetBSD: syslogd,v 1.15 2004/10/11 13:29:52 lukem Exp
#

# PROVIDE: rsyslogd
# REQUIRE: mountcritremote sysdb wscons
# BEFORE:  SERVERS

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="rsyslogd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/rsyslog.conf"
start_precmd="rsyslogd_precmd"
extra_commands="reload"

_sockfile="/var/run/syslogd.sockets"

rsyslogd_precmd()
{
	#	Transitional symlink for old binaries
	#
	if [ ! -h /dev/log ]; then
		ln -sf /var/run/log /dev/log
	fi

	#	Create default list of syslog sockets to watch
	#
	( umask 022 ; > $_sockfile )

	#	Find /etc/rc.d scripts with "chrootdir" rcorder(8) keyword,
	#	and if $${app}_chrootdir is a directory, add appropriate
	#	syslog socket to list of sockets to watch.
	#
	for _lr in $(rcorder -k chrootdir /etc/rc.d/*); do
	    (
		_l=${_lr##*/}
		load_rc_config ${_l}
		eval _ldir=\$${_l}_chrootdir
		if checkyesno $_l && [ -n "$_ldir" ]; then
			echo "${_ldir}/var/run/log" >> $_sockfile
		fi
	    )
	done

	#	If other sockets have been provided, change run_rc_command()'s
	#	internal copy of $rsyslogd_flags to force use of specific
	#	syslogd sockets.
	#
	if [ -s $_sockfile ]; then
		echo "/var/run/log" >> $_sockfile
		rc_flags="-P $_sockfile $rc_flags"
	fi

	return 0
}

load_rc_config $name
run_rc_command "$1"
