#!/bin/sh

LC_ALL=C
export LC_ALL

DIFF_PROG=${DIFF_PROG-diff -U20}

#
srcdir="`pwd`/.."
if test "$OBJDIR"; then
    objdir=${OBJDIR}
else
    objdir='.'
fi

#
if test -z "$BMAKE"; then
    BMAKE=/usr/bin/make
fi

AWKPATH="$srcdir:$OBJDIR"
PATH=$OBJDIR:$PATH

PSS_MKSCRIPTSDIR="${srcdir}"
LIBEXECDIR="${OBJDIR}"

export BMAKE AWKPATH PATH PSS_MKSCRIPTSDIR AWKPATH LIBEXECDIR

#
print_args (){
    for i in "$@"; do
	printf " '%s'" "$i"
    done
}

runtest (){
    prog="$objdir/$1"
    shift

    "$prog" "$@" 2>&1
}

grep_PKGNAME_n_PKGBASE_only (){
    grep -E '^(PKGNAME|PKGPATH)=|^$|^-' "$@"
}

tmpdir="/tmp/psu-test.$$"
mkdir -m 0700 "$tmpdir" || exit 60

tmpfn1="$tmpdir/1"
tmpfn2="$tmpdir/2"
tmpfn3="$tmpdir/3"
tmpfn4="$tmpdir/4"
tmpex="$tmpdir/5"

trap "rm -rf $tmpdir" 0 INT QUIT TERM HUP

echo > $tmpex

cmp (){
    # $1 - progress message
    # $2 - expected text
    printf '    %s... ' "$1" 1>&2

    cat > "$tmpfn2"
    printf '%s' "$2" > "$tmpfn1"

    if $DIFF_PROG "$tmpfn1" "$tmpfn2" > "$tmpfn3"; then
	echo ok
    else
	echo FAILED
	awk '{print "   " $0}' "$tmpfn3"
	rm -f $tmpex
    fi
}

# real tests
tests='
pkgsrc-dewey
pkg_summary2leaves
pkg_grep_summary
pkg_list_all_pkgs
pkg_refresh_summary
pkg_summary4view
pkg_uniq_summary
pkg_src_summary
pkg_assignments2pkgpath
pkg_src_fetch_var
pkg_micro_src_summary
pkg_cmp_summary
pkg_summary2deps
pkg_lint_summary
pkg_subgraph_deps
pkg_bin_summary
pkg_digger_backend
'

normalize_version (){
     awk '
    /^PKGNAME=/ {
        gsub(/(nb|alpha|beta|pre|rc|pl)[0-9]+$/, "")
        gsub(/[a-zA-Z]$/, "")
        gsub(/-[^-]*$/, "-X")
    }
    {  print $0  }' "$@"
}

for t in $tests; do
    . ./test_$t.sh
done

test -f "$tmpex"
exit $?
