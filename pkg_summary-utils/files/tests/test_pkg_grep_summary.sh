# pkg_grep_summary
runtest pkg_grep_summary -f 'COMMENT PKGNAME PKGPATH DEPENDS' -s PKGBASE distbb \
    < src_summary.txt |
cmp 'pkg_grep_summary #1' \
'PKGNAME=distbb-0.22.0
PKGPATH=wip/distbb
DEPENDS=pkg_summary-utils>=0.18.1:../../wip/pkg_summary-utils paexec>=0.10.0:../../wip/paexec runawk>=0.13.0:../../wip/runawk
COMMENT=DISTributed Bulk Build tool for pkgsrc

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

runtest pkg_grep_summary -fPKGNAME -e EXFIELD < src_summary.txt | \
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

runtest pkg_grep_summary -f PKGNAME -t empty EXFIELD '' < src_summary.txt | \
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

runtest pkg_grep_summary -s PKGPATH graphics/png \
    -fPKGNAME,PKGPATH,COMMENT,MAINTAINER < src_summary.txt |
cmp 'pkg_grep_summary #9' \
'PKGNAME=png-1.2.32beta01
PKGPATH=graphics/png
COMMENT=Library for manipulating PNG images
MAINTAINER=wiz@NetBSD.org

'

runtest pkg_grep_summary -s PKGPATHe www/ap22-vhost-ldap:PKG_APACHE=apache22 \
    -f PKGNAME,PKGPATH,COMMENT,MAINTAINER,ASSIGNMENTS < src_summary.txt |
cmp 'pkg_grep_summary #10' \
'PKGNAME=ap22-vhost-ldap-1.2.0nb1
ASSIGNMENTS=PKG_APACHE=apache22
COMMENT=Apache 2.2 module LDAP Virtual Hosts support
MAINTAINER=imil@gcu.info
PKGPATH=www/ap22-vhost-ldap

'

runtest pkg_grep_summary -s PKGPATHe www/ap2-vhost-ldap:PKG_APACHE=apache2 \
    -f'PKGNAME PKGPATH COMMENT MAINTAINER ASSIGNMENTS' < src_summary.txt |
cmp 'pkg_grep_summary #11' \
'PKGNAME=ap2-vhost-ldap-1.2.0nb1
PKGPATH=www/ap2-vhost-ldap:PKG_APACHE=apache2
COMMENT=Apache 2 module LDAP Virtual Hosts support
MAINTAINER=imil@gcu.info

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

runtest pkg_grep_summary -fPKGNAME,PKGPATH,MAINTAINER,COMMENT \
    -v -t re MAINTAINER 'cheusov|vle@gmx[.]net' \
    < src_summary.txt |
cmp 'pkg_grep_summary #49' \
'COMMENT=Check and correct file permissions
MAINTAINER=rillig@NetBSD.org
PKGNAME=checkperms-1.10
PKGPATH=sysutils/checkperms

PKGNAME=dict-client-1.9.15nb2
PKGPATH=textproc/dict-client
COMMENT=Dictionary Service Protocol client
MAINTAINER=pkgsrc-users@NetBSD.org

PKGNAME=gmake-3.81
PKGPATH=devel/gmake
COMMENT=GNU version of '"'"'make'"'"' utility
MAINTAINER=pkgsrc-users@NetBSD.org

PKGNAME=libtool-base-1.5.24nb6
PKGPATH=devel/libtool-base
COMMENT=Generic shared library support script (the script itself)
MAINTAINER=joerg@NetBSD.org

PKGNAME=emacs-22.1nb6
PKGPATH=editors/emacs
COMMENT=GNU editing macros (editor)
MAINTAINER=markd@NetBSD.org

PKGNAME=libungif-4.1.4nb1
PKGPATH=graphics/libungif
COMMENT=Tools and library routines for working with GIF images
MAINTAINER=pkgsrc-users@NetBSD.org

PKGNAME=tiff-3.8.2nb4
PKGPATH=graphics/tiff
COMMENT=Library and tools for reading and writing TIFF data files
MAINTAINER=pkgsrc-users@NetBSD.org

PKGNAME=x11-links-0.38
PKGPATH=pkgtools/x11-links
COMMENT=Shadow tree of links to native X11 headers and libraries
MAINTAINER=pkgsrc-users@NetBSD.org

PKGNAME=perl-5.8.8nb8
PKGPATH=lang/perl5
COMMENT=Practical Extraction and Report Language
MAINTAINER=pkgsrc-users@NetBSD.org

PKGNAME=libltdl-1.5.24
PKGPATH=devel/libltdl
COMMENT=Generic shared library support (libltdl abstraction library)
MAINTAINER=joerg@NetBSD.org

PKGNAME=png-1.2.32beta01
PKGPATH=graphics/png
COMMENT=Library for manipulating PNG images
MAINTAINER=wiz@NetBSD.org

PKGNAME=netcat-1.10nb2
PKGPATH=net/netcat
COMMENT=Read and write data across network connections
MAINTAINER=pkgsrc-users@NetBSD.org

