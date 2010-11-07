#!/bin/sh

LC_ALL=C
export LC_ALL

DIFF_PROG=${DIFF_PROG-diff -u}

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
PKGSRCDIR="`pwd`/../../../.."

AWKPATH="$srcdir:$OBJDIR"
PATH=$OBJDIR:$PATH

PSS_MKSCRIPTSDIR="${srcdir}"
LIBEXECDIR="${OBJDIR}"

export PKGSRCDIR BMAKE AWKPATH PATH PSS_MKSCRIPTSDIR AWKPATH LIBEXECDIR

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

# pkgsrc-dewey.awk
AWKPATH=`pwd`/.. ./pkgsrc-dewey-test < ./pkgsrc-dewey-test.txt 2>&1 |
cmp 'pkgsrc-dewey.awk' ''

# pkg_grep_summary
runtest pkg_grep_summary -s PKGBASE distbb < src_summary.txt |
cmp 'pkg_grep_summary #1' \
'PKGNAME=distbb-0.22.0
PKGPATH=wip/distbb
DEPENDS=pkg_summary-utils>=0.18.1:../../wip/pkg_summary-utils paexec>=0.10.0:../../wip/paexec runawk>=0.13.0:../../wip/runawk
BUILD_DEPENDS= checkperms>=1.1:../../sysutils/checkperms
HOMEPAGE=http://mova.org/~cheusov/pub/distbb/
COMMENT=DISTributed Bulk Build tool for pkgsrc
MAINTAINER=cheusov@tut.by
CATEGORIES=pkgtools
EXFIELD=XVALUE1

'

runtest pkg_grep_summary -m PKGBASE '^dict' < src_summary.txt |
cmp 'pkg_grep_summary #2' \
'PKGPATH=textproc/dictem
DEPENDS=dict-client>=1.9.14:../../textproc/dict-client emacs>=22:../../editors/emacs  emacs>=22:../../editors/emacs
BUILD_DEPENDS= checkperms>=1.1:../../sysutils/checkperms
CONFLICTS=xemacs-dictem-[0-9]*
HOMEPAGE=http://freshmeat.net/projects/dictem/
COMMENT=Dictionary client (RFC-2229) for [X]Emacs
MAINTAINER=cheusov@tut.by
CATEGORIES=textproc editors
PKGNAME=dictem-0.82

BUILD_DEPENDS= libtool-base>=1.5.18nb5:../../devel/libtool-base gmake>=3.81:../../devel/gmake checkperms>=1.1:../../sysutils/checkperms
PKGNAME=dict-server-1.10.11nb2
PKGPATH=wip/dict-server
DEPENDS=   libmaa>=1.2:../../devel/libmaa
HOMEPAGE=http://www.dict.org/
COMMENT=Dictionary Service Protocol server
MAINTAINER=cheusov@tut.by
CATEGORIES=textproc

PKGNAME=dict-client-1.9.15nb2
PKGPATH=textproc/dict-client
DEPENDS=  libltdl>=1.5.10:../../devel/libltdl
BUILD_DEPENDS= gmake>=3.81:../../devel/gmake checkperms>=1.1:../../sysutils/checkperms
HOMEPAGE=http://www.dict.org/
COMMENT=Dictionary Service Protocol client
MAINTAINER=pkgsrc-users@NetBSD.org
CATEGORIES=textproc

PKGNAME=dict-client-1.10.11nb2
PKGPATH=wip/dict-client
DEPENDS=  libmaa>=1.0:../../devel/libmaa
BUILD_DEPENDS= libtool-base>=1.5.18nb5:../../devel/libtool-base gmake>=3.81:../../devel/gmake checkperms>=1.1:../../sysutils/checkperms
HOMEPAGE=http://www.dict.org/
COMMENT=Dictionary Service Protocol client
MAINTAINER=cheusov@tut.by
CATEGORIES=textproc

'

runtest pkg_grep_summary PKGNAME 'fvalue ~ /^d/' < src_summary.txt |
cmp 'pkg_grep_summary #3' \
'PKGNAME=distbb-0.22.0
PKGPATH=wip/distbb
DEPENDS=pkg_summary-utils>=0.18.1:../../wip/pkg_summary-utils paexec>=0.10.0:../../wip/paexec runawk>=0.13.0:../../wip/runawk
BUILD_DEPENDS= checkperms>=1.1:../../sysutils/checkperms
HOMEPAGE=http://mova.org/~cheusov/pub/distbb/
COMMENT=DISTributed Bulk Build tool for pkgsrc
MAINTAINER=cheusov@tut.by
CATEGORIES=pkgtools
EXFIELD=XVALUE1

PKGPATH=textproc/dictem
DEPENDS=dict-client>=1.9.14:../../textproc/dict-client emacs>=22:../../editors/emacs  emacs>=22:../../editors/emacs
BUILD_DEPENDS= checkperms>=1.1:../../sysutils/checkperms
CONFLICTS=xemacs-dictem-[0-9]*
HOMEPAGE=http://freshmeat.net/projects/dictem/
COMMENT=Dictionary client (RFC-2229) for [X]Emacs
MAINTAINER=cheusov@tut.by
CATEGORIES=textproc editors
PKGNAME=dictem-0.82

BUILD_DEPENDS= libtool-base>=1.5.18nb5:../../devel/libtool-base gmake>=3.81:../../devel/gmake checkperms>=1.1:../../sysutils/checkperms
PKGNAME=dict-server-1.10.11nb2
PKGPATH=wip/dict-server
DEPENDS=   libmaa>=1.2:../../devel/libmaa
HOMEPAGE=http://www.dict.org/
COMMENT=Dictionary Service Protocol server
MAINTAINER=cheusov@tut.by
CATEGORIES=textproc

PKGNAME=dict-client-1.9.15nb2
PKGPATH=textproc/dict-client
DEPENDS=  libltdl>=1.5.10:../../devel/libltdl
BUILD_DEPENDS= gmake>=3.81:../../devel/gmake checkperms>=1.1:../../sysutils/checkperms
HOMEPAGE=http://www.dict.org/
COMMENT=Dictionary Service Protocol client
MAINTAINER=pkgsrc-users@NetBSD.org
CATEGORIES=textproc

PKGNAME=dict-client-1.10.11nb2
PKGPATH=wip/dict-client
DEPENDS=  libmaa>=1.0:../../devel/libmaa
BUILD_DEPENDS= libtool-base>=1.5.18nb5:../../devel/libtool-base gmake>=3.81:../../devel/gmake checkperms>=1.1:../../sysutils/checkperms
HOMEPAGE=http://www.dict.org/
COMMENT=Dictionary Service Protocol client
MAINTAINER=cheusov@tut.by
CATEGORIES=textproc

'

runtest pkg_grep_summary -t awk PKGNAME 'fvalue ~ /^d/' < src_summary.txt |
    grep_PKGNAME_n_PKGBASE_only |
cmp 'pkg_grep_summary #4' \
'PKGNAME=distbb-0.22.0
PKGPATH=wip/distbb

PKGPATH=textproc/dictem
PKGNAME=dictem-0.82

PKGNAME=dict-server-1.10.11nb2
PKGPATH=wip/dict-server

PKGNAME=dict-client-1.9.15nb2
PKGPATH=textproc/dict-client

PKGNAME=dict-client-1.10.11nb2
PKGPATH=wip/dict-client

'

runtest pkg_grep_summary COMMENT \
    'tolower(fvalue) ~ /dictionary.*client/' < src_summary.txt | \
    grep -E 'PKGNAME|---' |
cmp 'pkg_grep_summary #5' \
'PKGNAME=dictem-0.82
PKGNAME=dict-client-1.9.15nb2
PKGNAME=dict-client-1.10.11nb2
'

runtest pkg_grep_summary -e EXFIELD < src_summary.txt | \
    grep -E 'PKGNAME|---' |
cmp 'pkg_grep_summary #6' \
'PKGNAME=dictem-0.82
PKGNAME=pkg_online-0.5.0nb2
PKGNAME=dict-server-1.10.11nb2
PKGNAME=pkg_online-server-0.5.0
PKGNAME=dict-client-1.9.15nb2
PKGNAME=pkg_online-client-0.5.0
PKGNAME=libmaa-1.0.1nb1
PKGNAME=gmake-3.81
PKGNAME=paexec-0.10.0nb1
PKGNAME=libtool-base-1.5.24nb6
PKGNAME=runawk-0.14.3
PKGNAME=emacs-22.1nb6
PKGNAME=pkg_summary-utils-0.18.1
PKGNAME=libungif-4.1.4nb1
PKGNAME=tiff-3.8.2nb4
PKGNAME=x11-links-0.38
PKGNAME=perl-5.8.8nb8
PKGNAME=libltdl-1.5.24
PKGNAME=dict-client-1.10.11nb2
PKGNAME=pipestatus-0.4.0
PKGNAME=awk-pkgsrc-dewey-0.5.6
PKGNAME=png-1.2.32beta01
PKGNAME=netcat-1.10nb2
PKGNAME=pkg-config-0.23
PKGNAME=jpeg-6bnb4
PKGNAME=ap22-vhost-ldap-1.2.0nb1
PKGNAME=ap2-vhost-ldap-1.2.0nb1
'

runtest pkg_grep_summary -t empty EXFIELD '' < src_summary.txt | \
    grep -E 'PKGNAME|---' |
cmp 'pkg_grep_summary #7' \
'PKGNAME=dictem-0.82
PKGNAME=pkg_online-0.5.0nb2
PKGNAME=dict-server-1.10.11nb2
PKGNAME=pkg_online-server-0.5.0
PKGNAME=dict-client-1.9.15nb2
PKGNAME=pkg_online-client-0.5.0
PKGNAME=libmaa-1.0.1nb1
PKGNAME=gmake-3.81
PKGNAME=paexec-0.10.0nb1
PKGNAME=libtool-base-1.5.24nb6
PKGNAME=runawk-0.14.3
PKGNAME=emacs-22.1nb6
PKGNAME=pkg_summary-utils-0.18.1
PKGNAME=libungif-4.1.4nb1
PKGNAME=tiff-3.8.2nb4
PKGNAME=x11-links-0.38
PKGNAME=perl-5.8.8nb8
PKGNAME=libltdl-1.5.24
PKGNAME=dict-client-1.10.11nb2
PKGNAME=pipestatus-0.4.0
PKGNAME=awk-pkgsrc-dewey-0.5.6
PKGNAME=png-1.2.32beta01
PKGNAME=netcat-1.10nb2
PKGNAME=pkg-config-0.23
PKGNAME=jpeg-6bnb4
PKGNAME=ap22-vhost-ldap-1.2.0nb1
PKGNAME=ap2-vhost-ldap-1.2.0nb1
'

runtest pkg_grep_summary -m MAINTAINER 'cheusov|vle@gmx.net' < src_summary.txt |
    grep -E 'PKGNAME|PKGPATH|^$|MAINTAINER|COMMENT' |
cmp 'pkg_grep_summary #8' \
'PKGNAME=distbb-0.22.0
PKGPATH=wip/distbb
COMMENT=DISTributed Bulk Build tool for pkgsrc
MAINTAINER=cheusov@tut.by

PKGPATH=textproc/dictem
COMMENT=Dictionary client (RFC-2229) for [X]Emacs
MAINTAINER=cheusov@tut.by
PKGNAME=dictem-0.82

COMMENT=Client/Server search in pkgsrc packages
MAINTAINER=cheusov@tut.by
PKGNAME=pkg_online-0.5.0nb2
PKGPATH=wip/pkg_online

PKGNAME=dict-server-1.10.11nb2
PKGPATH=wip/dict-server
COMMENT=Dictionary Service Protocol server
MAINTAINER=cheusov@tut.by

PKGNAME=pkg_online-server-0.5.0
PKGPATH=wip/pkg_online-server
COMMENT=Client/Server search in pkgsrc packages (server tools)
MAINTAINER=cheusov@tut.by

PKGNAME=pkg_online-client-0.5.0
PKGPATH=wip/pkg_online-client
COMMENT=Client/Server search in pkgsrc packages (client tools)
MAINTAINER=cheusov@tut.by

PKGNAME=libmaa-1.0.1nb1
PKGPATH=devel/libmaa
COMMENT=Provides a few data structures and helpful functions
MAINTAINER=cheusov@tut.by

PKGNAME=paexec-0.10.0nb1
PKGPATH=wip/paexec
COMMENT=Parallel executor, distributes tasks over network
MAINTAINER=cheusov@tut.by

PKGNAME=runawk-0.14.3
PKGPATH=wip/runawk
COMMENT=Wrapper that impelements modules for AWK
MAINTAINER=cheusov@tut.by

PKGNAME=pkg_summary-utils-0.18.1
PKGPATH=wip/pkg_summary-utils
COMMENT=Utilities for manipulating pkg_summary(5) files
MAINTAINER=cheusov@tut.by

PKGNAME=dict-client-1.10.11nb2
PKGPATH=wip/dict-client
COMMENT=Dictionary Service Protocol client
MAINTAINER=cheusov@tut.by

PKGNAME=pipestatus-0.4.0
PKGPATH=devel/pipestatus
COMMENT=UNIX/POSIX shell helper for running pipes safely
MAINTAINER=cheusov@tut.by

PKGNAME=awk-pkgsrc-dewey-0.5.6
PKGPATH=wip/awk-pkgsrc-dewey
COMMENT=Pkgsrc dewey module for AWK programming language
MAINTAINER=cheusov@tut.by

'

runtest pkg_grep_summary -s PKGPATH graphics/png < src_summary.txt |
cmp 'pkg_grep_summary #9' \
'PKGNAME=png-1.2.32beta01
PKGPATH=graphics/png
BUILD_DEPENDS= libtool-base>=1.5.18nb5:../../devel/libtool-base checkperms>=1.1:../../sysutils/checkperms
HOMEPAGE=http://www.libpng.org/pub/png/
COMMENT=Library for manipulating PNG images
MAINTAINER=wiz@NetBSD.org
CATEGORIES=graphics

'

runtest pkg_grep_summary -s PKGPATHe www/ap22-vhost-ldap:PKG_APACHE=apache22 \
    < src_summary.txt |
cmp 'pkg_grep_summary #10' \
'PKGNAME=ap22-vhost-ldap-1.2.0nb1
ASSIGNMENTS=PKG_APACHE=apache22
HOMEPAGE=http://packages.qa.debian.org/m/mod-vhost-ldap.html
COMMENT=Apache 2.2 module LDAP Virtual Hosts support
MAINTAINER=imil@gcu.info
PKGPATH=www/ap22-vhost-ldap
CATEGORIES=www databases

