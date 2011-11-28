# -*- mode: sh; -*-

#
# Public domain
#
# Written by Aleksey Cheusov <vle@gmx.net>

sig_handler (){
    on_exit
    trap - "$1"
    kill -"$1" $$
}

trap "sig_handler INT"  INT
trap "sig_handler QUIT" QUIT
trap "sig_handler TERM" TERM
trap "on_exit" 0

#LIBEXECDIR=${LIBEXECDIR-@libexecdir@}
#. ${LIBEXECDIR}/sig_handler.sh
