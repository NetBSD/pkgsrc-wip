# pkg_summary2leaves
pkg_summary2leaves -p bin_summary2.txt | sort |
cmp 'pkg_summary2leaves #1' \
'textproc/dict-client
textproc/dict-server
wip/distbb
wip/mk-configure
wip/pkg_status
wip/pkgnih
'

pkg_summary2leaves -pv bin_summary2.txt | sort |
cmp 'pkg_summary2leaves #2' \
'devel/libmaa
devel/pipestatus
pkgtools/digest
wip/paexec
wip/pkg_summary-utils
wip/runawk
'

pkg_summary2leaves -pa bin_summary2.txt | sort |
cmp 'pkg_summary2leaves #3' \
'wip/distbb
wip/mk-configure
wip/pkg_status
'

pkg_summary2leaves -pva bin_summary2.txt | sort |
cmp 'pkg_summary2leaves #4' \
'devel/libmaa
devel/pipestatus
pkgtools/digest
textproc/dict-client
textproc/dict-server
wip/paexec
wip/pkg_summary-utils
wip/pkgnih
wip/runawk
'

pkg_summary2leaves -pr bin_summary2.txt | sort |
cmp 'pkg_summary2leaves #5' \
'pkgtools/digest
wip/distbb
wip/mk-configure
wip/paexec
wip/pkg_status
wip/pkg_summary-utils
wip/runawk
'

pkg_summary2leaves -prv bin_summary2.txt | sort |
cmp 'pkg_summary2leaves #6' \
'devel/libmaa
devel/pipestatus
textproc/dict-client
textproc/dict-server
wip/pkgnih
'

pkg_summary2leaves -a bin_summary2.txt |
cmp 'pkg_summary2leaves #7' \
'PKGPATH=wip/distbb
PKGNAME=distbb-0.38.1
DEPENDS=pkg_summary-utils>=0.43.1
DEPENDS=paexec>=0.15.0
DEPENDS=runawk>=1.1.0
DEPENDS=pipestatus>=0.6.0
DEPENDS=digest-[0-9]*
automatic=yes

PKGPATH=wip/pkg_status
PKGNAME=pkg_status-0.11
DEPENDS=pipestatus-[0-9]*
DEPENDS=pkg_summary-utils>=0.46
automatic=yes

PKGPATH=wip/mk-configure
PKGNAME=mk-configure-0.21.0
automatic=yes

'

pkg_summary2leaves -a 2>&1 |
cmp 'pkg_summary2leaves #8' \
'pkg_summary2leaves requires <files...>
'

pkg_summary2leaves 2>&1 |
cmp 'pkg_summary2leaves #9' \
'pkg_summary2leaves requires <files...>
'

pkg_summary2leaves -a bin_summary11.txt |
cmp 'pkg_summary2leaves #10.1' \
'PKGNAME=py26-gtk2-2.24.0nb4
PKGPATH=x11/py-gtk2
FILE_NAME=py26-gtk2-2.24.0nb4.tgz
force_update=yes
automatic=yes

'

pkg_summary2leaves -ap bin_summary11.txt |
cmp 'pkg_summary2leaves #10.2' \
'x11/py-gtk2
'