'

runtest pkg_grep_summary -s PKGPATHe www/ap2-vhost-ldap:PKG_APACHE=apache2 \
    < src_summary.txt |
cmp 'pkg_grep_summary #11' \
'PKGNAME=ap2-vhost-ldap-1.2.0nb1
PKGPATH=www/ap2-vhost-ldap:PKG_APACHE=apache2
HOMEPAGE=http://packages.qa.debian.org/m/mod-vhost-ldap.html
COMMENT=Apache 2 module LDAP Virtual Hosts support
MAINTAINER=imil@gcu.info
CATEGORIES=www databases

'

runtest pkg_grep_summary -s PKGPATH www/ap22-vhost-ldap < src_summary.txt |
cmp 'pkg_grep_summary #12' \
'PKGNAME=ap22-vhost-ldap-1.2.0nb1
ASSIGNMENTS=PKG_APACHE=apache22
HOMEPAGE=http://packages.qa.debian.org/m/mod-vhost-ldap.html
COMMENT=Apache 2.2 module LDAP Virtual Hosts support
MAINTAINER=imil@gcu.info
PKGPATH=www/ap22-vhost-ldap
CATEGORIES=www databases

'

runtest pkg_grep_summary -s PKGPATH www/ap2-vhost-ldap < src_summary.txt |
cmp 'pkg_grep_summary #13' \
'PKGNAME=ap2-vhost-ldap-1.2.0nb1
PKGPATH=www/ap2-vhost-ldap:PKG_APACHE=apache2
HOMEPAGE=http://packages.qa.debian.org/m/mod-vhost-ldap.html
COMMENT=Apache 2 module LDAP Virtual Hosts support
MAINTAINER=imil@gcu.info
CATEGORIES=www databases

'

runtest pkg_grep_summary -S PKGPATH  pkgs.txt < src_summary.txt |
cmp 'pkg_grep_summary #14' \
'PKGNAME=distbb-0.22.0
PKGPATH=wip/distbb
DEPENDS=pkg_summary-utils>=0.18.1:../../wip/pkg_summary-utils paexec>=0.10.0:../../wip/paexec runawk>=0.13.0:../../wip/runawk
BUILD_DEPENDS= checkperms>=1.1:../../sysutils/checkperms
HOMEPAGE=http://mova.org/~cheusov/pub/distbb/
COMMENT=DISTributed Bulk Build tool for pkgsrc
MAINTAINER=cheusov@tut.by
CATEGORIES=pkgtools
EXFIELD=XVALUE1

BUILD_DEPENDS= libtool-base>=1.5.18nb5:../../devel/libtool-base gmake>=3.81:../../devel/gmake checkperms>=1.1:../../sysutils/checkperms
PKGNAME=dict-server-1.10.11nb2
PKGPATH=wip/dict-server
DEPENDS=   libmaa>=1.2:../../devel/libmaa
HOMEPAGE=http://www.dict.org/
COMMENT=Dictionary Service Protocol server
MAINTAINER=cheusov@tut.by
CATEGORIES=textproc

PKGNAME=png-1.2.32beta01
PKGPATH=graphics/png
BUILD_DEPENDS= libtool-base>=1.5.18nb5:../../devel/libtool-base checkperms>=1.1:../../sysutils/checkperms
HOMEPAGE=http://www.libpng.org/pub/png/
COMMENT=Library for manipulating PNG images
MAINTAINER=wiz@NetBSD.org
CATEGORIES=graphics

PKGNAME=ap2-vhost-ldap-1.2.0nb1
PKGPATH=www/ap2-vhost-ldap:PKG_APACHE=apache2
HOMEPAGE=http://packages.qa.debian.org/m/mod-vhost-ldap.html
COMMENT=Apache 2 module LDAP Virtual Hosts support
MAINTAINER=imil@gcu.info
CATEGORIES=www databases

'

runtest pkg_grep_summary -S PKGPATHe pkgs.txt < src_summary.txt |
cmp 'pkg_grep_summary #15' \
'PKGNAME=distbb-0.22.0
PKGPATH=wip/distbb
DEPENDS=pkg_summary-utils>=0.18.1:../../wip/pkg_summary-utils paexec>=0.10.0:../../wip/paexec runawk>=0.13.0:../../wip/runawk
BUILD_DEPENDS= checkperms>=1.1:../../sysutils/checkperms
HOMEPAGE=http://mova.org/~cheusov/pub/distbb/
COMMENT=DISTributed Bulk Build tool for pkgsrc
MAINTAINER=cheusov@tut.by
CATEGORIES=pkgtools
EXFIELD=XVALUE1

BUILD_DEPENDS= libtool-base>=1.5.18nb5:../../devel/libtool-base gmake>=3.81:../../devel/gmake checkperms>=1.1:../../sysutils/checkperms
PKGNAME=dict-server-1.10.11nb2
PKGPATH=wip/dict-server
DEPENDS=   libmaa>=1.2:../../devel/libmaa
HOMEPAGE=http://www.dict.org/
COMMENT=Dictionary Service Protocol server
MAINTAINER=cheusov@tut.by
CATEGORIES=textproc

PKGNAME=png-1.2.32beta01
PKGPATH=graphics/png
BUILD_DEPENDS= libtool-base>=1.5.18nb5:../../devel/libtool-base checkperms>=1.1:../../sysutils/checkperms
HOMEPAGE=http://www.libpng.org/pub/png/
COMMENT=Library for manipulating PNG images
MAINTAINER=wiz@NetBSD.org
CATEGORIES=graphics

'

runtest pkg_grep_summary -t strfile PKGPATH  pkgs.txt < src_summary.txt |
cmp 'pkg_grep_summary #16' \
'PKGNAME=distbb-0.22.0
PKGPATH=wip/distbb
DEPENDS=pkg_summary-utils>=0.18.1:../../wip/pkg_summary-utils paexec>=0.10.0:../../wip/paexec runawk>=0.13.0:../../wip/runawk
BUILD_DEPENDS= checkperms>=1.1:../../sysutils/checkperms
HOMEPAGE=http://mova.org/~cheusov/pub/distbb/
COMMENT=DISTributed Bulk Build tool for pkgsrc
MAINTAINER=cheusov@tut.by
CATEGORIES=pkgtools
EXFIELD=XVALUE1

BUILD_DEPENDS= libtool-base>=1.5.18nb5:../../devel/libtool-base gmake>=3.81:../../devel/gmake checkperms>=1.1:../../sysutils/checkperms
PKGNAME=dict-server-1.10.11nb2
PKGPATH=wip/dict-server
DEPENDS=   libmaa>=1.2:../../devel/libmaa
HOMEPAGE=http://www.dict.org/
COMMENT=Dictionary Service Protocol server
MAINTAINER=cheusov@tut.by
CATEGORIES=textproc

PKGNAME=png-1.2.32beta01
PKGPATH=graphics/png
BUILD_DEPENDS= libtool-base>=1.5.18nb5:../../devel/libtool-base checkperms>=1.1:../../sysutils/checkperms
HOMEPAGE=http://www.libpng.org/pub/png/
COMMENT=Library for manipulating PNG images
MAINTAINER=wiz@NetBSD.org
CATEGORIES=graphics

PKGNAME=ap2-vhost-ldap-1.2.0nb1
PKGPATH=www/ap2-vhost-ldap:PKG_APACHE=apache2
HOMEPAGE=http://packages.qa.debian.org/m/mod-vhost-ldap.html
COMMENT=Apache 2 module LDAP Virtual Hosts support
MAINTAINER=imil@gcu.info
CATEGORIES=www databases

'

runtest pkg_grep_summary -t strfile PKGPATHe pkgs.txt < src_summary.txt |
cmp 'pkg_grep_summary #17' \
'PKGNAME=distbb-0.22.0
PKGPATH=wip/distbb
DEPENDS=pkg_summary-utils>=0.18.1:../../wip/pkg_summary-utils paexec>=0.10.0:../../wip/paexec runawk>=0.13.0:../../wip/runawk
BUILD_DEPENDS= checkperms>=1.1:../../sysutils/checkperms
HOMEPAGE=http://mova.org/~cheusov/pub/distbb/
COMMENT=DISTributed Bulk Build tool for pkgsrc
MAINTAINER=cheusov@tut.by
CATEGORIES=pkgtools
EXFIELD=XVALUE1

BUILD_DEPENDS= libtool-base>=1.5.18nb5:../../devel/libtool-base gmake>=3.81:../../devel/gmake checkperms>=1.1:../../sysutils/checkperms
PKGNAME=dict-server-1.10.11nb2
PKGPATH=wip/dict-server
DEPENDS=   libmaa>=1.2:../../devel/libmaa
HOMEPAGE=http://www.dict.org/
COMMENT=Dictionary Service Protocol server
MAINTAINER=cheusov@tut.by
CATEGORIES=textproc

PKGNAME=png-1.2.32beta01
PKGPATH=graphics/png
BUILD_DEPENDS= libtool-base>=1.5.18nb5:../../devel/libtool-base checkperms>=1.1:../../sysutils/checkperms
HOMEPAGE=http://www.libpng.org/pub/png/
COMMENT=Library for manipulating PNG images
MAINTAINER=wiz@NetBSD.org
CATEGORIES=graphics

'

runtest pkg_grep_summary -t strlist PKGPATH 'graphics/png wip/distbb' \
    < src_summary.txt |
cmp 'pkg_grep_summary #18' \
'PKGNAME=distbb-0.22.0
PKGPATH=wip/distbb
DEPENDS=pkg_summary-utils>=0.18.1:../../wip/pkg_summary-utils paexec>=0.10.0:../../wip/paexec runawk>=0.13.0:../../wip/runawk
BUILD_DEPENDS= checkperms>=1.1:../../sysutils/checkperms
HOMEPAGE=http://mova.org/~cheusov/pub/distbb/
COMMENT=DISTributed Bulk Build tool for pkgsrc
MAINTAINER=cheusov@tut.by
CATEGORIES=pkgtools
EXFIELD=XVALUE1

PKGNAME=png-1.2.32beta01
PKGPATH=graphics/png
BUILD_DEPENDS= libtool-base>=1.5.18nb5:../../devel/libtool-base checkperms>=1.1:../../sysutils/checkperms
HOMEPAGE=http://www.libpng.org/pub/png/
COMMENT=Library for manipulating PNG images
MAINTAINER=wiz@NetBSD.org
CATEGORIES=graphics

'

runtest pkg_grep_summary -t substring PKGNAME dict < src_summary.txt |
    grep_PKGNAME_n_PKGBASE_only |
cmp 'pkg_grep_summary #19' \
'PKGPATH=textproc/dictem
PKGNAME=dictem-0.82

PKGNAME=dict-server-1.10.11nb2
PKGPATH=wip/dict-server

PKGNAME=dict-client-1.9.15nb2
PKGPATH=textproc/dict-client

PKGNAME=dict-client-1.10.11nb2
PKGPATH=wip/dict-client

'

runtest pkg_grep_summary -t substring PKGNAME distcc < src_summary.txt |
    grep_PKGNAME_n_PKGBASE_only |
cmp 'pkg_grep_summary #20' \
''

runtest pkg_grep_summary -t substring DEPENDS pkg_online-server < src_summary.txt |
    grep_PKGNAME_n_PKGBASE_only |
cmp 'pkg_grep_summary #21' \
'PKGNAME=pkg_online-0.5.0nb2
PKGPATH=wip/pkg_online

'

runtest pkg_grep_summary -t first PKGNAME dict < src_summary.txt |
    grep_PKGNAME_n_PKGBASE_only |
cmp 'pkg_grep_summary #22' \
'PKGNAME=dict-server-1.10.11nb2
PKGPATH=wip/dict-server

PKGNAME=dict-client-1.9.15nb2
PKGPATH=textproc/dict-client

PKGNAME=dict-client-1.10.11nb2
PKGPATH=wip/dict-client

'

runtest pkg_grep_summary -t first PKGNAME dic < src_summary.txt |
    grep_PKGNAME_n_PKGBASE_only |
cmp 'pkg_grep_summary #23' \
''

runtest pkg_grep_summary -t last PKGBASE client < src_summary.txt |
    grep_PKGNAME_n_PKGBASE_only |
cmp 'pkg_grep_summary #24' \
'PKGNAME=dict-client-1.9.15nb2
PKGPATH=textproc/dict-client

PKGNAME=pkg_online-client-0.5.0
PKGPATH=wip/pkg_online-client

PKGNAME=dict-client-1.10.11nb2
PKGPATH=wip/dict-client

'

runtest pkg_grep_summary -t last PKGBASE lient < src_summary.txt |
    grep_PKGNAME_n_PKGBASE_only |
cmp 'pkg_grep_summary #25' \
''

runtest pkg_grep_summary -t exact PKGBASE dictem < src_summary.txt |
    grep_PKGNAME_n_PKGBASE_only |
cmp 'pkg_grep_summary #26' \
'PKGPATH=textproc/dictem
PKGNAME=dictem-0.82

'

runtest pkg_grep_summary -t exact PKGBASE dict < src_summary.txt |
    grep_PKGNAME_n_PKGBASE_only |
cmp 'pkg_grep_summary #27' \
''

runtest pkg_grep_summary -t prefix PKGBASE awk < src_summary.txt |
    grep_PKGNAME_n_PKGBASE_only |
cmp 'pkg_grep_summary #28' \
'PKGNAME=awk-pkgsrc-dewey-0.5.6
PKGPATH=wip/awk-pkgsrc-dewey

'

runtest pkg_grep_summary -t prefix PKGBASE ruby < src_summary.txt |
    grep_PKGNAME_n_PKGBASE_only |
cmp 'pkg_grep_summary #29' \
''

runtest pkg_grep_summary -t suffix PKGBASE ldap < src_summary.txt |
    grep_PKGNAME_n_PKGBASE_only |
cmp 'pkg_grep_summary #30' \
'PKGNAME=ap22-vhost-ldap-1.2.0nb1
PKGPATH=www/ap22-vhost-ldap

PKGNAME=ap2-vhost-ldap-1.2.0nb1
PKGPATH=www/ap2-vhost-ldap:PKG_APACHE=apache2

'

runtest pkg_grep_summary -t suffix PKGBASE nis < src_summary.txt |
    grep_PKGNAME_n_PKGBASE_only |
cmp 'pkg_grep_summary #31' \
''

runtest pkg_grep_summary -t word PKGBASE dict < src_summary.txt |
    grep_PKGNAME_n_PKGBASE_only |