PKGNAME=pkg-config-0.23
PKGPATH=devel/pkg-config
COMMENT=System for managing library compile/link flags
MAINTAINER=pkgsrc-users@NetBSD.org

COMMENT=IJG'"'"'s jpeg compression utilities
PKGNAME=jpeg-6bnb4
PKGPATH=graphics/jpeg
MAINTAINER=pkgsrc-users@NetBSD.org

PKGNAME=ap22-vhost-ldap-1.2.0nb1
COMMENT=Apache 2.2 module LDAP Virtual Hosts support
MAINTAINER=imil@gcu.info
PKGPATH=www/ap22-vhost-ldap

PKGNAME=ap2-vhost-ldap-1.2.0nb1
PKGPATH=www/ap2-vhost-ldap:PKG_APACHE=apache2
COMMENT=Apache 2 module LDAP Virtual Hosts support
MAINTAINER=imil@gcu.info

'

runtest pkg_grep_summary -fPKGNAME,PKGPATH \
    -s PKGPAIR 'wip/dict-server,dict-server' < src_summary.txt |
cmp 'pkg_grep_summary #50' \
'PKGNAME=dict-server-1.10.11nb2
PKGPATH=wip/dict-server

'

runtest pkg_grep_summary -fPKGNAME,PKGPATH \
    -s PKGPABA 'sysutils/checkperms,checkperms' < src_summary.txt |
cmp 'pkg_grep_summary #50.1' \
'PKGNAME=checkperms-1.10
PKGPATH=sysutils/checkperms

'

runtest pkg_grep_summary -fPKGNAME,PKGPATH \
    -s PKGPANA 'wip/dict-server,dict-server-1.10.11nb2' < src_summary.txt |
cmp 'pkg_grep_summary #50.2' \
'PKGNAME=dict-server-1.10.11nb2
PKGPATH=wip/dict-server

'

{
if runtest pkg_grep_summary -r -fPKGNAME,PKGPATH \
    -s PKGPAIR 'foo-bar-baz' < src_summary.txt
then
    echo found
else
    echo not found
fi
} |
cmp 'pkg_grep_summary #51' \
'not found
'

{
if runtest pkg_grep_summary -R -fPKGNAME,PKGPATH \
    -s PKGPAIR 'foo-bar-baz' < src_summary.txt 2>&1
then
    echo found
else
    echo not found
fi
} |
cmp 'pkg_grep_summary #52' \
'No matches found
not found
'

runtest pkg_grep_summary -T |
cmp 'pkg_grep_summary #53' \
'exact prefix suffix substring word first last re strfile strlist awk empty kw
'

runtest pkg_grep_summary -T -T |
cmp 'pkg_grep_summary #54' \
'exact	Match exactly
prefix	Match prefixes
suffix	Match suffixes
substring	Match substring
word	Match separate words
first	Match the first word
last	Match the last word
re	POSIX 1003.2 (modern) regular expressions
strfile	Match the words from file
strlist	Match the specified words
awk	Match using AWK expression
empty	Match an empty string
kw	"keyword" match
'

runtest pkg_grep_summary -i -fPKGNAME,PKGPATH \
    -s PKGPAIR 'WIP/DICT-SERVER,DICT-SERVER' < src_summary.txt |
cmp 'pkg_grep_summary #55' \
'PKGNAME=dict-server-1.10.11nb2
PKGPATH=wip/dict-server

'

runtest pkg_grep_summary -fPKGNAME,PKGPATH \
    -i -t re DEPENDS 'perl.*p5-Digest' < bin_summary4.txt |
cmp 'pkg_grep_summary #56' \
'PKGNAME=p5-Catalyst-Plugin-Session-0.30nb1
PKGPATH=www/p5-Catalyst-Plugin-Session

PKGNAME=p5-DBIx-Class-EncodedColumn-0.00010
PKGPATH=databases/p5-DBIx-Class-EncodedColumn

'

runtest pkg_grep_summary -fPKGNAME,PKGPATH \
    -i -t re PKGPATH '^WIP/' < src_summary.txt |
cmp 'pkg_grep_summary #57' \
'PKGNAME=distbb-0.22.0
PKGPATH=wip/distbb

PKGNAME=pkg_online-0.5.0nb2
PKGPATH=wip/pkg_online

PKGNAME=dict-server-1.10.11nb2
PKGPATH=wip/dict-server

PKGNAME=pkg_online-server-0.5.0
PKGPATH=wip/pkg_online-server

PKGNAME=pkg_online-client-0.5.0
PKGPATH=wip/pkg_online-client

PKGNAME=paexec-0.10.0nb1
PKGPATH=wip/paexec

PKGNAME=runawk-0.14.3
PKGPATH=wip/runawk

PKGNAME=pkg_summary-utils-0.18.1
PKGPATH=wip/pkg_summary-utils

PKGNAME=dict-client-1.10.11nb2
PKGPATH=wip/dict-client

PKGNAME=awk-pkgsrc-dewey-0.5.6
PKGPATH=wip/awk-pkgsrc-dewey

'
