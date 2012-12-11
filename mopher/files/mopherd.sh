#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: mopherd.sh,v 1.2 2012/12/11 00:39:45 pebog Exp $
#
# PROVIDE: mopherd
# REQUIRE: DAEMON
# BEFORE:  mail

$_rc_subr_loaded . /etc/rc.subr

name=mopherd
rcvar=mopherd
pidfile=@MOPHER_RUN@/mopherd.pid
start_precmd=${name}_precmd
command=@PREFIX@/sbin/mopherd
command_args="-p $pidfile"

mopherd_precmd()
{
	@INSTALL@ -d -o @MOPHER_USER@ -g @MOPHER_GROUP@ @MOPHER_RUN@
}

load_rc_config mopherd
run_rc_command "$1"
