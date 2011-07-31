# pkg_refresh_summary
pkg_refresh_summary src_summary.txt src_summary2.txt |
sed -n 's/^PKGNAME=//p' | sort |
cmp 'pkg_refresh_summary #1' \
'ap22-vhost-ldap-1.2.0nb1
awk-pkgsrc-dewey-0.5.6
checkperms-1.10
dict-client-1.10.11nb2
dict-client-1.9.15nb2
dict-server-1.11.0
dictem-0.82
digest-99.99.99
distbb-0.22.0
emacs-22.1nb6
gmake-3.81
jpeg-6bnb4
libltdl-1.5.24
libmaa-1.0.1nb1
libtool-base-1.5.24nb6
libungif-4.1.4nb1
netcat-1.10nb2
paexec-0.10.0nb1
perl-5.8.8nb8
pipestatus-0.5.0
pkg-config-0.23
pkg_online-0.5.0nb2
pkg_online-client-0.5.0
pkg_online-server-0.5.0
pkg_summary-utils-0.18.1
png-1.2.32beta01
runawk-0.14.3
tiff-3.8.2nb4
x11-links-0.38
'

pkg_refresh_summary -o src_summary.txt src_summary2.txt |
sed -n 's/^PKGNAME=//p' | sort |
cmp 'pkg_refresh_summary #2' \
'ap2-vhost-ldap-1.2.0nb1
dict-server-1.10.11nb2
pipestatus-0.4.0
runawk-0.13.0
'
