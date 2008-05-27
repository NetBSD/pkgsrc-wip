#!/bin/sh

##
## Service - A tool to handle rc.d startup scripts.
##
##  Adam Hoka, 2008
##

# the directory where init scripts reside
#
RCDIR="/etc/rc.d/"

# chech if we are root
#
if [ "$(id -u)" -ne 0 ]; then
	echo "${0##*/}: only root can use ${0##*/}" 1>&2
	exit 125
fi

# show usage if no arguments were given
#
if [ $# -eq 0 ]; then
	echo "Usage: ${0##*/} [ service ] [ command ]" 1>&2
	exit 126
fi

# try to sanitize the environment
# XXX im not sure if this required
PATH=/sbin:/usr/sbin:/usr/local/sbin:/usr/pkg/sbin:/usr/local/bin:/usr/pkg/bin:/bin:/usr/bin:/usr/X11R6/bin
test -n "$TERM" || TERM=raw
LANG=C
export PATH TERM LANG

# service and command
#
SERVICE=$1
COMMAND=$2

# run the command if it really exists
#
if [ -x $RCDIR$SERVICE ] && [ ! -d $RCDIR$SERVICE ]; then
	env -i TERM=$TERM LANG=$LANG PATH=$PATH "$RCDIR$SERVICE" "$COMMAND"
	exit $?
   else
	echo "${0##*/}: no such service $SERVICE." 1>&2
	exit 127
fi
