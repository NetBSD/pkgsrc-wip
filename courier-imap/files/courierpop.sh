#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: courierpop.sh,v 1.16 2008/02/19 18:45:14 jlam Exp $
#
# Courier POP3 services daemon
#
# PROVIDE: courierpop
# REQUIRE: authdaemond
# KEYWORD: shutdown

. /etc/rc.subr

name="courierpop"
rcvar=${name}
command="@PREFIX@/sbin/couriertcpd"
ctl_command="@PREFIX@/sbin/pop3d"
pidfile="@COURIER_STATEDIR@/tmp/pop3d.pid"
required_files="@PKG_SYSCONFDIR@/pop3d @PKG_SYSCONFDIR@/pop3d-ssl"

start_precmd="${name}_prestart"
start_cmd="${name}_doit start"
stop_cmd="${name}_doit stop"

mkdir_perms()
{
	dir="$1"; user="$2"; group="$3"; mode="$4"
	@TEST@ -d $dir || @MKDIR@ $dir
	@CHOWN@ $user $dir
	@CHGRP@ $group $dir
	@CHMOD@ $mode $dir
}

courierpop_prestart()
{
	mkdir_perms @COURIER_STATEDIR@/tmp \
		@COURIER_USER@ @COURIER_GROUP@ 0770
}

courierpop_doit()
{
	action=$1
	case $action in
	start)
		for f in $required_files; do
			if [ ! -r "$f" ]; then
				@ECHO@ 1>&2 "$0: WARNING: $f is not readable"
				return 1
			fi
		done

		. @PKG_SYSCONFDIR@/pop3d

		case x$POP3DSTART in
		x[yY]*)
			@ECHO@ "Starting ${name}."
			${ctl_command} $action
                ;;
		esac
		;;
	stop)
		@ECHO@ "Stopping ${name}."
		${ctl_command} $action
		;;
	esac
}

load_rc_config $name
run_rc_command "$1"