cmp 'pkg_grep_summary #32' \
'PKGNAME=dict-server-1.10.11nb2
PKGPATH=wip/dict-server

PKGNAME=dict-client-1.9.15nb2
PKGPATH=textproc/dict-client

PKGNAME=dict-client-1.10.11nb2
PKGPATH=wip/dict-client

'

runtest pkg_grep_summary -t word PKGBASE dic < src_summary.txt |
    grep_PKGNAME_n_PKGBASE_only |
cmp 'pkg_grep_summary #33' \
''

runtest pkg_grep_summary -t word PKGBASE ldap < src_summary.txt |
    grep_PKGNAME_n_PKGBASE_only |
cmp 'pkg_grep_summary #34' \
'PKGNAME=ap22-vhost-ldap-1.2.0nb1
PKGPATH=www/ap22-vhost-ldap

PKGNAME=ap2-vhost-ldap-1.2.0nb1
PKGPATH=www/ap2-vhost-ldap:PKG_APACHE=apache2

'

runtest pkg_grep_summary -t word PKGBASE dap < src_summary.txt |
    grep_PKGNAME_n_PKGBASE_only |
cmp 'pkg_grep_summary #35' \
''

runtest pkg_grep_summary -t word PKGBASE nis < src_summary.txt |
    grep_PKGNAME_n_PKGBASE_only |
cmp 'pkg_grep_summary #36' \
''

runtest pkg_grep_summary -t word PKGBASE dictem < src_summary.txt |
    grep_PKGNAME_n_PKGBASE_only |
cmp 'pkg_grep_summary #37' \
'PKGPATH=textproc/dictem
PKGNAME=dictem-0.82

'

runtest pkg_grep_summary -t re PKGBASE 'd.*t' < src_summary.txt |
    grep_PKGNAME_n_PKGBASE_only |
cmp 'pkg_grep_summary #38' \
'PKGNAME=distbb-0.22.0
PKGPATH=wip/distbb

PKGPATH=textproc/dictem
PKGNAME=dictem-0.82

PKGNAME=dict-server-1.10.11nb2
PKGPATH=wip/dict-server

PKGNAME=dict-client-1.9.15nb2
PKGPATH=textproc/dict-client

PKGNAME=dict-client-1.10.11nb2
PKGPATH=wip/dict-client

'

runtest pkg_grep_summary -i -s MAINTAINER 'rillig@netbsd.org' < src_summary.txt |
    grep_PKGNAME_n_PKGBASE_only |
cmp 'pkg_grep_summary #39' \
'PKGNAME=checkperms-1.10
PKGPATH=sysutils/checkperms

'

runtest pkg_grep_summary -s PLIST file2 < src_summary10.txt |
cmp 'pkg_grep_summary #40' \
'PKGNAME=foo
PKGPATH=pkgtools/foo
PLIST=file1
PLIST=file2

'

runtest pkg_grep_summary -m CONFLICTS package2 < src_summary10.txt |
cmp 'pkg_grep_summary #41' \
'PKGNAME=foobar
PKGPATH=pkgtools/foobar
CONFLICTS=package1
CONFLICTS=package2

'

runtest pkg_grep_summary -m DEPENDS depends2 < src_summary10.txt |
cmp 'pkg_grep_summary #42' \
'PKGNAME=barbaz
PKGPATH=pkgtools/barbaz
DEPENDS=depends1
DEPENDS=depends2

'

runtest pkg_grep_summary -m PROVIDES provides2 < src_summary10.txt |
cmp 'pkg_grep_summary #43' \
'PKGNAME=bazzzz
PKGPATH=pkgtools/bazzzz
PROVIDES=provides1
PROVIDES=provides2

'

runtest pkg_grep_summary -m REQUIRES requires2 < src_summary10.txt |
cmp 'pkg_grep_summary #44' \
'PKGNAME=baz
PKGPATH=pkgtools/baz
REQUIRES=requires1
REQUIRES=requires2

'

runtest pkg_grep_summary -m DESCRIPTION descr2 < src_summary10.txt |
cmp 'pkg_grep_summary #45' \
'PKGNAME=bar
PKGPATH=pkgtools/bar
DESCRIPTION=descr1
DESCRIPTION=descr2

'

runtest pkg_grep_summary . \
    'fields ["MAINTAINER"] ~ /cheusov/ && fields ["PKGPATH"] !~ /^wip/' \
    < src_summary.txt | grep -E '^(PKGNAME|PKGPATH|MAINTAINER)=|^$|^--' |
cmp 'pkg_grep_summary #46' \
'PKGPATH=textproc/dictem
MAINTAINER=cheusov@tut.by
PKGNAME=dictem-0.82

PKGNAME=libmaa-1.0.1nb1
PKGPATH=devel/libmaa
MAINTAINER=cheusov@tut.by

PKGNAME=pipestatus-0.4.0
PKGPATH=devel/pipestatus
MAINTAINER=cheusov@tut.by

'

runtest pkg_grep_summary -i -t kw       COMMENT 'dictionary client' \
    < src_summary.txt |
cmp 'pkg_grep_summary #47' \
'PKGPATH=textproc/dictem
DEPENDS=dict-client>=1.9.14:../../textproc/dict-client emacs>=22:../../editors/emacs  emacs>=22:../../editors/emacs
BUILD_DEPENDS= checkperms>=1.1:../../sysutils/checkperms
CONFLICTS=xemacs-dictem-[0-9]*
HOMEPAGE=http://freshmeat.net/projects/dictem/
COMMENT=Dictionary client (RFC-2229) for [X]Emacs
MAINTAINER=cheusov@tut.by
CATEGORIES=textproc editors
PKGNAME=dictem-0.82

PKGNAME=dict-client-1.9.15nb2
PKGPATH=textproc/dict-client
DEPENDS=  libltdl>=1.5.10:../../devel/libltdl
BUILD_DEPENDS= gmake>=3.81:../../devel/gmake checkperms>=1.1:../../sysutils/checkperms
HOMEPAGE=http://www.dict.org/
COMMENT=Dictionary Service Protocol client
MAINTAINER=pkgsrc-users@NetBSD.org
CATEGORIES=textproc

PKGNAME=dict-client-1.10.11nb2
PKGPATH=wip/dict-client
DEPENDS=  libmaa>=1.0:../../devel/libmaa
BUILD_DEPENDS= libtool-base>=1.5.18nb5:../../devel/libtool-base gmake>=3.81:../../devel/gmake checkperms>=1.1:../../sysutils/checkperms
HOMEPAGE=http://www.dict.org/
COMMENT=Dictionary Service Protocol client
MAINTAINER=cheusov@tut.by
CATEGORIES=textproc

'

runtest pkg_grep_summary -i -t keywords COMMENT 'dictionary client' \
    < src_summary.txt |
cmp 'pkg_grep_summary #48' \
'PKGPATH=textproc/dictem
DEPENDS=dict-client>=1.9.14:../../textproc/dict-client emacs>=22:../../editors/emacs  emacs>=22:../../editors/emacs
BUILD_DEPENDS= checkperms>=1.1:../../sysutils/checkperms
CONFLICTS=xemacs-dictem-[0-9]*
HOMEPAGE=http://freshmeat.net/projects/dictem/
COMMENT=Dictionary client (RFC-2229) for [X]Emacs
MAINTAINER=cheusov@tut.by
CATEGORIES=textproc editors
PKGNAME=dictem-0.82

PKGNAME=dict-client-1.9.15nb2
PKGPATH=textproc/dict-client
DEPENDS=  libltdl>=1.5.10:../../devel/libltdl
BUILD_DEPENDS= gmake>=3.81:../../devel/gmake checkperms>=1.1:../../sysutils/checkperms
HOMEPAGE=http://www.dict.org/
COMMENT=Dictionary Service Protocol client
MAINTAINER=pkgsrc-users@NetBSD.org
CATEGORIES=textproc

PKGNAME=dict-client-1.10.11nb2
PKGPATH=wip/dict-client
DEPENDS=  libmaa>=1.0:../../devel/libmaa
BUILD_DEPENDS= libtool-base>=1.5.18nb5:../../devel/libtool-base gmake>=3.81:../../devel/gmake checkperms>=1.1:../../sysutils/checkperms
HOMEPAGE=http://www.dict.org/
COMMENT=Dictionary Service Protocol client
MAINTAINER=cheusov@tut.by
CATEGORIES=textproc

'

runtest pkg_grep_summary -T |
cmp 'pkg_grep_summary #49' \
'exact prefix suffix substring word first last re strfile strlist awk empty kw
'

# pkg_list_all_pkgs
env  pkg_list_all_pkgs |
awk '
END {
    if (NR > 7000) {
        print "XXXX"
    }else{
        print "failure"
    }
}' |
cmp 'pkg_list_all_pkgs #1' \
'XXXX
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



# pkg_refresh_summary
pkg_refresh_summary src_summary.txt src_summary2.txt |
sed -n 's/^PKGNAME=//p' | sort |
cmp 'pkg_refresh_summary #1' \
'ap22-vhost-ldap-1.2.0nb1
awk-pkgsrc-dewey-0.5.6
checkperms-1.10
dict-client-1.10.11nb2
dict-client-1.9.15nb2
dict-server-1.11.0
dictem-0.82
digest-99.99.99
distbb-0.22.0
emacs-22.1nb6
gmake-3.81
jpeg-6bnb4
libltdl-1.5.24
libmaa-1.0.1nb1
libtool-base-1.5.24nb6
libungif-4.1.4nb1
netcat-1.10nb2
paexec-0.10.0nb1
perl-5.8.8nb8
pipestatus-0.5.0
pkg-config-0.23
pkg_online-0.5.0nb2
pkg_online-client-0.5.0
pkg_online-server-0.5.0
pkg_summary-utils-0.18.1
png-1.2.32beta01
runawk-0.14.3
tiff-3.8.2nb4
x11-links-0.38
'

pkg_refresh_summary -o src_summary.txt src_summary2.txt |
sed -n 's/^PKGNAME=//p' | sort |
cmp 'pkg_refresh_summary #2' \
'ap2-vhost-ldap-1.2.0nb1
dict-server-1.10.11nb2
pipestatus-0.4.0
runawk-0.13.0
'


# pkg_summary4view
pkg_grep_summary -s PKGPATH 'wip/pkg_summary-utils' \
    < src_summary.txt |
pkg_summary4view |
normalize_version |
cmp 'pkg_summary4view #1' \
'-----------------------------------------------------------
PKGNAME:        pkg_summary-utils-0.18.1
PKGPATH:        wip/pkg_summary-utils
DEPENDS:        awk-pkgsrc-dewey>=0.5.6:../../wip/awk-pkgsrc-dewey
                pipestatus-[0-9]*:../../devel/pipestatus
                runawk>=0.12.1:../../wip/runawk
BUILD_DEPENDS:  checkperms>=1.1:../../sysutils/checkperms
CONFLICTS:      paexec<0.9.0
                pkg_cmp_summary-[0-9]*
                pkg_src_summary-[0-9]*
                pkg_src_update_summary-[0-9]*
                pkg_summary4view-[0-9]*
                pkg_update_summary-[0-9]*
HOMEPAGE:       http://www.mova.org/~cheusov/pub/pkg_summary-utils/
COMMENT:        Utilities for manipulating pkg_summary(5) files
MAINTAINER:     cheusov@tut.by
CATEGORIES:     pkgtools

'

pkg_summary4view -h     2>&1 | grep pkg_summary4view | grep summary4view |
cmp 'pkg_summary4view #2' \
'pkg_summary4view - converts pkg_summary(5) to human readable format
usage: pkg_summary4view [OPTIONS] [files...]
'

pkg_summary4view --help 2>&1 | grep pkg_summary4view | grep summary4view |
cmp 'pkg_summary4view #3' \
'pkg_summary4view - converts pkg_summary(5) to human readable format
usage: pkg_summary4view [OPTIONS] [files...]
'



# pkg_uniq_summary
pkg_uniq_summary src_summary3.txt |
cmp 'pkg_uniq_summary #1' \
'ASSIGNMENTS=OPT1=1,OPT2=2
PKGNAME=distbb-0.22.0
PKGPATH=wip/distbb

PKGNAME=distbb-0.22.0
PKGPATH=wip/distbb:OPT=1,OPT2=3

'

pkg_uniq_summary -h 2>&1     | grep pkg_uniq_summary |
cmp 'pkg_uniq_summary #2' \
'pkg_uniq_summary - filter out repeated summaries.
usage: pkg_uniq_summary -h
      pkg_uniq_summary [OPTIONS] [files...]
'

pkg_uniq_summary --help 2>&1 | grep pkg_uniq_summary |
cmp 'pkg_uniq_summary #3' \
'pkg_uniq_summary - filter out repeated summaries.
usage: pkg_uniq_summary -h
      pkg_uniq_summary [OPTIONS] [files...]
'




# pkg_src_summary
pkgs="`sed -n 's/^PKGPATH=//p' src_summary.txt`"
pkg_src_summary -f PKGNAME,PKGPATH $pkgs 2>"$tmpfn4" |
tee "$objdir"/summary_full.txt |
normalize_version |
cmp 'pkg_src_summary #1' \
'PKGNAME=distbb-X
PKGPATH=wip/distbb

PKGNAME=dictem-X
PKGPATH=textproc/dictem

PKGNAME=checkperms-X
PKGPATH=sysutils/checkperms

PKGNAME=pkg_online-server-X
PKGPATH=wip/pkg_online-server

PKGNAME=dict-client-X
PKGPATH=textproc/dict-client

PKGNAME=pkg_online-client-X
PKGPATH=wip/pkg_online-client

PKGNAME=libmaa-X
PKGPATH=devel/libmaa

PKGNAME=gmake-X
PKGPATH=devel/gmake

PKGNAME=paexec-X
PKGPATH=wip/paexec

PKGNAME=libtool-base-X
PKGPATH=devel/libtool-base

PKGNAME=runawk-X
PKGPATH=wip/runawk

PKGNAME=emacs-X
PKGPATH=editors/emacs

PKGNAME=pkg_summary-utils-X
PKGPATH=wip/pkg_summary-utils

PKGNAME=libungif-X
PKGPATH=graphics/libungif

PKGNAME=tiff-X
PKGPATH=graphics/tiff

PKGNAME=x11-links-X
PKGPATH=pkgtools/x11-links

PKGNAME=perl-X
PKGPATH=lang/perl5

PKGNAME=libltdl-X
PKGPATH=devel/libltdl

PKGNAME=pipestatus-X
PKGPATH=devel/pipestatus

PKGNAME=png-X
PKGPATH=graphics/png

