# pkg_digger
export PKG_DIGGER_SUMMARY=`pwd`/src_summary.txt

pkg_digger_backend -931 wip/runawk,runawk |
cmp 'pkg_digger_backend #1' \
'wip/runawk                - Wrapper that impelements modules for AWK
'

pkg_digger_backend -391r wip/runawk,runawk |
cmp 'pkg_digger_backend #1.1' \
'wip/runawk                - Wrapper that impelements modules for AWK
'

pkg_digger_backend -13r wip/runawk,runawk |
cmp 'pkg_digger_backend #2' \
'PKGNAME=runawk-0.14.3
PKGPATH=wip/runawk
HOMEPAGE=http://sourceforge.net/projects/runawk
COMMENT=Wrapper that impelements modules for AWK
MAINTAINER=cheusov@tut.by
CATEGORIES=lang devel

'

pkg_digger_backend -93 wip/runawk,runawk |
cmp 'pkg_digger_backend #2.1' \
'-----------------------------------------------------------
PKGNAME:        runawk-0.14.3
PKGPATH:        wip/runawk
HOMEPAGE:       http://sourceforge.net/projects/runawk
COMMENT:        Wrapper that impelements modules for AWK
MAINTAINER:     cheusov@tut.by
CATEGORIES:     lang devel

'

pkg_digger_backend -19r wip/runawk,runawk |
cmp 'pkg_digger_backend #3' \
'PKGNAME=runawk-0.14.3
PKGPATH=wip/runawk
BUILD_DEPENDS= checkperms>=1.1:../../sysutils/checkperms
HOMEPAGE=http://sourceforge.net/projects/runawk
COMMENT=Wrapper that impelements modules for AWK
MAINTAINER=cheusov@tut.by
CATEGORIES=lang devel
EXTRA_FIELD=lalala

'

pkg_digger_backend -19 wip/runawk,runawk |
cmp 'pkg_digger_backend #3.1' \
'-----------------------------------------------------------
PKGNAME:        runawk-0.14.3
PKGPATH:        wip/runawk
BUILD_DEPENDS:  checkperms>=1.1:../../sysutils/checkperms
HOMEPAGE:       http://sourceforge.net/projects/runawk
COMMENT:        Wrapper that impelements modules for AWK
MAINTAINER:     cheusov@tut.by
CATEGORIES:     lang devel
EXTRA_FIELD:    lalala

'
