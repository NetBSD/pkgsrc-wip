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