PKGNAME=netcat-X
PKGPATH=net/netcat

PKGNAME=pkg-config-X
PKGPATH=devel/pkg-config

PKGNAME=jpeg-X
PKGPATH=graphics/jpeg

PKGNAME=ap22-vhost-ldap-X
PKGPATH=www/ap22-vhost-ldap

'

cat "$tmpfn4" |
cmp 'pkg_src_summary #1 stderr' \
" ------------------
Bad package wip/pkg_online, skipped
cd: can't cd to wip/pkg_online
 ------------------
Bad package wip/dict-server, skipped
cd: can't cd to wip/dict-server
 ------------------
Bad package wip/dict-client, skipped
cd: can't cd to wip/dict-client
 ------------------
Bad package wip/awk-pkgsrc-dewey, skipped
cd: can't cd to wip/awk-pkgsrc-dewey
 ------------------
Bad package www/ap2-vhost-ldap:PKG_APACHE=apache2, skipped
cd: can't cd to www/ap2-vhost-ldap
"

pkg_src_summary -m -fPKGNAME,PKGPATH www/ap2-python |
grep -v DEPENDS |
cmp 'pkg_src_summary #2' \
'ASSIGNMENTS=PKG_APACHE=apache2
PKGNAME=ap2-py26-python-3.3.1
PKGPATH=www/ap2-python

ASSIGNMENTS=PKG_APACHE=apache2,PYTHON_VERSION_REQD=25
PKGNAME=ap2-py25-python-3.3.1
PKGPATH=www/ap2-python

ASSIGNMENTS=PKG_APACHE=apache2,PYTHON_VERSION_REQD=24
PKGNAME=ap2-py24-python-3.3.1
PKGPATH=www/ap2-python

PKGNAME=ap22-py26-python-3.3.1
PKGPATH=www/ap2-python

ASSIGNMENTS=PYTHON_VERSION_REQD=25
PKGNAME=ap22-py25-python-3.3.1
PKGPATH=www/ap2-python

ASSIGNMENTS=PYTHON_VERSION_REQD=24
PKGNAME=ap22-py24-python-3.3.1
PKGPATH=www/ap2-python

'

pkg_src_summary -m --fields PKGNAME,PKGPATH www/ap2-python:PKG_APACHE=apache2 |
grep -v DEPENDS |
cmp 'pkg_src_summary #3' \
'PKGNAME=ap22-py26-python-3.3.1
PKGPATH=www/ap2-python

ASSIGNMENTS=PYTHON_VERSION_REQD=25
PKGNAME=ap22-py25-python-3.3.1
PKGPATH=www/ap2-python

ASSIGNMENTS=PYTHON_VERSION_REQD=24
PKGNAME=ap22-py24-python-3.3.1
PKGPATH=www/ap2-python

'

pkg_src_summary -m --fields='PKGNAME PKGPATH' www/ap2-python:PYTHON_VERSION_REQD=25 |
grep -v DEPENDS |
cmp 'pkg_src_summary #4' \
'ASSIGNMENTS=PKG_APACHE=apache2
PKGNAME=ap2-py26-python-3.3.1
PKGPATH=www/ap2-python

PKGNAME=ap22-py26-python-3.3.1
PKGPATH=www/ap2-python

'

pkg_src_summary -m -f'PKGNAME PKGPATH' \
   www/ap2-python:PYTHON_VERSION_REQD=25,PKG_APACHE=apache22 |
grep -v DEPENDS |
cmp 'pkg_src_summary #5' \
'ASSIGNMENTS=PYTHON_VERSION_REQD=25
PKGNAME=ap22-py25-python-3.3.1
PKGPATH=www/ap2-python

'


normalize_python_deps (){
    awk '
sub(/^DEPENDS=/, "FAKED_PKGPATH= ") {
   for (i=2; i <= NF; ++i){
      if ($i ~ /py/){
         sub(/^[^:]*:([.][.]\/[.][.]\/)?/, "", $i)
         if (i && $i == $(i-1))
            $i = ""
      }else{
         $i = ""
      }
   }
   gsub(/  +/, " ")
}
/^BUILD_DEPENDS=/ {
   next
}
{
   print
}
' "$@"
}

if false; then
pkg_src_summary -Af PKGNAME,PKGPATH \
   graphics/py-cairo:PYTHON_VERSION_REQD=25 |
normalize_python_deps |
pkg_grep_summary -m PKGPATH 'py-Numeric|py-cairo|python|cairo' |
normalize_version |
cmp 'pkg_src_summary #6' \
'ASSIGNMENTS=PYTHON_VERSION_REQD=25
PKGNAME=py25-cairo-X
PKGPATH=graphics/py-cairo
FAKED_PKGPATH= lang/python25 math/py-Numeric:PYTHON_VERSION_REQD=25 lang/python25 math/py-Numeric:PYTHON_VERSION_REQD=25 

PKGNAME=cairo-X
PKGPATH=graphics/cairo
FAKED_PKGPATH= 

ASSIGNMENTS=PYTHON_VERSION_REQD=25
PKGNAME=py25-Numeric-X
PKGPATH=math/py-Numeric
FAKED_PKGPATH= lang/python25 lang/python25

PKGNAME=python25-X
PKGPATH=lang/python25
FAKED_PKGPATH= 

'
fi

if false; then
pkg_src_summary -A -fPKGNAME,PKGPATH \
   graphics/py-cairo:PYTHON_VERSION_REQD=26 |
normalize_python_deps |
pkg_grep_summary -m PKGPATH 'py-Numeric|py-cairo|python|cairo' |
normalize_version |
cmp 'pkg_src_summary #7' \
'PKGNAME=py26-cairo-X
PKGPATH=graphics/py-cairo
FAKED_PKGPATH= lang/python26 math/py-Numeric math/py-Numeric 

PKGNAME=py26-Numeric-X
PKGPATH=math/py-Numeric
FAKED_PKGPATH= lang/python26

PKGNAME=cairo-X
PKGPATH=graphics/cairo
FAKED_PKGPATH= 

PKGNAME=python26-X
PKGPATH=lang/python26
FAKED_PKGPATH= 

'
fi

if false; then
pkg_src_summary -mA -f PKGNAME,PKGPATH graphics/py-cairo |
normalize_python_deps |
pkg_grep_summary -m PKGPATH 'py-Numeric|py-cairo|python|cairo' |
normalize_version |
cmp 'pkg_src_summary #8' \
'PKGNAME=py26-cairo-X
PKGPATH=graphics/py-cairo
FAKED_PKGPATH= lang/python26 math/py-Numeric math/py-Numeric 

ASSIGNMENTS=PYTHON_VERSION_REQD=25
PKGNAME=py25-cairo-X
PKGPATH=graphics/py-cairo
FAKED_PKGPATH= lang/python25 math/py-Numeric:PYTHON_VERSION_REQD=25 lang/python25 math/py-Numeric:PYTHON_VERSION_REQD=25 

PKGNAME=cairo-X
PKGPATH=graphics/cairo
FAKED_PKGPATH= 

ASSIGNMENTS=PYTHON_VERSION_REQD=25
PKGNAME=py25-Numeric-X
PKGPATH=math/py-Numeric
FAKED_PKGPATH= lang/python25 lang/python25

PKGNAME=py26-Numeric-X
PKGPATH=math/py-Numeric
FAKED_PKGPATH= lang/python26

PKGNAME=python25-X
PKGPATH=lang/python25
FAKED_PKGPATH= 

PKGNAME=python26-X
PKGPATH=lang/python26
FAKED_PKGPATH= 

'
fi

pkg_src_summary -f PKGNAME --add-fields 'PKGPATH MAINTAINER' x11/xxkb |
normalize_version |
cmp 'pkg_src_summary #9' \
'PKGNAME=xxkb-X
PKGPATH=x11/xxkb
MAINTAINER=vle@gmx.net

'

pkg_src_summary --fields=PKGNAME -a 'PKGPATH MAINTAINER' x11/xxkb |
normalize_version |
cmp 'pkg_src_summary #10' \
'PKGNAME=xxkb-X
PKGPATH=x11/xxkb
MAINTAINER=vle@gmx.net

'

pkg_src_summary -fPKGNAME -aPKGPATH,MAINTAINER x11/xxkb |
normalize_version |
cmp 'pkg_src_summary #11' \
'PKGNAME=xxkb-X
PKGPATH=x11/xxkb
MAINTAINER=vle@gmx.net

'

pkg_src_summary -fPKGNAME --add-fields=PKGPATH,MAINTAINER x11/xxkb |
normalize_version |
cmp 'pkg_src_summary #12' \
'PKGNAME=xxkb-X
PKGPATH=x11/xxkb
MAINTAINER=vle@gmx.net

'



# pkg_src_summary
pkg_src_summary -f PKGNAME,PKGPATH,COMMENT --rem-fields 'PKGPATH MAINTAINER' x11/xxkb |
normalize_version |
cmp 'pkg_src_summary #13' \
'PKGNAME=xxkb-X
COMMENT=XXKB - switches and indicates a current keyboard layout

'

pkg_src_summary -f PKGNAME,PKGPATH,COMMENT -r 'PKGPATH MAINTAINER' x11/xxkb |
normalize_version |
cmp 'pkg_src_summary #14' \
'PKGNAME=xxkb-X
COMMENT=XXKB - switches and indicates a current keyboard layout

'

pkg_src_summary -f PKGNAME,PKGPATH,COMMENT -rPKGPATH,MAINTAINER x11/xxkb |
normalize_version |
cmp 'pkg_src_summary #15' \
'PKGNAME=xxkb-X
COMMENT=XXKB - switches and indicates a current keyboard layout

'

pkg_src_summary -f PKGNAME,PKGPATH,COMMENT --rem-fields=PKGPATH,MAINTAINER x11/xxkb |
normalize_version |
cmp 'pkg_src_summary #16' \
'PKGNAME=xxkb-X
COMMENT=XXKB - switches and indicates a current keyboard layout

'

hide_distfile_size (){
    sed 's/:[0-9]*/:NNN/g' "$@"
}

pkg_src_summary -f PKGNAME,PKGPATH,ALLDISTFILES x11/xxkb | hide_distfile_size |
cmp 'pkg_src_summary #17' \
'PKGNAME=xxkb-1.11
PKGPATH=x11/xxkb
ALLDISTFILES= xxkb-1.11-src.tar.gz:NNN

'

# pkg_assignments2pkgpath
pkg_assignments2pkgpath -h 2>&1 |
grep pkg_assignments2pkgpath |
cmp 'pkg_assignments2pkgpath #1' \
'pkg_assignments2pkgpath - makes an ASSIGNMENTS section a part of PKGPATH
usage: pkg_assignments2pkgpath -h|--help\n\
       pkg_assignments2pkgpath [OPTIONS] [files...]
'

pkg_assignments2pkgpath --help 2>&1 |
grep pkg_assignments2pkgpath |
cmp 'pkg_assignments2pkgpath #2' \
'pkg_assignments2pkgpath - makes an ASSIGNMENTS section a part of PKGPATH
usage: pkg_assignments2pkgpath -h|--help\n\
       pkg_assignments2pkgpath [OPTIONS] [files...]
'



# pkg_src_fetch_var
echo x11/xxkb | pkg_src_fetch_var -f 'PKGNAME PKGPATH MAINTAINER' |
normalize_version |
cmp 'pkg_src_fetch_var #1' \
'+	xxkb-1.11	x11/xxkb	vle@gmx.net
'

echo x11/xxkb | pkg_src_fetch_var -v'PKGNAME PKGPATH MAINTAINER' |
normalize_version |
cmp 'pkg_src_fetch_var #2' \
'+	xxkb-1.11	x11/xxkb	vle@gmx.net
'

echo x11/xxkb | pkg_src_fetch_var --vars='PKGNAME PKGPATH MAINTAINER' |
normalize_version |
cmp 'pkg_src_fetch_var #3' \
'+	xxkb-1.11	x11/xxkb	vle@gmx.net
'

echo x11/xxkb | pkg_src_fetch_var --fields 'PKGNAME PKGPATH MAINTAINER' |
normalize_version |
cmp 'pkg_src_fetch_var #4' \
'+	xxkb-1.11	x11/xxkb	vle@gmx.net
'


# pkg_micro_src_summary
pkgs="`sed -n 's/^PKGPATH=//p' src_summary.txt`"
pkg_micro_src_summary $pkgs 2>"$tmpfn4" |
tee "$objdir"/summary_micro.txt |
normalize_version |
cmp 'pkg_micro_src_summary #1' \
'PKGNAME=distbb-X
PKGPATH=wip/distbb

PKGNAME=checkperms-X
PKGPATH=sysutils/checkperms

PKGNAME=dict-client-X
PKGPATH=textproc/dict-client

PKGNAME=libmaa-X
PKGPATH=devel/libmaa

PKGNAME=gmake-X
PKGPATH=devel/gmake

PKGNAME=paexec-X
PKGPATH=wip/paexec

PKGNAME=libtool-base-X
PKGPATH=devel/libtool-base

PKGNAME=runawk-X
PKGPATH=wip/runawk

PKGNAME=emacs-X
PKGPATH=editors/emacs

PKGNAME=pkg_summary-utils-X
PKGPATH=wip/pkg_summary-utils

PKGNAME=libungif-X
PKGPATH=graphics/libungif

PKGNAME=tiff-X
PKGPATH=graphics/tiff

PKGNAME=x11-links-X
PKGPATH=pkgtools/x11-links

PKGNAME=perl-X
PKGPATH=lang/perl5

PKGNAME=libltdl-X
PKGPATH=devel/libltdl

PKGNAME=pipestatus-X
PKGPATH=devel/pipestatus

PKGNAME=png-X
PKGPATH=graphics/png

PKGNAME=netcat-X
PKGPATH=net/netcat

PKGNAME=pkg-config-X
PKGPATH=devel/pkg-config

PKGNAME=jpeg-X
PKGPATH=graphics/jpeg

PKGNAME=dictem-X
PKGPATH=textproc/dictem

PKGNAME=pkg_online-server-X
PKGPATH=wip/pkg_online-server

PKGNAME=pkg_online-client-X
PKGPATH=wip/pkg_online-client

PKGNAME=ap22-vhost-ldap-X
PKGPATH=www/ap22-vhost-ldap

'

cat "$tmpfn4" |
cmp 'pkg_micro_src_summary #1 stderr' \
" ------------------
Bad package wip/pkg_online, skipped
cd: can't cd to wip/pkg_online
 ------------------
Bad package wip/dict-server, skipped
cd: can't cd to wip/dict-server
 ------------------
