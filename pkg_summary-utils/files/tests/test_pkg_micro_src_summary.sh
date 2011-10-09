# pkg_micro_src_summary
pkgs="`sed -n 's/^PKGPATH=//p' src_summary.txt`"
pkg_micro_src_summary $pkgs 2>"$tmpfn4" |
tee "$objdir"/summary_micro.txt |
normalize_version |
cmp 'pkg_micro_src_summary #1' \
'PKGNAME=checkperms-X
PKGPATH=sysutils/checkperms

PKGNAME=dict-client-X
PKGPATH=textproc/dict-client

PKGNAME=libmaa-X
PKGPATH=devel/libmaa

PKGNAME=gmake-X
PKGPATH=devel/gmake

PKGNAME=libtool-base-X
PKGPATH=devel/libtool-base

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

PKGNAME=ap22-vhost-ldap-X
PKGPATH=www/ap22-vhost-ldap

'

grep_pss_stderr "$tmpfn4" |
cmp 'pkg_micro_src_summary #1 stderr' \
" ------------------
Bad package wip/distbb, skipped
 ------------------
Bad package wip/pkg_online, skipped
 ------------------
Bad package wip/dict-server, skipped
 ------------------
Bad package wip/pkg_online-server, skipped
 ------------------
Bad package wip/pkg_online-client, skipped
 ------------------
Bad package wip/paexec, skipped
 ------------------
Bad package wip/runawk, skipped
 ------------------
Bad package wip/dict-client, skipped
 ------------------
Bad package wip/awk-pkgsrc-dewey, skipped
 ------------------
Bad package www/ap2-vhost-ldap:PKG_APACHE=apache2, skipped
"

pkg_micro_src_summary -f PKGNAME,PKGPATH,MAINTAINER x11/xxkb |
normalize_version |
cmp 'pkg_micro_src_summary #2' \
'PKGNAME=xxkb-X
PKGPATH=x11/xxkb
MAINTAINER=cheusov@NetBSD.org

'

pkg_micro_src_summary -fPKGNAME,PKGPATH,MAINTAINER x11/xxkb |
normalize_version |
cmp 'pkg_micro_src_summary #3' \
'PKGNAME=xxkb-X
PKGPATH=x11/xxkb
MAINTAINER=cheusov@NetBSD.org

'
