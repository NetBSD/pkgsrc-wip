#!/bin/sh
#
# $NetBSD: ftpdtls.sh,v 1.1.1.1 2004/12/28 09:34:03 imilh Exp $
#

. /etc/rc.subr

name="ftpdtls"
rcvar=${name}

# having a - causes an error on rcvar
ftpd_tls="ftpd-tls"
command="@PREFIX@/libexec/${ftpd_tls}"

# run in daemon mode by default
command_args="-D"
pidfile="/var/run/${ftpd_tls}.pid"

load_rc_config $name
run_rc_command "$1"