Bad package wip/dict-client, skipped
cd: can't cd to wip/dict-client
 ------------------
Bad package wip/awk-pkgsrc-dewey, skipped
cd: can't cd to wip/awk-pkgsrc-dewey
 ------------------
Bad package www/ap2-vhost-ldap:PKG_APACHE=apache2, skipped
cd: can't cd to www/ap2-vhost-ldap
"

pkg_micro_src_summary -f PKGNAME,PKGPATH,MAINTAINER x11/xxkb |
normalize_version |
cmp 'pkg_micro_src_summary #2' \
'PKGNAME=xxkb-X
PKGPATH=x11/xxkb
MAINTAINER=vle@gmx.net

'

pkg_micro_src_summary --fields=PKGNAME,PKGPATH,MAINTAINER x11/xxkb |
normalize_version |
cmp 'pkg_micro_src_summary #3' \
'PKGNAME=xxkb-X
PKGPATH=x11/xxkb
MAINTAINER=vle@gmx.net

'

pkg_micro_src_summary -fPKGNAME,PKGPATH,MAINTAINER x11/xxkb |
normalize_version |
cmp 'pkg_micro_src_summary #4' \
'PKGNAME=xxkb-X
PKGPATH=x11/xxkb
MAINTAINER=vle@gmx.net

'

pkg_micro_src_summary --fields PKGNAME,PKGPATH,MAINTAINER x11/xxkb |
normalize_version |
cmp 'pkg_micro_src_summary #5' \
'PKGNAME=xxkb-X
PKGPATH=x11/xxkb
MAINTAINER=vle@gmx.net

'


# pkg_cmp_summary
pkg_cmp_summary src_summary.txt src_summary2.txt | sort -k2,2 |
cmp 'pkg_cmp_summary #1' \
'- ap2-vhost-ldap 1.2.0nb1
- ap22-vhost-ldap 1.2.0nb1
= awk-pkgsrc-dewey 0.5.6 0.5.6
= checkperms 1.10 1.10
2 dict-client
< dict-server 1.10.11nb2 1.11.0
= dictem 0.82 0.82
+ digest 99.99.99
= distbb 0.22.0 0.22.0
= emacs 22.1nb6 22.1nb6
= gmake 3.81 3.81
= jpeg 6bnb4 6bnb4
= libltdl 1.5.24 1.5.24
= libmaa 1.0.1nb1 1.0.1nb1
= libtool-base 1.5.24nb6 1.5.24nb6
= libungif 4.1.4nb1 4.1.4nb1
- netcat 1.10nb2
= paexec 0.10.0nb1 0.10.0nb1
= perl 5.8.8nb8 5.8.8nb8
< pipestatus 0.4.0 0.5.0
= pkg-config 0.23 0.23
= pkg_online 0.5.0nb2 0.5.0nb2
= pkg_online-client 0.5.0 0.5.0
= pkg_online-server 0.5.0 0.5.0
= pkg_summary-utils 0.18.1 0.18.1
= png 1.2.32beta01 1.2.32beta01
> runawk 0.14.3 0.13.0
= tiff 3.8.2nb4 3.8.2nb4
- x11-links 0.38
'

pkg_cmp_summary -p src_summary.txt src_summary2.txt | sort -k2,2 |
cmp 'pkg_cmp_summary #2' \
'= devel/gmake gmake 3.81 3.81
= devel/libltdl libltdl 1.5.24 1.5.24
= devel/libmaa libmaa 1.0.1nb1 1.0.1nb1
= devel/libtool-base libtool-base 1.5.24nb6 1.5.24nb6
< devel/pipestatus pipestatus 0.4.0 0.5.0
= devel/pkg-config pkg-config 0.23 0.23
= editors/emacs emacs 22.1nb6 22.1nb6
= graphics/jpeg jpeg 6bnb4 6bnb4
= graphics/libungif libungif 4.1.4nb1 4.1.4nb1
= graphics/png png 1.2.32beta01 1.2.32beta01
= graphics/tiff tiff 3.8.2nb4 3.8.2nb4
= lang/perl5 perl 5.8.8nb8 5.8.8nb8
- net/netcat netcat 1.10nb2
+ pkgtools/digest digest 99.99.99
- pkgtools/x11-links x11-links 0.38
= sysutils/checkperms checkperms 1.10 1.10
= textproc/dict-client dict-client 1.9.15nb2 1.9.15nb2
= textproc/dictem dictem 0.82 0.82
= wip/awk-pkgsrc-dewey awk-pkgsrc-dewey 0.5.6 0.5.6
= wip/dict-client dict-client 1.10.11nb2 1.10.11nb2
< wip/dict-server dict-server 1.10.11nb2 1.11.0
= wip/distbb distbb 0.22.0 0.22.0
= wip/paexec paexec 0.10.0nb1 0.10.0nb1
= wip/pkg_online pkg_online 0.5.0nb2 0.5.0nb2
= wip/pkg_online-client pkg_online-client 0.5.0 0.5.0
= wip/pkg_online-server pkg_online-server 0.5.0 0.5.0
= wip/pkg_summary-utils pkg_summary-utils 0.18.1 0.18.1
> wip/runawk runawk 0.14.3 0.13.0
- www/ap2-vhost-ldap:PKG_APACHE=apache2 ap2-vhost-ldap 1.2.0nb1
- www/ap22-vhost-ldap ap22-vhost-ldap 1.2.0nb1
'

pkg_cmp_summary --with-pkgpath src_summary.txt src_summary2.txt | sort -k2,2 |
cmp 'pkg_cmp_summary #3' \
'= devel/gmake gmake 3.81 3.81
= devel/libltdl libltdl 1.5.24 1.5.24
= devel/libmaa libmaa 1.0.1nb1 1.0.1nb1
= devel/libtool-base libtool-base 1.5.24nb6 1.5.24nb6
< devel/pipestatus pipestatus 0.4.0 0.5.0
= devel/pkg-config pkg-config 0.23 0.23
= editors/emacs emacs 22.1nb6 22.1nb6
= graphics/jpeg jpeg 6bnb4 6bnb4
= graphics/libungif libungif 4.1.4nb1 4.1.4nb1
= graphics/png png 1.2.32beta01 1.2.32beta01
= graphics/tiff tiff 3.8.2nb4 3.8.2nb4
= lang/perl5 perl 5.8.8nb8 5.8.8nb8
- net/netcat netcat 1.10nb2
+ pkgtools/digest digest 99.99.99
- pkgtools/x11-links x11-links 0.38
= sysutils/checkperms checkperms 1.10 1.10
= textproc/dict-client dict-client 1.9.15nb2 1.9.15nb2
= textproc/dictem dictem 0.82 0.82
= wip/awk-pkgsrc-dewey awk-pkgsrc-dewey 0.5.6 0.5.6
= wip/dict-client dict-client 1.10.11nb2 1.10.11nb2
< wip/dict-server dict-server 1.10.11nb2 1.11.0
= wip/distbb distbb 0.22.0 0.22.0
= wip/paexec paexec 0.10.0nb1 0.10.0nb1
= wip/pkg_online pkg_online 0.5.0nb2 0.5.0nb2
= wip/pkg_online-client pkg_online-client 0.5.0 0.5.0
= wip/pkg_online-server pkg_online-server 0.5.0 0.5.0
= wip/pkg_summary-utils pkg_summary-utils 0.18.1 0.18.1
> wip/runawk runawk 0.14.3 0.13.0
- www/ap2-vhost-ldap:PKG_APACHE=apache2 ap2-vhost-ldap 1.2.0nb1
- www/ap22-vhost-ldap ap22-vhost-ldap 1.2.0nb1
'

pkg_cmp_summary src_summary4.txt src_summary5.txt | sort -k2,2 |
cmp 'pkg_cmp_summary #4' \
'= dictem 1.0.0 1.0.0
'

pkg_cmp_summary -p src_summary4.txt src_summary5.txt | sort -k2,2 |
cmp 'pkg_cmp_summary #5' \
'- textproc/dictem dictem 1.0.0
+ wip/dictem dictem 1.0.0
'

pkg_cmp_summary --use-checksum src_summary4.txt src_summary5.txt | sort -k2,2 |
cmp 'pkg_cmp_summary #6' \
'! dictem 1.0.0 1.0.0
'

pkg_cmp_summary -c src_summary4.txt src_summary5.txt | sort -k2,2 |
cmp 'pkg_cmp_summary #7' \
'! dictem 1.0.0 1.0.0
'

pkg_cmp_summary -cp src_summary4.txt src_summary6.txt | sort -k2,2 |
cmp 'pkg_cmp_summary #8' \
'! textproc/dictem dictem 1.0.0 1.0.0
'

pkg_cmp_summary -P src_summary.txt src_summary2.txt | sort -k2,2 |
cmp 'pkg_cmp_summary #9' \
'= devel/gmake
= devel/libltdl
= devel/libmaa
= devel/libtool-base
= devel/pipestatus
= devel/pkg-config
= editors/emacs
= graphics/jpeg
= graphics/libungif
= graphics/png
= graphics/tiff
= lang/perl5
- net/netcat
+ pkgtools/digest
- pkgtools/x11-links
= sysutils/checkperms
= textproc/dict-client
= textproc/dictem
= wip/awk-pkgsrc-dewey
= wip/dict-client
= wip/dict-server
= wip/distbb
= wip/paexec
= wip/pkg_online
= wip/pkg_online-client
= wip/pkg_online-server
= wip/pkg_summary-utils
= wip/runawk
- www/ap2-vhost-ldap:PKG_APACHE=apache2
- www/ap22-vhost-ldap
'

pkg_cmp_summary -p "$objdir"/summary_micro.txt "$objdir"/summary_full.txt |
grep -v '^=' |
cmp 'pkg_cmp_summary #10' \
''

pkg_cmp_summary -d summary1.txt summary2.txt |
cmp 'pkg_cmp_summary #11' \
'! baz 1.2.3 1.2.3
'

pkg_cmp_summary -d summary2.txt summary1.txt |
cmp 'pkg_cmp_summary #12' \
'! baz 1.2.3 1.2.3
'

pkg_cmp_summary -d summary1.txt summary4.txt |
cmp 'pkg_cmp_summary #13' \
'! baz 1.2.3 1.2.3
'

pkg_cmp_summary -d summary4.txt summary1.txt |
cmp 'pkg_cmp_summary #14' \
'! baz 1.2.3 1.2.3
'

pkg_cmp_summary -d summary1.txt summary3.txt |
cmp 'pkg_cmp_summary #15' \
'= baz 1.2.3 1.2.3
'

pkg_cmp_summary -d summary3.txt summary1.txt |
cmp 'pkg_cmp_summary #16' \
'= baz 1.2.3 1.2.3
'

# pkg_summary2build_graph
pkg_summary2build_graph src_summary.txt | sort |
cmp 'pkg_summary2build_graph #1' \
'devel/gmake devel/libmaa
devel/gmake editors/emacs
devel/gmake textproc/dict-client
devel/gmake wip/dict-client
devel/gmake wip/dict-server
devel/libltdl textproc/dict-client
devel/libmaa wip/dict-client
devel/libmaa wip/dict-server
devel/libmaa wip/paexec
devel/libtool-base devel/libltdl
devel/libtool-base devel/libmaa
devel/libtool-base devel/pkg-config
devel/libtool-base graphics/jpeg
devel/libtool-base graphics/libungif
devel/libtool-base graphics/png
devel/libtool-base graphics/tiff
devel/libtool-base wip/dict-client
devel/libtool-base wip/dict-server
devel/pipestatus wip/pkg_online-client
devel/pipestatus wip/pkg_online-server
devel/pipestatus wip/pkg_summary-utils
devel/pkg-config editors/emacs
editors/emacs textproc/dictem
graphics/jpeg editors/emacs
graphics/jpeg graphics/tiff
graphics/libungif editors/emacs
graphics/png editors/emacs
graphics/tiff editors/emacs
lang/perl5 editors/emacs
lang/perl5 graphics/libungif
net/netcat wip/pkg_online-client
pkgtools/x11-links editors/emacs
sysutils/checkperms devel/gmake
sysutils/checkperms devel/libltdl
sysutils/checkperms devel/libmaa
sysutils/checkperms devel/libtool-base
sysutils/checkperms devel/pipestatus
sysutils/checkperms devel/pkg-config
sysutils/checkperms editors/emacs
sysutils/checkperms graphics/jpeg
sysutils/checkperms graphics/libungif
sysutils/checkperms graphics/png
sysutils/checkperms graphics/tiff
sysutils/checkperms lang/perl5
sysutils/checkperms net/netcat
sysutils/checkperms pkgtools/x11-links
sysutils/checkperms textproc/dict-client
sysutils/checkperms textproc/dictem
sysutils/checkperms wip/awk-pkgsrc-dewey
sysutils/checkperms wip/dict-client
sysutils/checkperms wip/dict-server
sysutils/checkperms wip/distbb
sysutils/checkperms wip/paexec
sysutils/checkperms wip/pkg_online
sysutils/checkperms wip/pkg_online-client
sysutils/checkperms wip/pkg_online-server
sysutils/checkperms wip/pkg_summary-utils
sysutils/checkperms wip/runawk
textproc/dict-client textproc/dictem
wip/awk-pkgsrc-dewey wip/pkg_summary-utils
wip/dict-client wip/pkg_online-client
wip/dict-server wip/pkg_online-server
wip/paexec wip/distbb
wip/pkg_online-client wip/pkg_online
wip/pkg_online-server wip/pkg_online
wip/pkg_summary-utils wip/distbb
wip/pkg_summary-utils wip/pkg_online-client
wip/pkg_summary-utils wip/pkg_online-server
wip/runawk wip/awk-pkgsrc-dewey
wip/runawk wip/distbb
wip/runawk wip/pkg_summary-utils
www/ap2-vhost-ldap:PKG_APACHE=apache2
www/ap22-vhost-ldap:PKG_APACHE=apache22
'

pkg_summary2build_graph -s src_summary.txt 2>&1 >/dev/null | sort |
cmp 'pkg_summary2build_graph #2' \
'Cannot find dependency libmaa>=1.2 for package wip/dict-server (dict-server-1.10.11nb2)
Cannot find dependency pkg_summary-utils>=0.19.0 for package wip/pkg_online-server (pkg_online-server-0.5.0)
'

