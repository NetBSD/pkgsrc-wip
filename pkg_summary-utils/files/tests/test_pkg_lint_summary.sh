# pkg_lint_summary
pkg_lint_summary bin_summary1.txt 2>&1 | sort |
sed -n 's/At least one.*$/MandatoryOptionErrorMessage/p' |
cmp 'pkg_lint_summary #1' \
'MandatoryOptionErrorMessage
'

pkg_lint_summary -p /usr/pkg -l bin_summary1.txt | sort |
cmp 'pkg_lint_summary #2' \
'l: not_found /usr/pkg/lib/libmaa.so.2 wip/dict-client dict-client-1.11.2
l: not_found /usr/pkg/lib/libz.so.1 wip/dict-client dict-client-1.11.2
l: not_found /usr/pkg/lib/libz.so.1 wip/dict-server dict-server-1.11.2
'

pkg_lint_summary -p /usr -l bin_summary1.txt | sort |
cmp 'pkg_lint_summary #2.1' \
'l: not_found /usr/lib/libc.so.12 devel/gmake gmake-3.81
l: not_found /usr/lib/libc.so.12 devel/libmaa libmaa-1.1.0
l: not_found /usr/lib/libc.so.12 net/netcat netcat-1.10nb2
l: not_found /usr/lib/libc.so.12 sysutils/checkperms checkperms-1.10
l: not_found /usr/lib/libc.so.12 wip/dict-client dict-client-1.11.2
l: not_found /usr/lib/libc.so.12 wip/dict-server dict-server-1.11.2
l: not_found /usr/lib/libc.so.12 wip/paexec paexec-0.13.0nb1
l: not_found /usr/lib/libc.so.12 wip/runawk runawk-0.18.0
l: not_found /usr/lib/libintl.so.0 devel/gmake gmake-3.81
l: not_found /usr/pkg/lib/libmaa.so.2 wip/dict-client dict-client-1.11.2
l: not_found /usr/pkg/lib/libz.so.1 wip/dict-client dict-client-1.11.2
l: not_found /usr/pkg/lib/libz.so.1 wip/dict-server dict-server-1.11.2
'

pkg_lint_summary -dDu src_summary.txt | sort |
cmp 'pkg_lint_summary -Ap #3' \
'd: not_found libmaa>=1.2 <- wip/dict-server dict-server-1.10.11nb2
d: not_found pkg_summary-utils>=0.19.0 <- wip/pkg_online-server pkg_online-server-0.5.0
u: unicity dict-client <- textproc/dict-client wip/dict-client
'

pkg_lint_summary -dD src_summary2.txt | sort |
cmp 'pkg_lint_summary -Ap #4' \
'd: not_found pkg_online-client-0.5.0nb2 <- wip/pkg_online pkg_online-0.5.0nb2
d: not_found pkg_online-server-0.5.0nb2 <- wip/pkg_online pkg_online-0.5.0nb2
'

pkg_lint_summary -cd src_summary12.txt | sort |
cmp 'pkg_lint_summary -Ap #5' \
'c: conflict awk-pkgsrc-dewey-[0-9]* wip/awk-pkgsrc-dewey awk-pkgsrc-dewey-0.5.6 <- wip/pkg_summary-utils pkg_summary-utils-0.49beta2
c: conflict egcs-current-19980608 somewhere/egcs-current egcs-current-19980608 <- lang/f2c f2c-20090411nb5
c: conflict glibtool-[0-9]* somewhere/glibtool glibtool-1.2.3 <- devel/libtool-base libtool-base-2.2.6bnb4
c: conflict libtool<=1.3.5nb11 somewhere/libtool libtool-1.3.4 <- devel/libtool-base libtool-base-2.2.6bnb4
c: conflict libtool<=1.3.5nb11 somewhere/libtool133 libtool-1.3.3 <- devel/libtool-base libtool-base-2.2.6bnb4
c: conflict paexec<0.15.0 wip/paexec paexec-0.13.0 <- wip/pkg_summary-utils pkg_summary-utils-0.49beta2
c: conflict pkg_cmp_summary-[0-9]* somewhere/pkg_cmp_summary pkg_cmp_summary-0.0.1 <- wip/pkg_summary-utils pkg_summary-utils-0.49beta2
c: conflict pkg_src_update_summary-[0-9]* somewhere/pkg_src_update_summary pkg_src_update_summary-0.0.2 <- wip/pkg_summary-utils pkg_summary-utils-0.49beta2
c: conflict pkg_summary4view-[0-9]* somewhere/pkg_summary4view pkg_summary4view-0.0.4 <- wip/pkg_summary-utils pkg_summary-utils-0.49beta2
c: conflict pkg_update_summary-[0-9]* somewhere/pkg_update_summary pkg_update_summary-0.0.3 <- wip/pkg_summary-utils pkg_summary-utils-0.49beta2
d: not_found paexec>=0.15.0 <- wip/distbb distbb-0.38.2
'

