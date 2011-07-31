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

pkg_uniq_summary -n src_summary.txt | grep -E '^(PKGNAME=|PKGPATH=)|^$' |
cmp 'pkg_uniq_summary #4' \
'PKGNAME=distbb-0.22.0
PKGPATH=wip/distbb

PKGPATH=textproc/dictem
PKGNAME=dictem-0.82

PKGNAME=pkg_online-0.5.0nb2
PKGPATH=wip/pkg_online

PKGNAME=dict-server-1.10.11nb2
PKGPATH=wip/dict-server

PKGNAME=checkperms-1.10
PKGPATH=sysutils/checkperms

PKGNAME=pkg_online-server-0.5.0
PKGPATH=wip/pkg_online-server

PKGNAME=dict-client-1.9.15nb2
PKGPATH=textproc/dict-client

PKGNAME=pkg_online-client-0.5.0
PKGPATH=wip/pkg_online-client

PKGNAME=libmaa-1.0.1nb1
PKGPATH=devel/libmaa

PKGNAME=gmake-3.81
PKGPATH=devel/gmake

PKGNAME=paexec-0.10.0nb1
PKGPATH=wip/paexec

PKGNAME=libtool-base-1.5.24nb6
PKGPATH=devel/libtool-base

PKGNAME=runawk-0.14.3
PKGPATH=wip/runawk

PKGNAME=emacs-22.1nb6
PKGPATH=editors/emacs

PKGNAME=pkg_summary-utils-0.18.1
PKGPATH=wip/pkg_summary-utils

PKGNAME=libungif-4.1.4nb1
PKGPATH=graphics/libungif

PKGNAME=tiff-3.8.2nb4
PKGPATH=graphics/tiff

PKGNAME=x11-links-0.38
PKGPATH=pkgtools/x11-links

PKGNAME=perl-5.8.8nb8
PKGPATH=lang/perl5

PKGNAME=libltdl-1.5.24
PKGPATH=devel/libltdl

PKGNAME=pipestatus-0.4.0
PKGPATH=devel/pipestatus

PKGNAME=awk-pkgsrc-dewey-0.5.6
PKGPATH=wip/awk-pkgsrc-dewey

PKGNAME=png-1.2.32beta01
PKGPATH=graphics/png

PKGNAME=netcat-1.10nb2
PKGPATH=net/netcat

PKGNAME=pkg-config-0.23
PKGPATH=devel/pkg-config

PKGNAME=jpeg-6bnb4
PKGPATH=graphics/jpeg

PKGNAME=ap22-vhost-ldap-1.2.0nb1
PKGPATH=www/ap22-vhost-ldap

PKGNAME=ap2-vhost-ldap-1.2.0nb1
PKGPATH=www/ap2-vhost-ldap:PKG_APACHE=apache2

'

pkg_uniq_summary -n src_summary3.txt |
cmp 'pkg_uniq_summary #5' \
'ASSIGNMENTS=OPT1=1,OPT2=2
PKGNAME=distbb-0.22.0
PKGPATH=wip/distbb

'