pkg_summary2build_graph src_summary2.txt | sort |
cmp 'pkg_summary2build_graph #3' \
'devel/gmake
devel/libltdl
devel/libmaa wip/dict-client
devel/libtool-base
devel/pipestatus
devel/pkg-config
editors/emacs
graphics/jpeg
graphics/libungif
graphics/png
graphics/tiff
lang/perl5
pkgtools/digest
sysutils/checkperms
textproc/dict-client
textproc/dictem
wip/awk-pkgsrc-dewey
wip/dict-client wip/pkg_online-client
wip/dict-server
wip/distbb
wip/paexec
wip/pkg_online-client wip/pkg_online
wip/pkg_online-server wip/pkg_online
wip/pkg_summary-utils
wip/runawk
'

pkg_summary2build_graph -s src_summary2.txt 2>&1 >/dev/null | sort |
cmp 'pkg_summary2build_graph #4' \
'Cannot find dependency pkg_online-client-0.5.0nb2 for package wip/pkg_online (pkg_online-0.5.0nb2)
Cannot find dependency pkg_online-server-0.5.0nb2 for package wip/pkg_online (pkg_online-0.5.0nb2)
'

pkg_summary2build_graph src_summary7.txt | sort |
cmp 'pkg_summary2build_graph #5' \
'audio/py-mutagen audio/py-karaoke
audio/py-mutagen:PYTHON_VERSION_REQD=24 audio/py-karaoke:PYTHON_VERSION_REQD=24
audio/py-mutagen:PYTHON_VERSION_REQD=26 audio/py-karaoke:PYTHON_VERSION_REQD=26
'

pkg_summary2build_graph src_summary8.txt | sort | uniq |
cmp 'pkg_summary2build_graph #6' \
'archivers/p5-Archive-Tar devel/p5-Module-Build
devel/p5-Algorithm-Diff textproc/p5-Text-Diff
devel/p5-Compress-Raw-Bzip2 devel/p5-IO-Compress
devel/p5-Compress-Raw-Zlib devel/p5-IO-Compress
devel/p5-ExtUtils-CBuilder devel/p5-Module-Build
devel/p5-ExtUtils-ParseXS devel/p5-Module-Build
devel/p5-IO-Compress archivers/p5-Archive-Tar
devel/p5-IO-Compress devel/p5-IO-Zlib
devel/p5-IO-String archivers/p5-Archive-Tar
devel/p5-IO-Zlib archivers/p5-Archive-Tar
devel/p5-version devel/p5-Module-Build
lang/perl5 archivers/p5-Archive-Tar
lang/perl5 devel/p5-Algorithm-Diff
lang/perl5 devel/p5-Compress-Raw-Bzip2
lang/perl5 devel/p5-Compress-Raw-Zlib
lang/perl5 devel/p5-ExtUtils-CBuilder
lang/perl5 devel/p5-ExtUtils-ParseXS
lang/perl5 devel/p5-IO-Compress
lang/perl5 devel/p5-IO-String
lang/perl5 devel/p5-IO-Zlib
lang/perl5 devel/p5-Module-Build
lang/perl5 devel/p5-version
lang/perl5 textproc/p5-Filter
lang/perl5 textproc/p5-Pod-Readme
lang/perl5 textproc/p5-Regexp-Common
lang/perl5 textproc/p5-Text-Diff
lang/perl5 textproc/p5-YAML
sysutils/checkperms archivers/p5-Archive-Tar
sysutils/checkperms devel/p5-Algorithm-Diff
sysutils/checkperms devel/p5-Compress-Raw-Bzip2
sysutils/checkperms devel/p5-Compress-Raw-Zlib
sysutils/checkperms devel/p5-ExtUtils-CBuilder
sysutils/checkperms devel/p5-ExtUtils-ParseXS
sysutils/checkperms devel/p5-IO-Compress
sysutils/checkperms devel/p5-IO-String
sysutils/checkperms devel/p5-IO-Zlib
sysutils/checkperms devel/p5-Module-Build
sysutils/checkperms devel/p5-version
sysutils/checkperms lang/perl5
sysutils/checkperms textproc/p5-Filter
sysutils/checkperms textproc/p5-Pod-Readme
sysutils/checkperms textproc/p5-Regexp-Common
sysutils/checkperms textproc/p5-Text-Diff
sysutils/checkperms textproc/p5-YAML
textproc/p5-Filter textproc/p5-YAML
textproc/p5-Pod-Readme devel/p5-Module-Build
textproc/p5-Regexp-Common textproc/p5-Pod-Readme
textproc/p5-Text-Diff archivers/p5-Archive-Tar
textproc/p5-YAML devel/p5-Module-Build
'


#test -f "$tmpex"
#exit $?

# pkg_summary2deps
pkg_summary2deps -Apn src_summary.txt | sort |
cmp 'pkg_summary2deps #1' \
'devel/gmake;gmake devel/libmaa;libmaa
devel/gmake;gmake editors/emacs;emacs
devel/gmake;gmake textproc/dict-client;dict-client
devel/gmake;gmake wip/dict-client;dict-client
devel/gmake;gmake wip/dict-server;dict-server
devel/libltdl;libltdl textproc/dict-client;dict-client
devel/libmaa;libmaa wip/dict-client;dict-client
devel/libmaa;libmaa wip/dict-server;dict-server
devel/libmaa;libmaa wip/paexec;paexec
devel/libtool-base;libtool-base devel/libltdl;libltdl
devel/libtool-base;libtool-base devel/libmaa;libmaa
devel/libtool-base;libtool-base devel/pkg-config;pkg-config
devel/libtool-base;libtool-base graphics/jpeg;jpeg
devel/libtool-base;libtool-base graphics/libungif;libungif
devel/libtool-base;libtool-base graphics/png;png
devel/libtool-base;libtool-base graphics/tiff;tiff
devel/libtool-base;libtool-base wip/dict-client;dict-client
devel/libtool-base;libtool-base wip/dict-server;dict-server
devel/pipestatus;pipestatus wip/pkg_online-client;pkg_online-client
devel/pipestatus;pipestatus wip/pkg_online-server;pkg_online-server
devel/pipestatus;pipestatus wip/pkg_summary-utils;pkg_summary-utils
devel/pkg-config;pkg-config editors/emacs;emacs
editors/emacs;emacs textproc/dictem;dictem
graphics/jpeg;jpeg editors/emacs;emacs
graphics/jpeg;jpeg graphics/tiff;tiff
graphics/libungif;libungif editors/emacs;emacs
graphics/png;png editors/emacs;emacs
graphics/tiff;tiff editors/emacs;emacs
lang/perl5;perl editors/emacs;emacs
lang/perl5;perl graphics/libungif;libungif
net/netcat;netcat wip/pkg_online-client;pkg_online-client
pkgtools/x11-links;x11-links editors/emacs;emacs
sysutils/checkperms;checkperms devel/gmake;gmake
sysutils/checkperms;checkperms devel/libltdl;libltdl
sysutils/checkperms;checkperms devel/libmaa;libmaa
sysutils/checkperms;checkperms devel/libtool-base;libtool-base
sysutils/checkperms;checkperms devel/pipestatus;pipestatus
sysutils/checkperms;checkperms devel/pkg-config;pkg-config
sysutils/checkperms;checkperms editors/emacs;emacs
sysutils/checkperms;checkperms graphics/jpeg;jpeg
sysutils/checkperms;checkperms graphics/libungif;libungif
sysutils/checkperms;checkperms graphics/png;png
sysutils/checkperms;checkperms graphics/tiff;tiff
sysutils/checkperms;checkperms lang/perl5;perl
sysutils/checkperms;checkperms net/netcat;netcat
sysutils/checkperms;checkperms pkgtools/x11-links;x11-links
sysutils/checkperms;checkperms textproc/dict-client;dict-client
sysutils/checkperms;checkperms textproc/dictem;dictem
sysutils/checkperms;checkperms wip/awk-pkgsrc-dewey;awk-pkgsrc-dewey
sysutils/checkperms;checkperms wip/dict-client;dict-client
sysutils/checkperms;checkperms wip/dict-server;dict-server
sysutils/checkperms;checkperms wip/distbb;distbb
sysutils/checkperms;checkperms wip/paexec;paexec
sysutils/checkperms;checkperms wip/pkg_online-client;pkg_online-client
sysutils/checkperms;checkperms wip/pkg_online-server;pkg_online-server
sysutils/checkperms;checkperms wip/pkg_online;pkg_online
sysutils/checkperms;checkperms wip/pkg_summary-utils;pkg_summary-utils
sysutils/checkperms;checkperms wip/runawk;runawk
textproc/dict-client;dict-client textproc/dictem;dictem
wip/awk-pkgsrc-dewey;awk-pkgsrc-dewey wip/pkg_summary-utils;pkg_summary-utils
wip/dict-client;dict-client wip/pkg_online-client;pkg_online-client
wip/dict-server;dict-server wip/pkg_online-server;pkg_online-server
wip/paexec;paexec wip/distbb;distbb
wip/pkg_online-client;pkg_online-client wip/pkg_online;pkg_online
wip/pkg_online-server;pkg_online-server wip/pkg_online;pkg_online
wip/pkg_summary-utils;pkg_summary-utils wip/distbb;distbb
wip/pkg_summary-utils;pkg_summary-utils wip/pkg_online-client;pkg_online-client
wip/pkg_summary-utils;pkg_summary-utils wip/pkg_online-server;pkg_online-server
wip/runawk;runawk wip/awk-pkgsrc-dewey;awk-pkgsrc-dewey
wip/runawk;runawk wip/distbb;distbb
wip/runawk;runawk wip/pkg_summary-utils;pkg_summary-utils
www/ap2-vhost-ldap:PKG_APACHE=apache2;ap2-vhost-ldap
www/ap22-vhost-ldap:PKG_APACHE=apache22;ap22-vhost-ldap
'

pkg_summary2deps -dnt src_summary.txt | sort |
cmp 'pkg_summary2deps #2' \
'ap2-vhost-ldap ap2-vhost-ldap
ap22-vhost-ldap ap22-vhost-ldap
awk-pkgsrc-dewey pkg_summary-utils
checkperms checkperms
dict-client dictem
dict-client pkg_online-client
dict-server pkg_online-server
emacs dictem
gmake gmake
jpeg emacs
jpeg tiff
libltdl dict-client
libmaa dict-client
libmaa dict-server
libmaa paexec
libtool-base libtool-base
libungif emacs
netcat pkg_online-client
paexec distbb
perl emacs
perl libungif
pipestatus pkg_online-client
pipestatus pkg_online-server
pipestatus pkg_summary-utils
pkg-config pkg-config
pkg_online-client pkg_online
pkg_online-server pkg_online
pkg_summary-utils distbb
pkg_summary-utils pkg_online-client
pkg_summary-utils pkg_online-server
png emacs
runawk awk-pkgsrc-dewey
runawk distbb
runawk pkg_summary-utils
tiff emacs
x11-links x11-links
'

pkg_summary2deps -Apntr src_summary7.txt | sort |
cmp 'pkg_summary2deps #3' \
'audio/py-mutagen:PYTHON_VERSION_REQD=24;py24-mutagen-1.15 audio/py-karaoke:PYTHON_VERSION_REQD=24;py24-karaoke-0.7.1
audio/py-mutagen:PYTHON_VERSION_REQD=26;py26-mutagen-1.15 audio/py-karaoke:PYTHON_VERSION_REQD=26;py26-karaoke-0.7.1
audio/py-mutagen;py25-mutagen-1.15 audio/py-karaoke;py25-karaoke-0.7.1
'

pkg_summary2deps -Dp src_summary8.txt | sort | uniq |
cmp 'pkg_summary2deps #4' \
'lang/perl5 devel/p5-ExtUtils-CBuilder
lang/perl5 devel/p5-ExtUtils-ParseXS
lang/perl5 devel/p5-Module-Build
lang/perl5 devel/p5-version
sysutils/checkperms archivers/p5-Archive-Tar
sysutils/checkperms devel/p5-Algorithm-Diff
sysutils/checkperms devel/p5-Compress-Raw-Bzip2
sysutils/checkperms devel/p5-Compress-Raw-Zlib
sysutils/checkperms devel/p5-ExtUtils-CBuilder
sysutils/checkperms devel/p5-ExtUtils-ParseXS
sysutils/checkperms devel/p5-IO-Compress
sysutils/checkperms devel/p5-IO-String
sysutils/checkperms devel/p5-IO-Zlib
sysutils/checkperms devel/p5-Module-Build
sysutils/checkperms devel/p5-version
sysutils/checkperms lang/perl5
sysutils/checkperms textproc/p5-Filter
sysutils/checkperms textproc/p5-Pod-Readme
sysutils/checkperms textproc/p5-Regexp-Common
sysutils/checkperms textproc/p5-Text-Diff
sysutils/checkperms textproc/p5-YAML
textproc/p5-YAML devel/p5-Module-Build
'

pkg_summary2deps -Dpr src_summary8.txt | sort | uniq |
cmp 'pkg_summary2deps #5' \
'lang/perl5;perl-5.10.0nb7 devel/p5-ExtUtils-CBuilder;p5-ExtUtils-CBuilder-0.26.03.01
lang/perl5;perl-5.10.0nb7 devel/p5-ExtUtils-ParseXS;p5-ExtUtils-ParseXS-2.20.04.01
lang/perl5;perl-5.10.0nb7 devel/p5-Module-Build;p5-Module-Build-0.35000
lang/perl5;perl-5.10.0nb7 devel/p5-version;p5-version-0.7702
sysutils/checkperms;checkperms-1.10 archivers/p5-Archive-Tar;p5-Archive-Tar-1.54
sysutils/checkperms;checkperms-1.10 devel/p5-Algorithm-Diff;p5-Algorithm-Diff-1.1902nb1
sysutils/checkperms;checkperms-1.10 devel/p5-Compress-Raw-Bzip2;p5-Compress-Raw-Bzip2-2.021
sysutils/checkperms;checkperms-1.10 devel/p5-Compress-Raw-Zlib;p5-Compress-Raw-Zlib-2.021
sysutils/checkperms;checkperms-1.10 devel/p5-ExtUtils-CBuilder;p5-ExtUtils-CBuilder-0.26.03.01
sysutils/checkperms;checkperms-1.10 devel/p5-ExtUtils-ParseXS;p5-ExtUtils-ParseXS-2.20.04.01
sysutils/checkperms;checkperms-1.10 devel/p5-IO-Compress;p5-IO-Compress-2.021
sysutils/checkperms;checkperms-1.10 devel/p5-IO-String;p5-IO-String-1.08nb1
sysutils/checkperms;checkperms-1.10 devel/p5-IO-Zlib;p5-IO-Zlib-1.10
sysutils/checkperms;checkperms-1.10 devel/p5-Module-Build;p5-Module-Build-0.35000
sysutils/checkperms;checkperms-1.10 devel/p5-version;p5-version-0.7702
sysutils/checkperms;checkperms-1.10 lang/perl5;perl-5.10.0nb7
sysutils/checkperms;checkperms-1.10 textproc/p5-Filter;p5-Filter-1.37
sysutils/checkperms;checkperms-1.10 textproc/p5-Pod-Readme;p5-Pod-Readme-0.09
sysutils/checkperms;checkperms-1.10 textproc/p5-Regexp-Common;p5-Regexp-Common-2.122nb1
sysutils/checkperms;checkperms-1.10 textproc/p5-Text-Diff;p5-Text-Diff-1.37
sysutils/checkperms;checkperms-1.10 textproc/p5-YAML;p5-YAML-0.70
textproc/p5-YAML;p5-YAML-0.70 devel/p5-Module-Build;p5-Module-Build-0.35000
'