pkg_lint_summary -u src_summary3.txt | sort |
cmp 'pkg_lint_summary -Ap #6' \
'u: unicity distbb <- wip/distbb:OPT1=1,OPT2=2 wip/distbb:OPT1=1,OPT2=2 wip/distbb:OPT=1,OPT2=3
'

pkg_lint_summary -u src_summary7.txt | sort |
cmp 'pkg_lint_summary -Ap #7' \
''

pkg_lint_summary -u src_summary9.txt | sort |
cmp 'pkg_lint_summary -Ap #8' \
'u: unicity emacs <- editors/emacs editors/emacs21 editors/emacs22
'

pkg_lint_summary -d bin_summary4.txt | sort |
cmp 'pkg_lint_summary -d #9' \
'd: not_found p5-Catalyst-Runtime>=5.71001 <- www/p5-Catalyst-Plugin-Session p5-Catalyst-Plugin-Session-0.30nb1
d: not_found perl>=5.10.0|p5-Digest-SHA-[0-9]* <- databases/p5-DBIx-Class-EncodedColumn p5-DBIx-Class-EncodedColumn-0.00010
d: not_found perl>=5.10|p5-Digest-[0-9]* <- www/p5-Catalyst-Plugin-Session p5-Catalyst-Plugin-Session-0.30nb1
d: not_found perl>=5.10|p5-File-Temp-[0-9]* <- www/p5-Catalyst-Plugin-Session p5-Catalyst-Plugin-Session-0.30nb1
d: not_found perl>=5.7.3|p5-Digest-MD5-[0-9]* <- databases/p5-DBIx-Class-EncodedColumn p5-DBIx-Class-EncodedColumn-0.00010
d: not_found perl>=5.7.3|p5-Digest-[0-9]* <- databases/p5-DBIx-Class-EncodedColumn p5-DBIx-Class-EncodedColumn-0.00010
'

pkg_lint_summary -f bin_summary7.txt |
cmp 'pkg_lint_summary -f #10' \
'f: conflict /usr/pkg/lib/libpng15.so wip/aaa aaa-0.9.8qnb1 wip/ccc ccc-2.0.64
'

pkg_lint_summary -n bin_summary8.txt | sort |
cmp 'pkg_lint_summary -n #11' \
'n: conflict /usr/pkg/bin/lzgrep <- archivers/xz xz-5.0.3 archivers/lzip lzip-1.7
n: conflict /usr/pkg/bin/ssh <- security/openssh openssh-5.8.2nb2 security/ssh2 ssh2-3.2.9.1nb7
n: conflict /usr/pkg/libexec/cpp <- lang/pcc pcc-1.0.0 devel/lcc lcc-4.1
'

pkg_lint_summary -n bin_summary7.txt | sort |
cmp 'pkg_lint_summary -n #12' \
'n: conflict /usr/pkg/lib/libpng15.so <- wip/aaa aaa-0.9.8qnb1 wip/ccc ccc-2.0.64
'

pkg_lint_summary -n bin_summary6.txt | sort |
cmp 'pkg_lint_summary -n #13' \
''

pkg_lint_summary -s bin_summary1.txt |
cmp 'pkg_lint_summary -s #14' \
's: mismatch wip/distbb distbb-0.33.0 CheBSD 1.4 i386
s: mismatch wip/pkg_online pkg_online-0.9.1 CheBSD 1.4 i386
s: mismatch wip/pkg_conflicts pkg_conflicts-0.4.0 CheBSD 1.4 i386
s: mismatch sysutils/checkperms checkperms-1.10 CheBSD 1.4 i386
s: mismatch devel/libtool-base libtool-base-1.5.26nb2 CheBSD 1.4 i386
s: mismatch devel/gmake gmake-3.81 CheBSD 1.4 i386
s: mismatch net/netcat netcat-1.10nb2 CheBSD 1.4 i386
s: mismatch wip/awk-pkgsrc-dewey awk-pkgsrc-dewey-0.5.6 CheBSD 1.4 i386
s: mismatch devel/libmaa libmaa-1.1.0 CheBSD 1.4 i386
s: mismatch wip/pkgnih pkgnih-0.3.1 CheBSD 1.4 i386
s: mismatch wip/dict-client dict-client-1.11.2 CheBSD 1.4 i386
s: mismatch wip/dict-server dict-server-1.11.2 CheBSD 1.4 i386
s: mismatch wip/pkg_summary-utils pkg_summary-utils-0.35rc1 CheBSD 1.4 i386
s: mismatch devel/pipestatus pipestatus-0.6.0 CheBSD 1.4 i386
s: mismatch wip/runawk runawk-0.18.0 CheBSD 1.4 i386
s: mismatch wip/paexec paexec-0.13.0nb1 NetBSD 2.0 i386
s: mismatch wip/pkg_online-client pkg_online-client-0.9.1 NetBSD 1.6 nih386
s: mismatch wip/pkg_online-server pkg_online-server-0.9.1 NetBSD 1.5 che386
'
