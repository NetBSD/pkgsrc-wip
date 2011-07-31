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