pkg_summary2deps -ApnR src_summary.txt | sort |
cmp 'pkg_summary2deps #6' \
'devel/gmake;gmake devel/libmaa;libmaa ( gmake>=3.81 )
devel/gmake;gmake editors/emacs;emacs ( gmake>=3.81 )
devel/gmake;gmake textproc/dict-client;dict-client ( gmake>=3.81 )
devel/gmake;gmake wip/dict-client;dict-client ( gmake>=3.81 )
devel/gmake;gmake wip/dict-server;dict-server ( gmake>=3.81 )
devel/libltdl;libltdl textproc/dict-client;dict-client ( libltdl>=1.5.10 )
devel/libmaa;libmaa wip/dict-client;dict-client ( libmaa>=1.0 )
devel/libmaa;libmaa wip/dict-server;dict-server ( libmaa>=1.2 )
devel/libmaa;libmaa wip/paexec;paexec ( libmaa>=0.990 )
devel/libtool-base;libtool-base devel/libltdl;libltdl ( libtool-base>=1.5.18nb5 )
devel/libtool-base;libtool-base devel/libmaa;libmaa ( libtool-base>=1.5.18nb5 )
devel/libtool-base;libtool-base devel/pkg-config;pkg-config ( libtool-base>=1.5.18nb5 )
devel/libtool-base;libtool-base graphics/jpeg;jpeg ( libtool-base>=1.5.18nb5 )
devel/libtool-base;libtool-base graphics/libungif;libungif ( libtool-base>=1.5.18nb5 )
devel/libtool-base;libtool-base graphics/png;png ( libtool-base>=1.5.18nb5 )
devel/libtool-base;libtool-base graphics/tiff;tiff ( libtool-base>=1.5.18nb5 )
devel/libtool-base;libtool-base wip/dict-client;dict-client ( libtool-base>=1.5.18nb5 )
devel/libtool-base;libtool-base wip/dict-server;dict-server ( libtool-base>=1.5.18nb5 )
devel/pipestatus;pipestatus wip/pkg_online-client;pkg_online-client ( pipestatus-[0-9]* )
devel/pipestatus;pipestatus wip/pkg_online-server;pkg_online-server ( pipestatus-[0-9]* )
devel/pipestatus;pipestatus wip/pkg_summary-utils;pkg_summary-utils ( pipestatus-[0-9]* )
devel/pkg-config;pkg-config editors/emacs;emacs ( pkg-config>=0.19 )
editors/emacs;emacs textproc/dictem;dictem ( emacs>=22 )
graphics/jpeg;jpeg editors/emacs;emacs ( jpeg>=6bnb2 )
graphics/jpeg;jpeg graphics/tiff;tiff ( jpeg>=6bnb2 )
graphics/libungif;libungif editors/emacs;emacs ( libungif>=4.1.3nb1 )
graphics/png;png editors/emacs;emacs ( png>=1.2.9nb2 )
graphics/tiff;tiff editors/emacs;emacs ( tiff>=3.7.2nb1 )
lang/perl5;perl editors/emacs;emacs ( perl>=5.0 )
lang/perl5;perl graphics/libungif;libungif ( perl>=5.0 )
net/netcat;netcat wip/pkg_online-client;pkg_online-client ( netcat-[0-9]* )
pkgtools/x11-links;x11-links editors/emacs;emacs ( x11-links>=0.38 )
sysutils/checkperms;checkperms devel/gmake;gmake ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/libltdl;libltdl ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/libmaa;libmaa ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/libtool-base;libtool-base ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/pipestatus;pipestatus ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/pkg-config;pkg-config ( checkperms>=1.1 )
sysutils/checkperms;checkperms editors/emacs;emacs ( checkperms>=1.1 )
sysutils/checkperms;checkperms graphics/jpeg;jpeg ( checkperms>=1.1 )
sysutils/checkperms;checkperms graphics/libungif;libungif ( checkperms>=1.1 )
sysutils/checkperms;checkperms graphics/png;png ( checkperms>=1.1 )
sysutils/checkperms;checkperms graphics/tiff;tiff ( checkperms>=1.1 )
sysutils/checkperms;checkperms lang/perl5;perl ( checkperms>=1.1 )
sysutils/checkperms;checkperms net/netcat;netcat ( checkperms>=1.1 )
sysutils/checkperms;checkperms pkgtools/x11-links;x11-links ( checkperms>=1.1 )
sysutils/checkperms;checkperms textproc/dict-client;dict-client ( checkperms>=1.1 )
sysutils/checkperms;checkperms textproc/dictem;dictem ( checkperms>=1.1 )
sysutils/checkperms;checkperms wip/awk-pkgsrc-dewey;awk-pkgsrc-dewey ( checkperms>=1.1 )
sysutils/checkperms;checkperms wip/dict-client;dict-client ( checkperms>=1.1 )
sysutils/checkperms;checkperms wip/dict-server;dict-server ( checkperms>=1.1 )
sysutils/checkperms;checkperms wip/distbb;distbb ( checkperms>=1.1 )
sysutils/checkperms;checkperms wip/paexec;paexec ( checkperms>=1.1 )
sysutils/checkperms;checkperms wip/pkg_online-client;pkg_online-client ( checkperms>=1.1 )
sysutils/checkperms;checkperms wip/pkg_online-server;pkg_online-server ( checkperms>=1.1 )
sysutils/checkperms;checkperms wip/pkg_online;pkg_online ( checkperms>=1.1 )
sysutils/checkperms;checkperms wip/pkg_summary-utils;pkg_summary-utils ( checkperms>=1.1 )
sysutils/checkperms;checkperms wip/runawk;runawk ( checkperms>=1.1 )
textproc/dict-client;dict-client textproc/dictem;dictem ( dict-client>=1.9.14 )
wip/awk-pkgsrc-dewey;awk-pkgsrc-dewey wip/pkg_summary-utils;pkg_summary-utils ( awk-pkgsrc-dewey>=0.5.6 )
wip/dict-client;dict-client wip/pkg_online-client;pkg_online-client ( dict-client>=1.10.9 )
wip/dict-server;dict-server wip/pkg_online-server;pkg_online-server ( dict-server>=1.10.10nb2 )
wip/paexec;paexec wip/distbb;distbb ( paexec>=0.10.0 )
wip/pkg_online-client;pkg_online-client wip/pkg_online;pkg_online ( pkg_online-client-[0-9]* )
wip/pkg_online-server;pkg_online-server wip/pkg_online;pkg_online ( pkg_online-server-[0-9]* )
wip/pkg_summary-utils;pkg_summary-utils wip/distbb;distbb ( pkg_summary-utils>=0.18.1 )
wip/pkg_summary-utils;pkg_summary-utils wip/pkg_online-client;pkg_online-client ( pkg_summary-utils-[0-9]* )
wip/pkg_summary-utils;pkg_summary-utils wip/pkg_online-server;pkg_online-server ( pkg_summary-utils>=0.19.0 )
wip/runawk;runawk wip/awk-pkgsrc-dewey;awk-pkgsrc-dewey ( runawk-[0-9]* )
wip/runawk;runawk wip/distbb;distbb ( runawk>=0.13.0 )
wip/runawk;runawk wip/pkg_summary-utils;pkg_summary-utils ( runawk>=0.12.1 )
www/ap2-vhost-ldap:PKG_APACHE=apache2;ap2-vhost-ldap
www/ap22-vhost-ldap:PKG_APACHE=apache22;ap22-vhost-ldap
'

pkg_summary2deps -dntR src_summary.txt | sort |
cmp 'pkg_summary2deps #7' \
'ap2-vhost-ldap ap2-vhost-ldap
ap22-vhost-ldap ap22-vhost-ldap
awk-pkgsrc-dewey pkg_summary-utils ( awk-pkgsrc-dewey>=0.5.6 )
checkperms checkperms
dict-client dictem ( dict-client>=1.9.14 )
dict-client pkg_online-client ( dict-client>=1.10.9 )
dict-server pkg_online-server ( dict-server>=1.10.10nb2 )
emacs dictem ( emacs>=22 )
gmake gmake
jpeg emacs ( jpeg>=6bnb2 )
jpeg tiff ( jpeg>=6bnb2 )
libltdl dict-client ( libltdl>=1.5.10 )
libmaa dict-client ( libmaa>=1.0 )
libmaa dict-server ( libmaa>=1.2 )
libmaa paexec ( libmaa>=0.990 )
libtool-base libtool-base
libungif emacs ( libungif>=4.1.3nb1 )
netcat pkg_online-client ( netcat-[0-9]* )
paexec distbb ( paexec>=0.10.0 )
perl emacs ( perl>=5.0 )
perl libungif ( perl>=5.0 )
pipestatus pkg_online-client ( pipestatus-[0-9]* )
pipestatus pkg_online-server ( pipestatus-[0-9]* )
pipestatus pkg_summary-utils ( pipestatus-[0-9]* )
pkg-config pkg-config
pkg_online-client pkg_online ( pkg_online-client-[0-9]* )
pkg_online-server pkg_online ( pkg_online-server-[0-9]* )
pkg_summary-utils distbb ( pkg_summary-utils>=0.18.1 )
pkg_summary-utils pkg_online-client ( pkg_summary-utils-[0-9]* )
pkg_summary-utils pkg_online-server ( pkg_summary-utils>=0.19.0 )
png emacs ( png>=1.2.9nb2 )
runawk awk-pkgsrc-dewey ( runawk-[0-9]* )
runawk distbb ( runawk>=0.13.0 )
runawk pkg_summary-utils ( runawk>=0.12.1 )
tiff emacs ( tiff>=3.7.2nb1 )
x11-links x11-links
'

pkg_summary2deps -ApntrR src_summary7.txt | sort |
cmp 'pkg_summary2deps #8' \
'audio/py-mutagen:PYTHON_VERSION_REQD=24;py24-mutagen-1.15 audio/py-karaoke:PYTHON_VERSION_REQD=24;py24-karaoke-0.7.1 ( py24-mutagen>=1.9 )
audio/py-mutagen:PYTHON_VERSION_REQD=26;py26-mutagen-1.15 audio/py-karaoke:PYTHON_VERSION_REQD=26;py26-karaoke-0.7.1 ( py26-mutagen>=1.9 )
audio/py-mutagen;py25-mutagen-1.15 audio/py-karaoke;py25-karaoke-0.7.1 ( py25-mutagen>=1.9 )
'

pkg_summary2deps -DpR src_summary8.txt | sort | uniq |
cmp 'pkg_summary2deps #9' \
'lang/perl5;perl devel/p5-ExtUtils-CBuilder;p5-ExtUtils-CBuilder ( perl>=5.10 )
lang/perl5;perl devel/p5-ExtUtils-ParseXS;p5-ExtUtils-ParseXS ( perl>=5.10 )
lang/perl5;perl devel/p5-Module-Build;p5-Module-Build ( perl>=5.10.0 )
lang/perl5;perl devel/p5-version;p5-version ( perl>=5.10 )
sysutils/checkperms;checkperms archivers/p5-Archive-Tar;p5-Archive-Tar ( checkperms>=1.0 )
sysutils/checkperms;checkperms devel/p5-Algorithm-Diff;p5-Algorithm-Diff ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/p5-Compress-Raw-Bzip2;p5-Compress-Raw-Bzip2 ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/p5-Compress-Raw-Zlib;p5-Compress-Raw-Zlib ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/p5-ExtUtils-CBuilder;p5-ExtUtils-CBuilder ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/p5-ExtUtils-ParseXS;p5-ExtUtils-ParseXS ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/p5-IO-Compress;p5-IO-Compress ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/p5-IO-String;p5-IO-String ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/p5-IO-Zlib;p5-IO-Zlib ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/p5-Module-Build;p5-Module-Build ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/p5-version;p5-version ( checkperms>=1.1 )
sysutils/checkperms;checkperms lang/perl5;perl ( checkperms>=1.1 )
sysutils/checkperms;checkperms textproc/p5-Filter;p5-Filter ( checkperms>=1.1 )
sysutils/checkperms;checkperms textproc/p5-Pod-Readme;p5-Pod-Readme ( checkperms>=1.1 )
sysutils/checkperms;checkperms textproc/p5-Regexp-Common;p5-Regexp-Common ( checkperms>=1.1 )
sysutils/checkperms;checkperms textproc/p5-Text-Diff;p5-Text-Diff ( checkperms>=1.1 )
sysutils/checkperms;checkperms textproc/p5-YAML;p5-YAML ( checkperms>=1.1 )
textproc/p5-YAML;p5-YAML devel/p5-Module-Build;p5-Module-Build ( p5-YAML>=0.50 )
'

