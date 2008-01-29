#!/bin/sh

set -e

############################################################
# user settable variables
if test -z "$PKGSRCDIR"; then
    PKGSRCDIR=/usr/pkgsrc
fi

if test -z "$MAKE"; then
    MAKE=make
fi

############################################################
cd $PKGSRCDIR

tmpfn=/tmp/pkgdirs2info.$$
trap 'rm -f $tmpfn' 0 1 2 15

############################################################
summary_data2summary (){
    awk '
    function normalize (w){
	return toupper(w)
    }

    BEGIN {
	descr_msg = normalize("description:")
    }

    $1 == "prefix" {
	next
    }

    $1 == "index" {
	next
    }

    $1 == "descr" {
	fn = $3
	while (0 < ret = (getline < fn)){
	    print descr_msg "=" $0
	}
	if (ret < 0){
	    printf "reading from `" fn "` failed\n" > "/dev/stderr"
	    exit 1
	}
	next
    }

    NF > 0 {
	hdr = (normalize($1) "=")
	$1 = $2 = ""

	print hdr substr($0, 3)
    }'
}

cd_and_print_summary_data (){
    # $1 - pkgpath
    ( cd $1 && ${MAKE} print-summary-data; ) > "$tmpfn";
}

generate_summary (){
    # general information
    if cd_and_print_summary_data $1 > "$tmpfn"; then
	pkgname=`awk '$1 == "index" {print $3}' "$tmpfn"`
	pkgpath=`awk '$1 == "index" {print $2}' "$tmpfn"`
	echo "PKGNAME=$pkgname"
	echo "PKGPATH=$pkgpath"
	cat "$tmpfn" | summary_data2summary

	# not expanding PLIST yet
	plist_fn=$1/PLIST
	if test -f $plist_fn; then
	    awk '/^[^@]/ {print "PLIST=" $0}' $plist_fn
	fi

	echo '' # empty line - separator 
    else
	printf "Bad package $1, skipped\n" 1>&2
    fi
}

############################################################
if test $# -eq 0; then
    # processing stdin
    while read pkgpath; do
	generate_summary "$pkgpath"
    done
else
    # processing arguments
    for pkgpath in "$@"; do
	generate_summary "$pkgpath"
    done
fi
