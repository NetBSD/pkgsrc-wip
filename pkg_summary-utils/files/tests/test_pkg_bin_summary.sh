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

pkg_bin_summary -fPKGPATH,PLIST -- bmake pkg_install |
awk '!/PLIST/ || /\/(s?bin|man)\/pkg_/ || /bmake/' |
cmp 'pkg_bin_summary #5' \
'PKGPATH=devel/bmake
PLIST=/usr/pkg/bin/bmake
PLIST=/usr/pkg/man/man1/bmake.1

PKGPATH=pkgtools/pkg_install
PLIST=/usr/pkg/sbin/pkg_add
PLIST=/usr/pkg/sbin/pkg_admin
PLIST=/usr/pkg/sbin/pkg_create
PLIST=/usr/pkg/sbin/pkg_delete
PLIST=/usr/pkg/sbin/pkg_info

'
