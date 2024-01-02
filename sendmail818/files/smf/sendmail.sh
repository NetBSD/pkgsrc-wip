#!/sbin/sh
#
# $NetBSD: sendmail.sh,v 1.1 2016/12/16 16:07:29 hans Exp $
#
# CDDL HEADER START
#
# The contents of this file are subject to the terms of the
# Common Development and Distribution License (the "License").
# You may not use this file except in compliance with the License.
#
# You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
# or http://www.opensolaris.org/os/licensing.
# See the License for the specific language governing permissions
# and limitations under the License.
#
# When distributing Covered Code, include this CDDL HEADER in each
# file and include the License file at usr/src/OPENSOLARIS.LICENSE.
# If applicable, add the following below this CDDL HEADER, with the
# fields enclosed by brackets "[]" replaced with your own identifying
# information: Portions Copyright [yyyy] [name of copyright owner]
#
# CDDL HEADER END
#
# Copyright 2009 Sun Microsystems, Inc.  All rights reserved.
# Use is subject to license terms.

. /lib/svc/share/smf_include.sh
. @PREFIX@/lib/svc/method/sendmail_include

ERRMSG1='WARNING: /var/mail is NFS-mounted without setting actimeo=0,'
ERRMSG2='this can cause mailbox locking and access problems.'
SERVER_PID_FILE="@VARBASE@/run/sendmail.pid"
ALIASES_FILE="/etc/mail/aliases"
SENDMAIL_CF="/etc/mail/sendmail.cf"

case "$1" in 
'refresh')
        [ -f $SERVER_PID_FILE ] && kill -1 `head -1 $SERVER_PID_FILE`
        ;;

'start')
	exist_or_exit $SENDMAIL
	if [ ! -d @VARBASE@/spool/mqueue ]; then
		/usr/bin/mkdir -m 0750 @VARBASE@/spool/mqueue
		/usr/bin/chown root:bin @VARBASE@/spool/mqueue
	fi
	if [ ! -f $ALIASES_FILE.db ] && [ ! -f $ALIASES_FILE.dir ] \
	    && [ ! -f $ALIASES_FILE.pag ]; then
		@PREFIX@/bin/newaliases
	fi
	MODE="-bd"
	[ -f $DEFAULT_FILE ] && . $DEFAULT_FILE
	#
	# * MODE should be "-bd" or null (MODE= or MODE="") or
	#   left alone.  Anything else and you're on your own.
	# * QUEUEOPTION should be "p" or null (as above).
	# * QUEUEINTERVAL should be set to some legal value;
	#   sanity checks are done below.
	# * OPTIONS are catch-alls; set with care.
	#
	if [ -n "$QUEUEOPTION" -a "$QUEUEOPTION" != "p" ]; then
		QUEUEOPTION=""
	fi
	if [ -z "$QUEUEOPTION" -o -n "$QUEUEINTERVAL" ]; then
		check_queue_interval_syntax $QUEUEINTERVAL
		QUEUEINTERVAL=$answer
	fi

	local=`/usr/bin/svcprop -p config/local_only $SMF_FMRI 2>/dev/null`
	if [ $? -eq 0 -a "$local" = "true" ]; then
		MODE="-bl"
	fi
	sendmail_path=`svcprop -p config/path_to_sendmail_mc $SMF_FMRI \
	    2>/dev/null`
	if [ $? -eq 0 -a -n "$sendmail_path" ]; then
		turn_m4_crank "$SENDMAIL_CF" "$sendmail_path"
	fi
	exist_or_exit "$SENDMAIL_CF"

	$SENDMAIL $MODE -q$QUEUEOPTION$QUEUEINTERVAL $OPTIONS &

	#
	# ETRN_HOSTS should be of the form
	# "s1:c1.1,c1.2        s2:c2.1 s3:c3.1,c3.2,c3.3"
	# i.e., white-space separated groups of server:client where
	# client can be one or more comma-separated names; N.B. that
	# the :client part is optional; see etrn(1M) for details.
	# server is the name of the server to prod; a mail queue run
	# is requested for each client name.  This is comparable to
	# running "/usr/lib/sendmail -qRclient" on the host server.
	#
	# See RFC 1985 for more information.
	#
	for i in $ETRN_HOSTS; do
		SERVER=`echo $i | /usr/bin/sed -e 's/:.*$//'`
		CLIENTS=`echo $i | /usr/bin/sed -n -e 's/,/ /g' \
		    -e '/:/s/^.*://p'`
		/usr/sbin/etrn -b $SERVER $CLIENTS >/dev/null 2>&1 &
	done

	if /usr/bin/nawk 'BEGIN{s = 1}
	    $2 == "/var/mail" && $3 == "nfs" && $4 !~ /actimeo=0/ &&
	    $4 !~ /noac/{s = 0} END{exit s}' /etc/mnttab; then

		/usr/bin/logger -p mail.crit "$ERRMSG1"
		/usr/bin/logger -p mail.crit "$ERRMSG2"
	fi
	;;

'stop')
	[ -f $SERVER_PID_FILE ] && check_and_kill $SERVER_PID_FILE
	# Need to kill the entire service contract to kill all sendmail related
	# processes
	smf_kill_contract $2 TERM 1 30
	ret=$?
	[ $ret -eq 1 ] && exit 1

	# Since sendmail spawns user processes out of .forward files, it is
	# possible that some of these are not responding to TERM.  If the
	# contract did not empty after TERM, move on to KILL.
	if [ $ret -eq 2 ] ; then
		smf_kill_contract $2 KILL 1
	fi
	;;

*)
	echo "Usage: $0 { start | stop | refresh }"
	exit 1
	;;
esac
exit 0
