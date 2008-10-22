#!/bin/sh

srcdir=..
tmpdir=.

export AWKPATH="`pwd`/$srcdir"

print_args (){
#    echo "$@"
    for i in "$@"; do
	printf " '%s'" "$i"
    done
}

runtest (){
    echo '--------------------------------------------------'
    printf '%s' '------- args:'
    print_args "$@"
    printf '\n'

    prog="../$1"
    shift

    "$prog" "$@" 2>&1
}

runtest pkg_grep_summary PKGNAME 'fvalue ~ /^d/' < src_summary.txt
