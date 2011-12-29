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

pkg_subgraph_deps -1 -f src_pkgs.txt src_deps.txt | sort |
cmp 'pkg_subgraph_deps #1.1' \
'textproc/dictem
wip/libuxre wip/heirloom-awk
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

pkg_subgraph_deps -1 -f src_pkgs.txt -r src_deps.txt | sort |
cmp 'pkg_subgraph_deps #2.1' \
'devel/libtool-base wip/libuxre
textproc/dictem
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

pkg_subgraph_deps -x1 -f src_pkgs.txt src_deps.txt | sort |
cmp 'pkg_subgraph_deps #3.1' \
'wip/awk-pkgsrc-dewey
wip/distbb
wip/heirloom-awk
wip/paexec
wip/pkg_summary-utils
'

pkg_subgraph_deps -rx -fsrc_pkgs.txt src_deps.txt | sort |
cmp 'pkg_subgraph_deps #4' \
'lang/f2c devel/libtool-base
wip/heirloom-common wip/heirloom-doc
wip/heirloom-doc wip/heirloom-libcommon
'

pkg_subgraph_deps -1rx -fsrc_pkgs.txt src_deps.txt | sort |
cmp 'pkg_subgraph_deps #4.1' \
'devel/libtool-base
wip/heirloom-libcommon
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

pkg_subgraph_deps -1v -f src_pkgs.txt src_deps.txt | sort |
cmp 'pkg_subgraph_deps #5.1' \
'devel/gmake textproc/dict-client
devel/gmake textproc/dict-server
devel/libjudy
devel/libmaa textproc/dict-client
devel/libmaa textproc/dict-server
devel/libmaa wip/paexec
devel/libtool-base devel/libmaa
devel/libtool-base textproc/dict-client
devel/libtool-base textproc/dict-server
devel/libtool-base wip/libuxre
devel/pipestatus wip/distbb
devel/pipestatus wip/pkg_online-client
devel/pipestatus wip/pkg_online-server
devel/pipestatus wip/pkg_summary-utils
lang/f2c devel/libtool-base
net/netcat wip/pkg_online-client
textproc/dict-client wip/pkg_online-client
textproc/dict-server wip/pkg_online-server
wip/awk-pkgsrc-dewey wip/pkg_summary-utils
wip/heirloom-common wip/heirloom-doc
wip/heirloom-doc wip/heirloom-awk
wip/heirloom-doc wip/heirloom-libcommon
wip/heirloom-libcommon wip/heirloom-awk
wip/heirloom-libcommon wip/libuxre
wip/paexec wip/distbb
wip/pkg_summary-utils wip/distbb
wip/pkg_summary-utils wip/pkg_online-client
wip/pkg_summary-utils wip/pkg_online-server
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

pkg_subgraph_deps -r -p'wip/pkg_online-client,wip/distbb' src_deps.txt |
sort |
cmp 'pkg_subgraph_deps #8' \
''

pkg_subgraph_deps -r -p'wip/pkg_online-client wip/distbb' src_deps.txt |
sort |
cmp 'pkg_subgraph_deps #8.1' \
'devel/gmake textproc/dict-client
devel/libmaa textproc/dict-client
devel/libmaa wip/paexec
devel/libtool-base devel/libmaa
devel/libtool-base textproc/dict-client
devel/pipestatus wip/distbb
devel/pipestatus wip/pkg_online-client
devel/pipestatus wip/pkg_summary-utils
lang/f2c devel/libtool-base
net/netcat wip/pkg_online-client
textproc/dict-client wip/pkg_online-client
wip/awk-pkgsrc-dewey wip/pkg_summary-utils
wip/paexec wip/distbb
wip/pkg_summary-utils wip/distbb
wip/pkg_summary-utils wip/pkg_online-client
wip/runawk wip/awk-pkgsrc-dewey
wip/runawk wip/distbb
wip/runawk wip/paexec
wip/runawk wip/pkg_summary-utils
'

pkg_subgraph_deps -r1 -p'wip/pkg_online-client wip/distbb' src_deps.txt |
sort |
cmp 'pkg_subgraph_deps #8.2' \
'devel/pipestatus wip/distbb
devel/pipestatus wip/pkg_online-client
net/netcat wip/pkg_online-client
textproc/dict-client wip/pkg_online-client
wip/paexec wip/distbb
wip/pkg_summary-utils wip/distbb
wip/pkg_summary-utils wip/pkg_online-client
wip/runawk wip/distbb
'

pkg_subgraph_deps -rtxv1 -p'wip/distbb' src_deps.txt 2>&1 |
head -n1 |
cmp 'pkg_subgraph_deps #9' \
'error: assertion failed: pkg_subgraph_deps: -xv1 is not allowed!
'

pkg_subgraph_deps -r -f src_pkgs2.txt src_deps2.txt |
sort |
cmp 'pkg_subgraph_deps #10' \
'BUILD_DEPENDS devel/gmake textproc/dict-server
BUILD_DEPENDS devel/libtool-base devel/libmaa
BUILD_DEPENDS devel/libtool-base textproc/dict-server
BUILD_DEPENDS devel/libtool-base wip/libuxre
BUILD_DEPENDS lang/perl5 textproc/dict-mueller7
BUILD_DEPENDS sysutils/coreutils textproc/dict-mueller7
BUILD_DEPENDS textproc/dict-server textproc/dict-mueller7
BUILD_DEPENDS wip/heirloom-libcommon wip/libuxre
DEPENDS devel/libmaa textproc/dict-server
DEPENDS lang/f2c devel/libtool-base
DEPENDS textproc/dict-server textproc/dict-mueller7
DEPENDS wip/heirloom-common wip/heirloom-doc
DEPENDS wip/heirloom-doc wip/heirloom-libcommon
textproc/dictem
wip/runawk
'