pkg_summary2deps -DpRr src_summary8.txt | sort | uniq |
cmp 'pkg_summary2deps #10' \
'lang/perl5;perl-5.10.0nb7 devel/p5-ExtUtils-CBuilder;p5-ExtUtils-CBuilder-0.26.03.01 ( perl>=5.10 )
lang/perl5;perl-5.10.0nb7 devel/p5-ExtUtils-ParseXS;p5-ExtUtils-ParseXS-2.20.04.01 ( perl>=5.10 )
lang/perl5;perl-5.10.0nb7 devel/p5-Module-Build;p5-Module-Build-0.35000 ( perl>=5.10.0 )
lang/perl5;perl-5.10.0nb7 devel/p5-version;p5-version-0.7702 ( perl>=5.10 )
sysutils/checkperms;checkperms-1.10 archivers/p5-Archive-Tar;p5-Archive-Tar-1.54 ( checkperms>=1.0 )
sysutils/checkperms;checkperms-1.10 devel/p5-Algorithm-Diff;p5-Algorithm-Diff-1.1902nb1 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 devel/p5-Compress-Raw-Bzip2;p5-Compress-Raw-Bzip2-2.021 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 devel/p5-Compress-Raw-Zlib;p5-Compress-Raw-Zlib-2.021 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 devel/p5-ExtUtils-CBuilder;p5-ExtUtils-CBuilder-0.26.03.01 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 devel/p5-ExtUtils-ParseXS;p5-ExtUtils-ParseXS-2.20.04.01 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 devel/p5-IO-Compress;p5-IO-Compress-2.021 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 devel/p5-IO-String;p5-IO-String-1.08nb1 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 devel/p5-IO-Zlib;p5-IO-Zlib-1.10 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 devel/p5-Module-Build;p5-Module-Build-0.35000 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 devel/p5-version;p5-version-0.7702 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 lang/perl5;perl-5.10.0nb7 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 textproc/p5-Filter;p5-Filter-1.37 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 textproc/p5-Pod-Readme;p5-Pod-Readme-0.09 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 textproc/p5-Regexp-Common;p5-Regexp-Common-2.122nb1 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 textproc/p5-Text-Diff;p5-Text-Diff-1.37 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 textproc/p5-YAML;p5-YAML-0.70 ( checkperms>=1.1 )
textproc/p5-YAML;p5-YAML-0.70 devel/p5-Module-Build;p5-Module-Build-0.35000 ( p5-YAML>=0.50 )
'

pkg_summary2deps -dn bin_summary1.txt | sort |
cmp 'pkg_summary2deps #11' \
'awk-pkgsrc-dewey pkg_summary-utils
checkperms
dict-client pkg_online-client
dict-server pkg_online-server
gmake
libmaa dict-client
libmaa dict-server
libmaa paexec
libtool-base
netcat pkg_online-client
paexec distbb
pipestatus distbb
pipestatus pkg_online-client
pipestatus pkg_online-server
pipestatus pkg_summary-utils
pkg_online-client pkg_conflicts
pkg_online-client pkg_online
pkg_online-server pkg_online
pkg_summary-utils distbb
pkg_summary-utils pkg_conflicts
pkg_summary-utils pkg_online-client
pkg_summary-utils pkg_online-server
runawk awk-pkgsrc-dewey
runawk distbb
runawk paexec
runawk pkg_conflicts
runawk pkg_summary-utils
'

pkg_summary2deps -Apn bin_summary1.txt | sort |
cmp 'pkg_summary2deps #12' \
'devel/gmake;gmake
devel/libmaa;libmaa wip/dict-client;dict-client
devel/libmaa;libmaa wip/dict-server;dict-server
devel/libmaa;libmaa wip/paexec;paexec
devel/libtool-base;libtool-base
devel/pipestatus;pipestatus wip/distbb;distbb
devel/pipestatus;pipestatus wip/pkg_online-client;pkg_online-client
devel/pipestatus;pipestatus wip/pkg_online-server;pkg_online-server
devel/pipestatus;pipestatus wip/pkg_summary-utils;pkg_summary-utils
net/netcat;netcat wip/pkg_online-client;pkg_online-client
sysutils/checkperms;checkperms
wip/awk-pkgsrc-dewey;awk-pkgsrc-dewey wip/pkg_summary-utils;pkg_summary-utils
wip/dict-client;dict-client wip/pkg_online-client;pkg_online-client
wip/dict-server;dict-server wip/pkg_online-server;pkg_online-server
wip/paexec;paexec wip/distbb;distbb
wip/pkg_online-client;pkg_online-client wip/pkg_conflicts;pkg_conflicts
wip/pkg_online-client;pkg_online-client wip/pkg_online;pkg_online
wip/pkg_online-server;pkg_online-server wip/pkg_online;pkg_online
wip/pkg_summary-utils;pkg_summary-utils wip/distbb;distbb
wip/pkg_summary-utils;pkg_summary-utils wip/pkg_conflicts;pkg_conflicts
wip/pkg_summary-utils;pkg_summary-utils wip/pkg_online-client;pkg_online-client
wip/pkg_summary-utils;pkg_summary-utils wip/pkg_online-server;pkg_online-server
wip/runawk;runawk wip/awk-pkgsrc-dewey;awk-pkgsrc-dewey
wip/runawk;runawk wip/distbb;distbb
wip/runawk;runawk wip/paexec;paexec
wip/runawk;runawk wip/pkg_conflicts;pkg_conflicts
wip/runawk;runawk wip/pkg_summary-utils;pkg_summary-utils
'

pkg_summary2deps -ArR bin_summary1.txt | sort |
cmp 'pkg_summary2deps #13' \
'awk-pkgsrc-dewey-0.5.6 pkg_summary-utils-0.35rc1 ( awk-pkgsrc-dewey>=0.5.6 )
checkperms-1.10
dict-client-1.11.2 pkg_online-client-0.9.1 ( dict-client>=1.10.9 )
dict-server-1.11.2 pkg_online-server-0.9.1 ( dict-server>=1.10.10nb2 )
gmake-3.81
libmaa-1.1.0 dict-client-1.11.2 ( libmaa>=0.990 )
libmaa-1.1.0 dict-server-1.11.2 ( libmaa>=0.990 )
libmaa-1.1.0 paexec-0.13.0nb1 ( libmaa>=0.990 )
libtool-base-1.5.26nb2
netcat-1.10nb2 pkg_online-client-0.9.1 ( netcat-[0-9]* )
paexec-0.13.0nb1 distbb-0.33.0 ( paexec>=0.13.0nb1 )
pipestatus-0.6.0 distbb-0.33.0 ( pipestatus>=0.5.0 )
pipestatus-0.6.0 pkg_online-client-0.9.1 ( pipestatus-[0-9]* )
pipestatus-0.6.0 pkg_online-server-0.9.1 ( pipestatus-[0-9]* )
pipestatus-0.6.0 pkg_summary-utils-0.35rc1 ( pipestatus-[0-9]* )
pkg_online-client-0.9.1 pkg_conflicts-0.4.0 ( pkg_online-client>=0.6.0 )
pkg_online-client-0.9.1 pkg_online-0.9.1 ( pkg_online-client-0.9.1 )
pkg_online-server-0.9.1 pkg_online-0.9.1 ( pkg_online-server-0.9.1 )
pkg_summary-utils-0.35rc1 distbb-0.33.0 ( pkg_summary-utils>=0.31.0 )
pkg_summary-utils-0.35rc1 pkg_conflicts-0.4.0 ( pkg_summary-utils-[0-9]* )
pkg_summary-utils-0.35rc1 pkg_online-client-0.9.1 ( pkg_summary-utils-[0-9]* )
pkg_summary-utils-0.35rc1 pkg_online-server-0.9.1 ( pkg_summary-utils>=0.18.1 )
runawk-0.18.0 awk-pkgsrc-dewey-0.5.6 ( runawk-[0-9]* )
runawk-0.18.0 distbb-0.33.0 ( runawk>=0.14.3 )
runawk-0.18.0 paexec-0.13.0nb1 ( runawk>=0.16.0 )
runawk-0.18.0 pkg_conflicts-0.4.0 ( runawk>=0.14.3 )
runawk-0.18.0 pkg_summary-utils-0.35rc1 ( runawk>=0.16.0 )
'

pkg_summary2deps -Ap src_summary11.txt | sort |
cmp 'pkg_summary2deps #14' \
'audio/libao audio/libao-oss
audio/libao audio/vorbis-tools
audio/libao-oss audio/vorbis-tools
devel/gmake editors/emacs20
devel/gmake textproc/dict-client
devel/libmaa textproc/dict-client
devel/libtool-base devel/libmaa
devel/libtool-base textproc/dict-client
editors/emacs textproc/dictem:EMACS_TYPE=emacs23
editors/emacs20 textproc/dictem:EMACS_TYPE=emacs20
editors/emacs21 textproc/dictem:EMACS_TYPE=emacs21
editors/emacs22 textproc/dictem
lang/f2c devel/libtool-base
lang/perl5 devel/p5-ExtUtils-CBuilder
sysutils/checkperms devel/gmake
sysutils/checkperms devel/libmaa
sysutils/checkperms devel/libtool-base
sysutils/checkperms devel/p5-ExtUtils-CBuilder
sysutils/checkperms editors/emacs20
sysutils/checkperms lang/f2c
sysutils/checkperms lang/perl5
sysutils/checkperms textproc/dict-client
sysutils/checkperms textproc/dictem
sysutils/checkperms textproc/dictem:EMACS_TYPE=emacs20
sysutils/checkperms textproc/dictem:EMACS_TYPE=emacs21
sysutils/checkperms textproc/dictem:EMACS_TYPE=emacs23
textproc/dict-client textproc/dictem
textproc/dict-client textproc/dictem:EMACS_TYPE=emacs20
textproc/dict-client textproc/dictem:EMACS_TYPE=emacs21
textproc/dict-client textproc/dictem:EMACS_TYPE=emacs23
'

# pkg_lint_summary
pkg_lint_summary bin_summary1.txt 2>&1 | sort |
sed 's/^One of the.*$/MandatoryOptionErrorMessage/' |
cmp 'pkg_lint_summary #1' \
'MandatoryOptionErrorMessage
'

pkg_lint_summary -l bin_summary1.txt | sort |
cmp 'pkg_lint_summary #2' \
'l: not_found /usr/pkg/lib/libmaa.so.2 wip/dict-client dict-client-1.11.2
l: not_found /usr/pkg/lib/libz.so.1 wip/dict-client dict-client-1.11.2
l: not_found /usr/pkg/lib/libz.so.1 wip/dict-server dict-server-1.11.2
'

# pkg_subgraph_deps
pkg_subgraph_deps -f src_pkgs.txt src_deps.txt | sort |
cmp 'pkg_subgraph_deps #1' \
'textproc/dictem
wip/awk-pkgsrc-dewey wip/pkg_summary-utils
wip/libuxre wip/heirloom-awk
wip/paexec wip/distbb
wip/pkg_summary-utils wip/distbb
wip/pkg_summary-utils wip/pkg_online-client
wip/pkg_summary-utils wip/pkg_online-server
wip/runawk wip/awk-pkgsrc-dewey
wip/runawk wip/distbb
wip/runawk wip/paexec
wip/runawk wip/pkg_summary-utils
'

pkg_subgraph_deps -f src_pkgs.txt -r src_deps.txt | sort |
cmp 'pkg_subgraph_deps #2' \
'devel/libtool-base wip/libuxre
lang/f2c devel/libtool-base
textproc/dictem
wip/heirloom-common wip/heirloom-doc
wip/heirloom-doc wip/heirloom-libcommon
wip/heirloom-libcommon wip/libuxre
wip/runawk
'

pkg_subgraph_deps -x -f src_pkgs.txt src_deps.txt | sort |
cmp 'pkg_subgraph_deps #3' \
'wip/awk-pkgsrc-dewey wip/pkg_summary-utils
wip/heirloom-awk
wip/paexec wip/distbb
wip/pkg_summary-utils wip/distbb
wip/pkg_summary-utils wip/pkg_online-client
wip/pkg_summary-utils wip/pkg_online-server
'

pkg_subgraph_deps -rx -fsrc_pkgs.txt src_deps.txt | sort |
cmp 'pkg_subgraph_deps #4' \
'lang/f2c devel/libtool-base
wip/heirloom-common wip/heirloom-doc
wip/heirloom-doc wip/heirloom-libcommon
'

pkg_subgraph_deps -xv -f src_pkgs.txt src_deps.txt | sort |
cmp 'pkg_subgraph_deps #5' \
'devel/gmake textproc/dict-client
devel/gmake textproc/dict-server
devel/libjudy
devel/libmaa textproc/dict-client
devel/libmaa textproc/dict-server
devel/libtool-base devel/libmaa
devel/libtool-base textproc/dict-client
devel/libtool-base textproc/dict-server
devel/libtool-base wip/libuxre
devel/pipestatus
lang/f2c devel/libtool-base
net/netcat
textproc/dictem
wip/heirloom-common wip/heirloom-doc
wip/heirloom-doc wip/heirloom-libcommon
wip/heirloom-libcommon wip/libuxre
wip/runawk
'

pkg_subgraph_deps -xvt -f src_pkgs.txt src_deps.txt | sort |
cmp 'pkg_subgraph_deps #6' \
'devel/gmake textproc/dict-client
devel/gmake textproc/dict-server
devel/libjudy devel/libjudy
devel/libmaa textproc/dict-client
devel/libmaa textproc/dict-server
devel/libtool-base devel/libmaa
devel/libtool-base textproc/dict-client
devel/libtool-base textproc/dict-server
devel/libtool-base wip/libuxre
devel/pipestatus devel/pipestatus
lang/f2c devel/libtool-base
net/netcat net/netcat
textproc/dictem textproc/dictem
wip/heirloom-common wip/heirloom-doc
wip/heirloom-doc wip/heirloom-libcommon
wip/heirloom-libcommon wip/libuxre
wip/runawk wip/runawk
'

pkg_subgraph_deps -xvn -f src_pkgs.txt src_deps.txt | sort |
cmp 'pkg_subgraph_deps #7' \
'devel/gmake
devel/libjudy
devel/libmaa
devel/libtool-base
devel/pipestatus
lang/f2c
net/netcat
textproc/dict-client
textproc/dict-server
textproc/dictem
wip/heirloom-common
wip/heirloom-doc
wip/heirloom-libcommon
wip/libuxre
wip/runawk
'

pkg_subgraph_deps -r -p'wip/pkg_online-client,wip/distbb' src_deps.txt | sort |
cmp 'pkg_subgraph_deps #8' \
''

# pkg_bin_summary
pkg_bin_summary pkg_install |
grep -E 'LICENSE|PKGPATH' |
cmp 'pkg_bin_summary #1' \
'LICENSE=modified-bsd
PKGPATH=pkgtools/pkg_install
'


pkg_bin_summary |
pkg_grep_summary -s PKGBASE bmake |
grep -E 'PKGPATH|LICENSE' |
cmp 'pkg_bin_summary #2' \
'LICENSE=modified-bsd
PKGPATH=devel/bmake
'


pkg_bin_summary -r LICENSE,COMMENT,DESCRIPTION,REQUIRES -- bmake |
grep -E 'PKGPATH|LICENSE' |
cmp 'pkg_bin_summary #3' \
'PKGPATH=devel/bmake
'


pkg_bin_summary -f 'PKGPATH' -- bmake pkg_install |
cmp 'pkg_bin_summary #4' \
'PKGPATH=devel/bmake

PKGPATH=pkgtools/pkg_install

'

test -f "$tmpex"
exit $?
