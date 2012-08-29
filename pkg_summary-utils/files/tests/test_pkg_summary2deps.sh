# pkg_summary2deps -Ap
pkg_summary2deps -Apa src_summary.txt | sort |
cmp 'pkg_summary2deps #1' \
'devel/gmake devel/libmaa
devel/gmake editors/emacs
devel/gmake textproc/dict-client
devel/gmake wip/dict-client
devel/gmake wip/dict-server
devel/libltdl textproc/dict-client
devel/libmaa wip/dict-client
devel/libmaa wip/dict-server
devel/libmaa wip/paexec
devel/libtool-base devel/libltdl
devel/libtool-base devel/libmaa
devel/libtool-base devel/pkg-config
devel/libtool-base graphics/jpeg
devel/libtool-base graphics/libungif
devel/libtool-base graphics/png
devel/libtool-base graphics/tiff
devel/libtool-base wip/dict-client
devel/libtool-base wip/dict-server
devel/pipestatus wip/pkg_online-client
devel/pipestatus wip/pkg_online-server
devel/pipestatus wip/pkg_summary-utils
devel/pkg-config editors/emacs
editors/emacs textproc/dictem
graphics/jpeg editors/emacs
graphics/jpeg graphics/tiff
graphics/libungif editors/emacs
graphics/png editors/emacs
graphics/tiff editors/emacs
lang/perl5 editors/emacs
lang/perl5 graphics/libungif
net/netcat wip/pkg_online-client
pkgtools/x11-links editors/emacs
sysutils/checkperms devel/gmake
sysutils/checkperms devel/libltdl
sysutils/checkperms devel/libmaa
sysutils/checkperms devel/libtool-base
sysutils/checkperms devel/pipestatus
sysutils/checkperms devel/pkg-config
sysutils/checkperms editors/emacs
sysutils/checkperms graphics/jpeg
sysutils/checkperms graphics/libungif
sysutils/checkperms graphics/png
sysutils/checkperms graphics/tiff
sysutils/checkperms lang/perl5
sysutils/checkperms net/netcat
sysutils/checkperms pkgtools/x11-links
sysutils/checkperms textproc/dict-client
sysutils/checkperms textproc/dictem
sysutils/checkperms wip/awk-pkgsrc-dewey
sysutils/checkperms wip/dict-client
sysutils/checkperms wip/dict-server
sysutils/checkperms wip/distbb
sysutils/checkperms wip/paexec
sysutils/checkperms wip/pkg_online
sysutils/checkperms wip/pkg_online-client
sysutils/checkperms wip/pkg_online-server
sysutils/checkperms wip/pkg_summary-utils
sysutils/checkperms wip/runawk
textproc/dict-client|wip/dict-client textproc/dictem
textproc/dict-client|wip/dict-client wip/pkg_online-client
wip/awk-pkgsrc-dewey wip/pkg_summary-utils
wip/dict-server wip/pkg_online-server
wip/paexec wip/distbb
wip/pkg_online-client wip/pkg_online
wip/pkg_online-server wip/pkg_online
wip/pkg_summary-utils wip/distbb
wip/pkg_summary-utils wip/pkg_online-client
wip/pkg_summary-utils wip/pkg_online-server
wip/runawk wip/awk-pkgsrc-dewey
wip/runawk wip/distbb
wip/runawk wip/pkg_summary-utils
www/ap2-vhost-ldap:PKG_APACHE=apache2
www/ap22-vhost-ldap:PKG_APACHE=apache22
'

# pkg_summary2deps -Ap
pkg_summary2deps -Apa -2 src_summary.txt | sort |
cmp 'pkg_summary2deps #1.1' \
'BUILD_DEPENDS devel/gmake devel/libmaa
BUILD_DEPENDS devel/gmake editors/emacs
BUILD_DEPENDS devel/gmake textproc/dict-client
BUILD_DEPENDS devel/gmake wip/dict-client
BUILD_DEPENDS devel/gmake wip/dict-server
BUILD_DEPENDS devel/libtool-base devel/libltdl
BUILD_DEPENDS devel/libtool-base devel/libmaa
BUILD_DEPENDS devel/libtool-base devel/pkg-config
BUILD_DEPENDS devel/libtool-base graphics/jpeg
BUILD_DEPENDS devel/libtool-base graphics/libungif
BUILD_DEPENDS devel/libtool-base graphics/png
BUILD_DEPENDS devel/libtool-base graphics/tiff
BUILD_DEPENDS devel/libtool-base wip/dict-client
BUILD_DEPENDS devel/libtool-base wip/dict-server
BUILD_DEPENDS devel/pkg-config editors/emacs
BUILD_DEPENDS pkgtools/x11-links editors/emacs
BUILD_DEPENDS sysutils/checkperms devel/gmake
BUILD_DEPENDS sysutils/checkperms devel/libltdl
BUILD_DEPENDS sysutils/checkperms devel/libmaa
BUILD_DEPENDS sysutils/checkperms devel/libtool-base
BUILD_DEPENDS sysutils/checkperms devel/pipestatus
BUILD_DEPENDS sysutils/checkperms devel/pkg-config
BUILD_DEPENDS sysutils/checkperms editors/emacs
BUILD_DEPENDS sysutils/checkperms graphics/jpeg
BUILD_DEPENDS sysutils/checkperms graphics/libungif
BUILD_DEPENDS sysutils/checkperms graphics/png
BUILD_DEPENDS sysutils/checkperms graphics/tiff
BUILD_DEPENDS sysutils/checkperms lang/perl5
BUILD_DEPENDS sysutils/checkperms net/netcat
BUILD_DEPENDS sysutils/checkperms pkgtools/x11-links
BUILD_DEPENDS sysutils/checkperms textproc/dict-client
BUILD_DEPENDS sysutils/checkperms textproc/dictem
BUILD_DEPENDS sysutils/checkperms wip/awk-pkgsrc-dewey
BUILD_DEPENDS sysutils/checkperms wip/dict-client
BUILD_DEPENDS sysutils/checkperms wip/dict-server
BUILD_DEPENDS sysutils/checkperms wip/distbb
BUILD_DEPENDS sysutils/checkperms wip/paexec
BUILD_DEPENDS sysutils/checkperms wip/pkg_online
BUILD_DEPENDS sysutils/checkperms wip/pkg_online-client
BUILD_DEPENDS sysutils/checkperms wip/pkg_online-server
BUILD_DEPENDS sysutils/checkperms wip/pkg_summary-utils
BUILD_DEPENDS sysutils/checkperms wip/runawk
DEPENDS devel/libltdl textproc/dict-client
DEPENDS devel/libmaa wip/dict-client
DEPENDS devel/libmaa wip/dict-server
DEPENDS devel/libmaa wip/paexec
DEPENDS devel/pipestatus wip/pkg_online-client
DEPENDS devel/pipestatus wip/pkg_online-server
DEPENDS devel/pipestatus wip/pkg_summary-utils
DEPENDS editors/emacs textproc/dictem
DEPENDS graphics/jpeg editors/emacs
DEPENDS graphics/jpeg graphics/tiff
DEPENDS graphics/libungif editors/emacs
DEPENDS graphics/png editors/emacs
DEPENDS graphics/tiff editors/emacs
DEPENDS lang/perl5 editors/emacs
DEPENDS lang/perl5 graphics/libungif
DEPENDS net/netcat wip/pkg_online-client
DEPENDS textproc/dict-client|wip/dict-client textproc/dictem
DEPENDS textproc/dict-client|wip/dict-client wip/pkg_online-client
DEPENDS wip/awk-pkgsrc-dewey wip/pkg_summary-utils
DEPENDS wip/dict-server wip/pkg_online-server
DEPENDS wip/paexec wip/distbb
DEPENDS wip/pkg_online-client wip/pkg_online
DEPENDS wip/pkg_online-server wip/pkg_online
DEPENDS wip/pkg_summary-utils wip/distbb
DEPENDS wip/pkg_summary-utils wip/pkg_online-client
DEPENDS wip/pkg_summary-utils wip/pkg_online-server
DEPENDS wip/runawk wip/awk-pkgsrc-dewey
DEPENDS wip/runawk wip/distbb
DEPENDS wip/runawk wip/pkg_summary-utils
www/ap2-vhost-ldap:PKG_APACHE=apache2
www/ap22-vhost-ldap:PKG_APACHE=apache22
'

pkg_summary2deps -Ap -s src_summary.txt 2>&1 >/dev/null | sort |
cmp 'pkg_summary2deps #2' \
'Cannot find dependency libmaa>=1.2 for package wip/dict-server (dict-server-1.10.11nb2)
Cannot find dependency pkg_summary-utils>=0.19.0 for package wip/pkg_online-server (pkg_online-server-0.5.0)
'

pkg_summary2deps -Ap src_summary2.txt | sort |
cmp 'pkg_summary2deps #3' \
'devel/gmake
devel/libltdl
devel/libmaa wip/dict-client
devel/libtool-base
devel/pipestatus
devel/pkg-config
editors/emacs
graphics/jpeg
graphics/libungif
graphics/png
graphics/tiff
lang/perl5
pkgtools/digest
sysutils/checkperms
textproc/dict-client
textproc/dictem
wip/awk-pkgsrc-dewey
wip/dict-client wip/pkg_online-client
wip/dict-server
wip/distbb
wip/paexec
wip/pkg_online-client wip/pkg_online
wip/pkg_online-server wip/pkg_online
wip/pkg_summary-utils
wip/runawk
'

pkg_summary2deps -Ap -2 src_summary2.txt | sort |
cmp 'pkg_summary2deps #3.1' \
'BUILD_DEPENDS devel/libmaa wip/dict-client
DEPENDS wip/dict-client wip/pkg_online-client
DEPENDS wip/pkg_online-client wip/pkg_online
DEPENDS wip/pkg_online-server wip/pkg_online
devel/gmake
devel/libltdl
devel/libtool-base
devel/pipestatus
devel/pkg-config
editors/emacs
graphics/jpeg
graphics/libungif
graphics/png
graphics/tiff
lang/perl5
pkgtools/digest
sysutils/checkperms
textproc/dict-client
textproc/dictem
wip/awk-pkgsrc-dewey
wip/dict-server
wip/distbb
wip/paexec
wip/pkg_summary-utils
wip/runawk
'

pkg_summary2deps -Ap -s src_summary2.txt 2>&1 >/dev/null | sort |
cmp 'pkg_summary2deps #4' \
'Cannot find dependency pkg_online-client-0.5.0nb2 for package wip/pkg_online (pkg_online-0.5.0nb2)
Cannot find dependency pkg_online-server-0.5.0nb2 for package wip/pkg_online (pkg_online-0.5.0nb2)
'

pkg_summary2deps -Ap src_summary7.txt | sort |
cmp 'pkg_summary2deps #5' \
'audio/py-mutagen audio/py-karaoke
audio/py-mutagen:PYTHON_VERSION_REQD=24 audio/py-karaoke:PYTHON_VERSION_REQD=24
audio/py-mutagen:PYTHON_VERSION_REQD=26 audio/py-karaoke:PYTHON_VERSION_REQD=26
'

pkg_summary2deps -Ap src_summary8.txt | sort | uniq |
cmp 'pkg_summary2deps #6' \
'archivers/p5-Archive-Tar devel/p5-Module-Build
devel/p5-Algorithm-Diff textproc/p5-Text-Diff
devel/p5-Compress-Raw-Bzip2 devel/p5-IO-Compress
devel/p5-Compress-Raw-Zlib devel/p5-IO-Compress
devel/p5-ExtUtils-CBuilder devel/p5-Module-Build
devel/p5-ExtUtils-ParseXS devel/p5-Module-Build
devel/p5-IO-Compress archivers/p5-Archive-Tar
devel/p5-IO-Compress devel/p5-IO-Zlib
devel/p5-IO-String archivers/p5-Archive-Tar
devel/p5-IO-Zlib archivers/p5-Archive-Tar
devel/p5-version devel/p5-Module-Build
lang/perl5 archivers/p5-Archive-Tar
lang/perl5 devel/p5-Algorithm-Diff
lang/perl5 devel/p5-Compress-Raw-Bzip2
lang/perl5 devel/p5-Compress-Raw-Zlib
lang/perl5 devel/p5-ExtUtils-CBuilder
lang/perl5 devel/p5-ExtUtils-ParseXS
lang/perl5 devel/p5-IO-Compress
lang/perl5 devel/p5-IO-String
lang/perl5 devel/p5-IO-Zlib
lang/perl5 devel/p5-Module-Build
lang/perl5 devel/p5-version
lang/perl5 textproc/p5-Filter
lang/perl5 textproc/p5-Pod-Readme
lang/perl5 textproc/p5-Regexp-Common
lang/perl5 textproc/p5-Text-Diff
lang/perl5 textproc/p5-YAML
sysutils/checkperms archivers/p5-Archive-Tar
sysutils/checkperms devel/p5-Algorithm-Diff
sysutils/checkperms devel/p5-Compress-Raw-Bzip2
sysutils/checkperms devel/p5-Compress-Raw-Zlib
sysutils/checkperms devel/p5-ExtUtils-CBuilder
sysutils/checkperms devel/p5-ExtUtils-ParseXS
sysutils/checkperms devel/p5-IO-Compress
sysutils/checkperms devel/p5-IO-String
sysutils/checkperms devel/p5-IO-Zlib
sysutils/checkperms devel/p5-Module-Build
sysutils/checkperms devel/p5-version
sysutils/checkperms lang/perl5
sysutils/checkperms textproc/p5-Filter
sysutils/checkperms textproc/p5-Pod-Readme
sysutils/checkperms textproc/p5-Regexp-Common
sysutils/checkperms textproc/p5-Text-Diff
sysutils/checkperms textproc/p5-YAML
textproc/p5-Filter textproc/p5-YAML
textproc/p5-Pod-Readme devel/p5-Module-Build
textproc/p5-Regexp-Common textproc/p5-Pod-Readme
textproc/p5-Text-Diff archivers/p5-Archive-Tar
textproc/p5-YAML devel/p5-Module-Build
'

pkg_summary2deps -2Ap src_summary8.txt | sort | uniq |
cmp 'pkg_summary2deps #6.1' \
'BUILD_DEPENDS lang/perl5 devel/p5-ExtUtils-CBuilder
BUILD_DEPENDS lang/perl5 devel/p5-ExtUtils-ParseXS
BUILD_DEPENDS lang/perl5 devel/p5-Module-Build
BUILD_DEPENDS lang/perl5 devel/p5-version
BUILD_DEPENDS sysutils/checkperms archivers/p5-Archive-Tar
BUILD_DEPENDS sysutils/checkperms devel/p5-Algorithm-Diff
BUILD_DEPENDS sysutils/checkperms devel/p5-Compress-Raw-Bzip2
BUILD_DEPENDS sysutils/checkperms devel/p5-Compress-Raw-Zlib
BUILD_DEPENDS sysutils/checkperms devel/p5-ExtUtils-CBuilder
BUILD_DEPENDS sysutils/checkperms devel/p5-ExtUtils-ParseXS
BUILD_DEPENDS sysutils/checkperms devel/p5-IO-Compress
BUILD_DEPENDS sysutils/checkperms devel/p5-IO-String
BUILD_DEPENDS sysutils/checkperms devel/p5-IO-Zlib
BUILD_DEPENDS sysutils/checkperms devel/p5-Module-Build
BUILD_DEPENDS sysutils/checkperms devel/p5-version
BUILD_DEPENDS sysutils/checkperms lang/perl5
BUILD_DEPENDS sysutils/checkperms textproc/p5-Filter
BUILD_DEPENDS sysutils/checkperms textproc/p5-Pod-Readme
BUILD_DEPENDS sysutils/checkperms textproc/p5-Regexp-Common
BUILD_DEPENDS sysutils/checkperms textproc/p5-Text-Diff
BUILD_DEPENDS sysutils/checkperms textproc/p5-YAML
BUILD_DEPENDS textproc/p5-YAML devel/p5-Module-Build
DEPENDS archivers/p5-Archive-Tar devel/p5-Module-Build
DEPENDS devel/p5-Algorithm-Diff textproc/p5-Text-Diff
DEPENDS devel/p5-Compress-Raw-Bzip2 devel/p5-IO-Compress
DEPENDS devel/p5-Compress-Raw-Zlib devel/p5-IO-Compress
DEPENDS devel/p5-ExtUtils-CBuilder devel/p5-Module-Build
DEPENDS devel/p5-ExtUtils-ParseXS devel/p5-Module-Build
DEPENDS devel/p5-IO-Compress archivers/p5-Archive-Tar
DEPENDS devel/p5-IO-Compress devel/p5-IO-Zlib
DEPENDS devel/p5-IO-String archivers/p5-Archive-Tar
DEPENDS devel/p5-IO-Zlib archivers/p5-Archive-Tar
DEPENDS devel/p5-version devel/p5-Module-Build
DEPENDS lang/perl5 archivers/p5-Archive-Tar
DEPENDS lang/perl5 devel/p5-Algorithm-Diff
DEPENDS lang/perl5 devel/p5-Compress-Raw-Bzip2
DEPENDS lang/perl5 devel/p5-Compress-Raw-Zlib
DEPENDS lang/perl5 devel/p5-ExtUtils-CBuilder
DEPENDS lang/perl5 devel/p5-ExtUtils-ParseXS
DEPENDS lang/perl5 devel/p5-IO-Compress
DEPENDS lang/perl5 devel/p5-IO-String
DEPENDS lang/perl5 devel/p5-IO-Zlib
DEPENDS lang/perl5 devel/p5-Module-Build
DEPENDS lang/perl5 devel/p5-version
DEPENDS lang/perl5 textproc/p5-Filter
DEPENDS lang/perl5 textproc/p5-Pod-Readme
DEPENDS lang/perl5 textproc/p5-Regexp-Common
DEPENDS lang/perl5 textproc/p5-Text-Diff
DEPENDS lang/perl5 textproc/p5-YAML
DEPENDS textproc/p5-Filter textproc/p5-YAML
DEPENDS textproc/p5-Pod-Readme devel/p5-Module-Build
DEPENDS textproc/p5-Regexp-Common textproc/p5-Pod-Readme
DEPENDS textproc/p5-Text-Diff archivers/p5-Archive-Tar
'


#test -f "$tmpex"
#exit $?

# pkg_summary2deps
pkg_summary2deps -Apna src_summary.txt | sort |
cmp 'pkg_summary2deps #7' \
'devel/gmake;gmake devel/libmaa;libmaa
devel/gmake;gmake editors/emacs;emacs
devel/gmake;gmake textproc/dict-client;dict-client
devel/gmake;gmake wip/dict-client;dict-client
devel/gmake;gmake wip/dict-server;dict-server
devel/libltdl;libltdl textproc/dict-client;dict-client
devel/libmaa;libmaa wip/dict-client;dict-client
devel/libmaa;libmaa wip/dict-server;dict-server
devel/libmaa;libmaa wip/paexec;paexec
devel/libtool-base;libtool-base devel/libltdl;libltdl
devel/libtool-base;libtool-base devel/libmaa;libmaa
devel/libtool-base;libtool-base devel/pkg-config;pkg-config
devel/libtool-base;libtool-base graphics/jpeg;jpeg
devel/libtool-base;libtool-base graphics/libungif;libungif
devel/libtool-base;libtool-base graphics/png;png
devel/libtool-base;libtool-base graphics/tiff;tiff
devel/libtool-base;libtool-base wip/dict-client;dict-client
devel/libtool-base;libtool-base wip/dict-server;dict-server
devel/pipestatus;pipestatus wip/pkg_online-client;pkg_online-client
devel/pipestatus;pipestatus wip/pkg_online-server;pkg_online-server
devel/pipestatus;pipestatus wip/pkg_summary-utils;pkg_summary-utils
devel/pkg-config;pkg-config editors/emacs;emacs
editors/emacs;emacs textproc/dictem;dictem
graphics/jpeg;jpeg editors/emacs;emacs
graphics/jpeg;jpeg graphics/tiff;tiff
graphics/libungif;libungif editors/emacs;emacs
graphics/png;png editors/emacs;emacs
graphics/tiff;tiff editors/emacs;emacs
lang/perl5;perl editors/emacs;emacs
lang/perl5;perl graphics/libungif;libungif
net/netcat;netcat wip/pkg_online-client;pkg_online-client
pkgtools/x11-links;x11-links editors/emacs;emacs
sysutils/checkperms;checkperms devel/gmake;gmake
sysutils/checkperms;checkperms devel/libltdl;libltdl
sysutils/checkperms;checkperms devel/libmaa;libmaa
sysutils/checkperms;checkperms devel/libtool-base;libtool-base
sysutils/checkperms;checkperms devel/pipestatus;pipestatus
sysutils/checkperms;checkperms devel/pkg-config;pkg-config
sysutils/checkperms;checkperms editors/emacs;emacs
sysutils/checkperms;checkperms graphics/jpeg;jpeg
sysutils/checkperms;checkperms graphics/libungif;libungif
sysutils/checkperms;checkperms graphics/png;png
sysutils/checkperms;checkperms graphics/tiff;tiff
sysutils/checkperms;checkperms lang/perl5;perl
sysutils/checkperms;checkperms net/netcat;netcat
sysutils/checkperms;checkperms pkgtools/x11-links;x11-links
sysutils/checkperms;checkperms textproc/dict-client;dict-client
sysutils/checkperms;checkperms textproc/dictem;dictem
sysutils/checkperms;checkperms wip/awk-pkgsrc-dewey;awk-pkgsrc-dewey
sysutils/checkperms;checkperms wip/dict-client;dict-client
sysutils/checkperms;checkperms wip/dict-server;dict-server
sysutils/checkperms;checkperms wip/distbb;distbb
sysutils/checkperms;checkperms wip/paexec;paexec
sysutils/checkperms;checkperms wip/pkg_online-client;pkg_online-client
sysutils/checkperms;checkperms wip/pkg_online-server;pkg_online-server
sysutils/checkperms;checkperms wip/pkg_online;pkg_online
sysutils/checkperms;checkperms wip/pkg_summary-utils;pkg_summary-utils
sysutils/checkperms;checkperms wip/runawk;runawk
textproc/dict-client;dict-client|wip/dict-client;dict-client textproc/dictem;dictem
textproc/dict-client;dict-client|wip/dict-client;dict-client wip/pkg_online-client;pkg_online-client
wip/awk-pkgsrc-dewey;awk-pkgsrc-dewey wip/pkg_summary-utils;pkg_summary-utils
wip/dict-server;dict-server wip/pkg_online-server;pkg_online-server
wip/paexec;paexec wip/distbb;distbb
wip/pkg_online-client;pkg_online-client wip/pkg_online;pkg_online
wip/pkg_online-server;pkg_online-server wip/pkg_online;pkg_online
wip/pkg_summary-utils;pkg_summary-utils wip/distbb;distbb
wip/pkg_summary-utils;pkg_summary-utils wip/pkg_online-client;pkg_online-client
wip/pkg_summary-utils;pkg_summary-utils wip/pkg_online-server;pkg_online-server
wip/runawk;runawk wip/awk-pkgsrc-dewey;awk-pkgsrc-dewey
wip/runawk;runawk wip/distbb;distbb
wip/runawk;runawk wip/pkg_summary-utils;pkg_summary-utils
www/ap2-vhost-ldap:PKG_APACHE=apache2;ap2-vhost-ldap
www/ap22-vhost-ldap:PKG_APACHE=apache22;ap22-vhost-ldap
'

pkg_summary2deps -dnta src_summary.txt | sort |
cmp 'pkg_summary2deps #8' \
'ap2-vhost-ldap ap2-vhost-ldap
ap22-vhost-ldap ap22-vhost-ldap
awk-pkgsrc-dewey pkg_summary-utils
checkperms checkperms
dict-client|dict-client dictem
dict-client|dict-client pkg_online-client
dict-server pkg_online-server
emacs dictem
gmake gmake
jpeg emacs
jpeg tiff
libltdl dict-client
libmaa dict-client
libmaa dict-server
libmaa paexec
libtool-base libtool-base
libungif emacs
netcat pkg_online-client
paexec distbb
perl emacs
perl libungif
pipestatus pkg_online-client
pipestatus pkg_online-server
pipestatus pkg_summary-utils
pkg-config pkg-config
pkg_online-client pkg_online
pkg_online-server pkg_online
pkg_summary-utils distbb
pkg_summary-utils pkg_online-client
pkg_summary-utils pkg_online-server
png emacs
runawk awk-pkgsrc-dewey
runawk distbb
runawk pkg_summary-utils
tiff emacs
x11-links x11-links
'

pkg_summary2deps -Apntr src_summary7.txt | sort |
cmp 'pkg_summary2deps #9' \
'audio/py-mutagen:PYTHON_VERSION_REQD=24;py24-mutagen-1.15 audio/py-karaoke:PYTHON_VERSION_REQD=24;py24-karaoke-0.7.1
audio/py-mutagen:PYTHON_VERSION_REQD=26;py26-mutagen-1.15 audio/py-karaoke:PYTHON_VERSION_REQD=26;py26-karaoke-0.7.1
audio/py-mutagen;py25-mutagen-1.15 audio/py-karaoke;py25-karaoke-0.7.1
'

pkg_summary2deps -Dp src_summary8.txt | sort | uniq |
cmp 'pkg_summary2deps #10' \
'lang/perl5 devel/p5-ExtUtils-CBuilder
lang/perl5 devel/p5-ExtUtils-ParseXS
lang/perl5 devel/p5-Module-Build
lang/perl5 devel/p5-version
sysutils/checkperms archivers/p5-Archive-Tar
sysutils/checkperms devel/p5-Algorithm-Diff
sysutils/checkperms devel/p5-Compress-Raw-Bzip2
sysutils/checkperms devel/p5-Compress-Raw-Zlib
sysutils/checkperms devel/p5-ExtUtils-CBuilder
sysutils/checkperms devel/p5-ExtUtils-ParseXS
sysutils/checkperms devel/p5-IO-Compress
sysutils/checkperms devel/p5-IO-String
sysutils/checkperms devel/p5-IO-Zlib
sysutils/checkperms devel/p5-Module-Build
sysutils/checkperms devel/p5-version
sysutils/checkperms lang/perl5
sysutils/checkperms textproc/p5-Filter
sysutils/checkperms textproc/p5-Pod-Readme
sysutils/checkperms textproc/p5-Regexp-Common
sysutils/checkperms textproc/p5-Text-Diff
sysutils/checkperms textproc/p5-YAML
textproc/p5-YAML devel/p5-Module-Build
'

pkg_summary2deps -Dpr src_summary8.txt | sort | uniq |
cmp 'pkg_summary2deps #11' \
'lang/perl5;perl-5.10.0nb7 devel/p5-ExtUtils-CBuilder;p5-ExtUtils-CBuilder-0.26.03.01
lang/perl5;perl-5.10.0nb7 devel/p5-ExtUtils-ParseXS;p5-ExtUtils-ParseXS-2.20.04.01
lang/perl5;perl-5.10.0nb7 devel/p5-Module-Build;p5-Module-Build-0.35000
lang/perl5;perl-5.10.0nb7 devel/p5-version;p5-version-0.7702
sysutils/checkperms;checkperms-1.10 archivers/p5-Archive-Tar;p5-Archive-Tar-1.54
sysutils/checkperms;checkperms-1.10 devel/p5-Algorithm-Diff;p5-Algorithm-Diff-1.1902nb1
sysutils/checkperms;checkperms-1.10 devel/p5-Compress-Raw-Bzip2;p5-Compress-Raw-Bzip2-2.021
sysutils/checkperms;checkperms-1.10 devel/p5-Compress-Raw-Zlib;p5-Compress-Raw-Zlib-2.021
sysutils/checkperms;checkperms-1.10 devel/p5-ExtUtils-CBuilder;p5-ExtUtils-CBuilder-0.26.03.01
sysutils/checkperms;checkperms-1.10 devel/p5-ExtUtils-ParseXS;p5-ExtUtils-ParseXS-2.20.04.01
sysutils/checkperms;checkperms-1.10 devel/p5-IO-Compress;p5-IO-Compress-2.021
sysutils/checkperms;checkperms-1.10 devel/p5-IO-String;p5-IO-String-1.08nb1
sysutils/checkperms;checkperms-1.10 devel/p5-IO-Zlib;p5-IO-Zlib-1.10
sysutils/checkperms;checkperms-1.10 devel/p5-Module-Build;p5-Module-Build-0.35000
sysutils/checkperms;checkperms-1.10 devel/p5-version;p5-version-0.7702
sysutils/checkperms;checkperms-1.10 lang/perl5;perl-5.10.0nb7
sysutils/checkperms;checkperms-1.10 textproc/p5-Filter;p5-Filter-1.37
sysutils/checkperms;checkperms-1.10 textproc/p5-Pod-Readme;p5-Pod-Readme-0.09
sysutils/checkperms;checkperms-1.10 textproc/p5-Regexp-Common;p5-Regexp-Common-2.122nb1
sysutils/checkperms;checkperms-1.10 textproc/p5-Text-Diff;p5-Text-Diff-1.37
sysutils/checkperms;checkperms-1.10 textproc/p5-YAML;p5-YAML-0.70
textproc/p5-YAML;p5-YAML-0.70 devel/p5-Module-Build;p5-Module-Build-0.35000
'

pkg_summary2deps -ApnRa src_summary.txt | sort |
cmp 'pkg_summary2deps #12' \
'devel/gmake;gmake devel/libmaa;libmaa ( gmake>=3.81 )
devel/gmake;gmake editors/emacs;emacs ( gmake>=3.81 )
devel/gmake;gmake textproc/dict-client;dict-client ( gmake>=3.81 )
devel/gmake;gmake wip/dict-client;dict-client ( gmake>=3.81 )
devel/gmake;gmake wip/dict-server;dict-server ( gmake>=3.81 )
devel/libltdl;libltdl textproc/dict-client;dict-client ( libltdl>=1.5.10 )
devel/libmaa;libmaa wip/dict-client;dict-client ( libmaa>=1.0 )
devel/libmaa;libmaa wip/dict-server;dict-server ( libmaa>=1.2 )
devel/libmaa;libmaa wip/paexec;paexec ( libmaa>=0.990 )
devel/libtool-base;libtool-base devel/libltdl;libltdl ( libtool-base>=1.5.18nb5 )
devel/libtool-base;libtool-base devel/libmaa;libmaa ( libtool-base>=1.5.18nb5 )
devel/libtool-base;libtool-base devel/pkg-config;pkg-config ( libtool-base>=1.5.18nb5 )
devel/libtool-base;libtool-base graphics/jpeg;jpeg ( libtool-base>=1.5.18nb5 )
devel/libtool-base;libtool-base graphics/libungif;libungif ( libtool-base>=1.5.18nb5 )
devel/libtool-base;libtool-base graphics/png;png ( libtool-base>=1.5.18nb5 )
devel/libtool-base;libtool-base graphics/tiff;tiff ( libtool-base>=1.5.18nb5 )
devel/libtool-base;libtool-base wip/dict-client;dict-client ( libtool-base>=1.5.18nb5 )
devel/libtool-base;libtool-base wip/dict-server;dict-server ( libtool-base>=1.5.18nb5 )
devel/pipestatus;pipestatus wip/pkg_online-client;pkg_online-client ( pipestatus-[0-9]* )
devel/pipestatus;pipestatus wip/pkg_online-server;pkg_online-server ( pipestatus-[0-9]* )
devel/pipestatus;pipestatus wip/pkg_summary-utils;pkg_summary-utils ( pipestatus-[0-9]* )
devel/pkg-config;pkg-config editors/emacs;emacs ( pkg-config>=0.19 )
editors/emacs;emacs textproc/dictem;dictem ( emacs>=22 )
graphics/jpeg;jpeg editors/emacs;emacs ( jpeg>=6bnb2 )
graphics/jpeg;jpeg graphics/tiff;tiff ( jpeg>=6bnb2 )
graphics/libungif;libungif editors/emacs;emacs ( libungif>=4.1.3nb1 )
graphics/png;png editors/emacs;emacs ( png>=1.2.9nb2 )
graphics/tiff;tiff editors/emacs;emacs ( tiff>=3.7.2nb1 )
lang/perl5;perl editors/emacs;emacs ( perl>=5.0 )
lang/perl5;perl graphics/libungif;libungif ( perl>=5.0 )
net/netcat;netcat wip/pkg_online-client;pkg_online-client ( netcat-[0-9]* )
pkgtools/x11-links;x11-links editors/emacs;emacs ( x11-links>=0.38 )
sysutils/checkperms;checkperms devel/gmake;gmake ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/libltdl;libltdl ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/libmaa;libmaa ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/libtool-base;libtool-base ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/pipestatus;pipestatus ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/pkg-config;pkg-config ( checkperms>=1.1 )
sysutils/checkperms;checkperms editors/emacs;emacs ( checkperms>=1.1 )
sysutils/checkperms;checkperms graphics/jpeg;jpeg ( checkperms>=1.1 )
sysutils/checkperms;checkperms graphics/libungif;libungif ( checkperms>=1.1 )
sysutils/checkperms;checkperms graphics/png;png ( checkperms>=1.1 )
sysutils/checkperms;checkperms graphics/tiff;tiff ( checkperms>=1.1 )
sysutils/checkperms;checkperms lang/perl5;perl ( checkperms>=1.1 )
sysutils/checkperms;checkperms net/netcat;netcat ( checkperms>=1.1 )
sysutils/checkperms;checkperms pkgtools/x11-links;x11-links ( checkperms>=1.1 )
sysutils/checkperms;checkperms textproc/dict-client;dict-client ( checkperms>=1.1 )
sysutils/checkperms;checkperms textproc/dictem;dictem ( checkperms>=1.1 )
sysutils/checkperms;checkperms wip/awk-pkgsrc-dewey;awk-pkgsrc-dewey ( checkperms>=1.1 )
sysutils/checkperms;checkperms wip/dict-client;dict-client ( checkperms>=1.1 )
sysutils/checkperms;checkperms wip/dict-server;dict-server ( checkperms>=1.1 )
sysutils/checkperms;checkperms wip/distbb;distbb ( checkperms>=1.1 )
sysutils/checkperms;checkperms wip/paexec;paexec ( checkperms>=1.1 )
sysutils/checkperms;checkperms wip/pkg_online-client;pkg_online-client ( checkperms>=1.1 )
sysutils/checkperms;checkperms wip/pkg_online-server;pkg_online-server ( checkperms>=1.1 )
sysutils/checkperms;checkperms wip/pkg_online;pkg_online ( checkperms>=1.1 )
sysutils/checkperms;checkperms wip/pkg_summary-utils;pkg_summary-utils ( checkperms>=1.1 )
sysutils/checkperms;checkperms wip/runawk;runawk ( checkperms>=1.1 )
textproc/dict-client;dict-client|wip/dict-client;dict-client textproc/dictem;dictem ( dict-client>=1.9.14 )
textproc/dict-client;dict-client|wip/dict-client;dict-client wip/pkg_online-client;pkg_online-client ( dict-client>=1.10.9 )
wip/awk-pkgsrc-dewey;awk-pkgsrc-dewey wip/pkg_summary-utils;pkg_summary-utils ( awk-pkgsrc-dewey>=0.5.6 )
wip/dict-server;dict-server wip/pkg_online-server;pkg_online-server ( dict-server>=1.10.10nb2 )
wip/paexec;paexec wip/distbb;distbb ( paexec>=0.10.0 )
wip/pkg_online-client;pkg_online-client wip/pkg_online;pkg_online ( pkg_online-client-[0-9]* )
wip/pkg_online-server;pkg_online-server wip/pkg_online;pkg_online ( pkg_online-server-[0-9]* )
wip/pkg_summary-utils;pkg_summary-utils wip/distbb;distbb ( pkg_summary-utils>=0.18.1 )
wip/pkg_summary-utils;pkg_summary-utils wip/pkg_online-client;pkg_online-client ( pkg_summary-utils-[0-9]* )
wip/pkg_summary-utils;pkg_summary-utils wip/pkg_online-server;pkg_online-server ( pkg_summary-utils>=0.19.0 )
wip/runawk;runawk wip/awk-pkgsrc-dewey;awk-pkgsrc-dewey ( runawk-[0-9]* )
wip/runawk;runawk wip/distbb;distbb ( runawk>=0.13.0 )
wip/runawk;runawk wip/pkg_summary-utils;pkg_summary-utils ( runawk>=0.12.1 )
www/ap2-vhost-ldap:PKG_APACHE=apache2;ap2-vhost-ldap
www/ap22-vhost-ldap:PKG_APACHE=apache22;ap22-vhost-ldap
'

pkg_summary2deps -dntRa src_summary.txt | sort |
cmp 'pkg_summary2deps #13' \
'ap2-vhost-ldap ap2-vhost-ldap
ap22-vhost-ldap ap22-vhost-ldap
awk-pkgsrc-dewey pkg_summary-utils ( awk-pkgsrc-dewey>=0.5.6 )
checkperms checkperms
dict-client|dict-client dictem ( dict-client>=1.9.14 )
dict-client|dict-client pkg_online-client ( dict-client>=1.10.9 )
dict-server pkg_online-server ( dict-server>=1.10.10nb2 )
emacs dictem ( emacs>=22 )
gmake gmake
jpeg emacs ( jpeg>=6bnb2 )
jpeg tiff ( jpeg>=6bnb2 )
libltdl dict-client ( libltdl>=1.5.10 )
libmaa dict-client ( libmaa>=1.0 )
libmaa dict-server ( libmaa>=1.2 )
libmaa paexec ( libmaa>=0.990 )
libtool-base libtool-base
libungif emacs ( libungif>=4.1.3nb1 )
netcat pkg_online-client ( netcat-[0-9]* )
paexec distbb ( paexec>=0.10.0 )
perl emacs ( perl>=5.0 )
perl libungif ( perl>=5.0 )
pipestatus pkg_online-client ( pipestatus-[0-9]* )
pipestatus pkg_online-server ( pipestatus-[0-9]* )
pipestatus pkg_summary-utils ( pipestatus-[0-9]* )
pkg-config pkg-config
pkg_online-client pkg_online ( pkg_online-client-[0-9]* )
pkg_online-server pkg_online ( pkg_online-server-[0-9]* )
pkg_summary-utils distbb ( pkg_summary-utils>=0.18.1 )
pkg_summary-utils pkg_online-client ( pkg_summary-utils-[0-9]* )
pkg_summary-utils pkg_online-server ( pkg_summary-utils>=0.19.0 )
png emacs ( png>=1.2.9nb2 )
runawk awk-pkgsrc-dewey ( runawk-[0-9]* )
runawk distbb ( runawk>=0.13.0 )
runawk pkg_summary-utils ( runawk>=0.12.1 )
tiff emacs ( tiff>=3.7.2nb1 )
x11-links x11-links
'

pkg_summary2deps -ApntrR src_summary7.txt | sort |
cmp 'pkg_summary2deps #14' \
'audio/py-mutagen:PYTHON_VERSION_REQD=24;py24-mutagen-1.15 audio/py-karaoke:PYTHON_VERSION_REQD=24;py24-karaoke-0.7.1 ( py24-mutagen>=1.9 )
audio/py-mutagen:PYTHON_VERSION_REQD=26;py26-mutagen-1.15 audio/py-karaoke:PYTHON_VERSION_REQD=26;py26-karaoke-0.7.1 ( py26-mutagen>=1.9 )
audio/py-mutagen;py25-mutagen-1.15 audio/py-karaoke;py25-karaoke-0.7.1 ( py25-mutagen>=1.9 )
'

pkg_summary2deps -DpR src_summary8.txt | sort | uniq |
cmp 'pkg_summary2deps #15' \
'lang/perl5;perl devel/p5-ExtUtils-CBuilder;p5-ExtUtils-CBuilder ( perl>=5.10 )
lang/perl5;perl devel/p5-ExtUtils-ParseXS;p5-ExtUtils-ParseXS ( perl>=5.10 )
lang/perl5;perl devel/p5-Module-Build;p5-Module-Build ( perl>=5.10.0 )
lang/perl5;perl devel/p5-version;p5-version ( perl>=5.10 )
sysutils/checkperms;checkperms archivers/p5-Archive-Tar;p5-Archive-Tar ( checkperms>=1.0 )
sysutils/checkperms;checkperms devel/p5-Algorithm-Diff;p5-Algorithm-Diff ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/p5-Compress-Raw-Bzip2;p5-Compress-Raw-Bzip2 ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/p5-Compress-Raw-Zlib;p5-Compress-Raw-Zlib ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/p5-ExtUtils-CBuilder;p5-ExtUtils-CBuilder ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/p5-ExtUtils-ParseXS;p5-ExtUtils-ParseXS ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/p5-IO-Compress;p5-IO-Compress ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/p5-IO-String;p5-IO-String ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/p5-IO-Zlib;p5-IO-Zlib ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/p5-Module-Build;p5-Module-Build ( checkperms>=1.1 )
sysutils/checkperms;checkperms devel/p5-version;p5-version ( checkperms>=1.1 )
sysutils/checkperms;checkperms lang/perl5;perl ( checkperms>=1.1 )
sysutils/checkperms;checkperms textproc/p5-Filter;p5-Filter ( checkperms>=1.1 )
sysutils/checkperms;checkperms textproc/p5-Pod-Readme;p5-Pod-Readme ( checkperms>=1.1 )
sysutils/checkperms;checkperms textproc/p5-Regexp-Common;p5-Regexp-Common ( checkperms>=1.1 )
sysutils/checkperms;checkperms textproc/p5-Text-Diff;p5-Text-Diff ( checkperms>=1.1 )
sysutils/checkperms;checkperms textproc/p5-YAML;p5-YAML ( checkperms>=1.1 )
textproc/p5-YAML;p5-YAML devel/p5-Module-Build;p5-Module-Build ( p5-YAML>=0.50 )
'

pkg_summary2deps -DpRr src_summary8.txt | sort | uniq |
cmp 'pkg_summary2deps #16' \
'lang/perl5;perl-5.10.0nb7 devel/p5-ExtUtils-CBuilder;p5-ExtUtils-CBuilder-0.26.03.01 ( perl>=5.10 )
lang/perl5;perl-5.10.0nb7 devel/p5-ExtUtils-ParseXS;p5-ExtUtils-ParseXS-2.20.04.01 ( perl>=5.10 )
lang/perl5;perl-5.10.0nb7 devel/p5-Module-Build;p5-Module-Build-0.35000 ( perl>=5.10.0 )
lang/perl5;perl-5.10.0nb7 devel/p5-version;p5-version-0.7702 ( perl>=5.10 )
sysutils/checkperms;checkperms-1.10 archivers/p5-Archive-Tar;p5-Archive-Tar-1.54 ( checkperms>=1.0 )
sysutils/checkperms;checkperms-1.10 devel/p5-Algorithm-Diff;p5-Algorithm-Diff-1.1902nb1 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 devel/p5-Compress-Raw-Bzip2;p5-Compress-Raw-Bzip2-2.021 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 devel/p5-Compress-Raw-Zlib;p5-Compress-Raw-Zlib-2.021 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 devel/p5-ExtUtils-CBuilder;p5-ExtUtils-CBuilder-0.26.03.01 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 devel/p5-ExtUtils-ParseXS;p5-ExtUtils-ParseXS-2.20.04.01 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 devel/p5-IO-Compress;p5-IO-Compress-2.021 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 devel/p5-IO-String;p5-IO-String-1.08nb1 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 devel/p5-IO-Zlib;p5-IO-Zlib-1.10 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 devel/p5-Module-Build;p5-Module-Build-0.35000 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 devel/p5-version;p5-version-0.7702 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 lang/perl5;perl-5.10.0nb7 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 textproc/p5-Filter;p5-Filter-1.37 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 textproc/p5-Pod-Readme;p5-Pod-Readme-0.09 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 textproc/p5-Regexp-Common;p5-Regexp-Common-2.122nb1 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 textproc/p5-Text-Diff;p5-Text-Diff-1.37 ( checkperms>=1.1 )
sysutils/checkperms;checkperms-1.10 textproc/p5-YAML;p5-YAML-0.70 ( checkperms>=1.1 )
textproc/p5-YAML;p5-YAML-0.70 devel/p5-Module-Build;p5-Module-Build-0.35000 ( p5-YAML>=0.50 )
'

pkg_summary2deps -dn bin_summary1.txt | sort |
cmp 'pkg_summary2deps #17' \
'awk-pkgsrc-dewey pkg_summary-utils
checkperms
dict-client pkg_online-client
dict-server pkg_online-server
gmake
libmaa dict-client
libmaa dict-server
libmaa paexec
libtool-base
netcat pkg_online-client
paexec distbb
pipestatus distbb
pipestatus pkg_online-client
pipestatus pkg_online-server
pipestatus pkg_summary-utils
pkg_online-client pkg_conflicts
pkg_online-client pkg_online
pkg_online-server pkg_online
pkg_summary-utils distbb
pkg_summary-utils pkg_conflicts
pkg_summary-utils pkg_online-client
pkg_summary-utils pkg_online-server
pkgnih
runawk awk-pkgsrc-dewey
runawk distbb
runawk paexec
runawk pkg_conflicts
runawk pkg_summary-utils
'

pkg_summary2deps -dn2 bin_summary1.txt | sort |
cmp 'pkg_summary2deps #17.1' \
'DEPENDS awk-pkgsrc-dewey pkg_summary-utils
DEPENDS dict-client pkg_online-client
DEPENDS dict-server pkg_online-server
DEPENDS libmaa dict-client
DEPENDS libmaa dict-server
DEPENDS libmaa paexec
DEPENDS netcat pkg_online-client
DEPENDS paexec distbb
DEPENDS pipestatus distbb
DEPENDS pipestatus pkg_online-client
DEPENDS pipestatus pkg_online-server
DEPENDS pipestatus pkg_summary-utils
DEPENDS pkg_online-client pkg_conflicts
DEPENDS pkg_online-client pkg_online
DEPENDS pkg_online-server pkg_online
DEPENDS pkg_summary-utils distbb
DEPENDS pkg_summary-utils pkg_conflicts
DEPENDS pkg_summary-utils pkg_online-client
DEPENDS pkg_summary-utils pkg_online-server
DEPENDS runawk awk-pkgsrc-dewey
DEPENDS runawk distbb
DEPENDS runawk paexec
DEPENDS runawk pkg_conflicts
DEPENDS runawk pkg_summary-utils
checkperms
gmake
libtool-base
pkgnih
'

pkg_summary2deps -Apn bin_summary1.txt | sort |
cmp 'pkg_summary2deps #18' \
'devel/gmake;gmake
devel/libmaa;libmaa wip/dict-client;dict-client
devel/libmaa;libmaa wip/dict-server;dict-server
devel/libmaa;libmaa wip/paexec;paexec
devel/libtool-base;libtool-base
devel/pipestatus;pipestatus wip/distbb;distbb
devel/pipestatus;pipestatus wip/pkg_online-client;pkg_online-client
devel/pipestatus;pipestatus wip/pkg_online-server;pkg_online-server
devel/pipestatus;pipestatus wip/pkg_summary-utils;pkg_summary-utils
net/netcat;netcat wip/pkg_online-client;pkg_online-client
sysutils/checkperms;checkperms
wip/awk-pkgsrc-dewey;awk-pkgsrc-dewey wip/pkg_summary-utils;pkg_summary-utils
wip/dict-client;dict-client wip/pkg_online-client;pkg_online-client
wip/dict-server;dict-server wip/pkg_online-server;pkg_online-server
wip/paexec;paexec wip/distbb;distbb
wip/pkg_online-client;pkg_online-client wip/pkg_conflicts;pkg_conflicts
wip/pkg_online-client;pkg_online-client wip/pkg_online;pkg_online
wip/pkg_online-server;pkg_online-server wip/pkg_online;pkg_online
wip/pkg_summary-utils;pkg_summary-utils wip/distbb;distbb
wip/pkg_summary-utils;pkg_summary-utils wip/pkg_conflicts;pkg_conflicts
wip/pkg_summary-utils;pkg_summary-utils wip/pkg_online-client;pkg_online-client
wip/pkg_summary-utils;pkg_summary-utils wip/pkg_online-server;pkg_online-server
wip/pkgnih;pkgnih
wip/runawk;runawk wip/awk-pkgsrc-dewey;awk-pkgsrc-dewey
wip/runawk;runawk wip/distbb;distbb
wip/runawk;runawk wip/paexec;paexec
wip/runawk;runawk wip/pkg_conflicts;pkg_conflicts
wip/runawk;runawk wip/pkg_summary-utils;pkg_summary-utils
'

pkg_summary2deps -ArR bin_summary1.txt | sort |
cmp 'pkg_summary2deps #19' \
'awk-pkgsrc-dewey-0.5.6 pkg_summary-utils-0.35rc1 ( awk-pkgsrc-dewey>=0.5.6 )
checkperms-1.10
dict-client-1.11.2 pkg_online-client-0.9.1 ( dict-client>=1.10.9 )
dict-server-1.11.2 pkg_online-server-0.9.1 ( dict-server>=1.10.10nb2 )
gmake-3.81
libmaa-1.1.0 dict-client-1.11.2 ( libmaa>=0.990 )
libmaa-1.1.0 dict-server-1.11.2 ( libmaa>=0.990 )
libmaa-1.1.0 paexec-0.13.0nb1 ( libmaa>=0.990 )
libtool-base-1.5.26nb2
netcat-1.10nb2 pkg_online-client-0.9.1 ( netcat-[0-9]* )
paexec-0.13.0nb1 distbb-0.33.0 ( paexec>=0.13.0nb1 )
pipestatus-0.6.0 distbb-0.33.0 ( pipestatus>=0.5.0 )
pipestatus-0.6.0 pkg_online-client-0.9.1 ( pipestatus-[0-9]* )
pipestatus-0.6.0 pkg_online-server-0.9.1 ( pipestatus-[0-9]* )
pipestatus-0.6.0 pkg_summary-utils-0.35rc1 ( pipestatus-[0-9]* )
pkg_online-client-0.9.1 pkg_conflicts-0.4.0 ( pkg_online-client>=0.6.0 )
pkg_online-client-0.9.1 pkg_online-0.9.1 ( pkg_online-client-0.9.1 )
pkg_online-server-0.9.1 pkg_online-0.9.1 ( pkg_online-server-0.9.1 )
pkg_summary-utils-0.35rc1 distbb-0.33.0 ( pkg_summary-utils>=0.31.0 )
pkg_summary-utils-0.35rc1 pkg_conflicts-0.4.0 ( pkg_summary-utils-[0-9]* )
pkg_summary-utils-0.35rc1 pkg_online-client-0.9.1 ( pkg_summary-utils-[0-9]* )
pkg_summary-utils-0.35rc1 pkg_online-server-0.9.1 ( pkg_summary-utils>=0.18.1 )
pkgnih-0.3.1
runawk-0.18.0 awk-pkgsrc-dewey-0.5.6 ( runawk-[0-9]* )
runawk-0.18.0 distbb-0.33.0 ( runawk>=0.14.3 )
runawk-0.18.0 paexec-0.13.0nb1 ( runawk>=0.16.0 )
runawk-0.18.0 pkg_conflicts-0.4.0 ( runawk>=0.14.3 )
runawk-0.18.0 pkg_summary-utils-0.35rc1 ( runawk>=0.16.0 )
'

pkg_summary2deps -Apa src_summary11.txt | sort |
cmp 'pkg_summary2deps #20' \
'audio/libao audio/libao-oss
audio/libao audio/vorbis-tools
audio/libao-oss audio/vorbis-tools
devel/gmake editors/emacs20
devel/gmake textproc/dict-client
devel/libmaa textproc/dict-client
devel/libtool-base devel/libmaa
devel/libtool-base textproc/dict-client
editors/emacs|editors/emacs22|editors/emacs21|editors/emacs20 textproc/dictem
editors/emacs|editors/emacs22|editors/emacs21|editors/emacs20 textproc/dictem:EMACS_TYPE=emacs20
editors/emacs|editors/emacs22|editors/emacs21|editors/emacs20 textproc/dictem:EMACS_TYPE=emacs21
editors/emacs|editors/emacs22|editors/emacs21|editors/emacs20 textproc/dictem:EMACS_TYPE=emacs23
editors/emacs|editors/emacs22|editors/emacs21|editors/emacs20 wip/emterm
lang/f2c devel/libtool-base
lang/perl5 devel/p5-ExtUtils-CBuilder
sysutils/checkperms devel/gmake
sysutils/checkperms devel/libmaa
sysutils/checkperms devel/libtool-base
sysutils/checkperms devel/p5-ExtUtils-CBuilder
sysutils/checkperms editors/emacs20
sysutils/checkperms lang/f2c
sysutils/checkperms lang/perl5
sysutils/checkperms textproc/dict-client
sysutils/checkperms textproc/dictem
sysutils/checkperms textproc/dictem:EMACS_TYPE=emacs20
sysutils/checkperms textproc/dictem:EMACS_TYPE=emacs21
sysutils/checkperms textproc/dictem:EMACS_TYPE=emacs23
textproc/dict-client textproc/dictem
textproc/dict-client textproc/dictem:EMACS_TYPE=emacs20
textproc/dict-client textproc/dictem:EMACS_TYPE=emacs21
textproc/dict-client textproc/dictem:EMACS_TYPE=emacs23
'

pkg_summary2deps -Apas src_summary11.txt | sort |
cmp 'pkg_summary2deps #20.1' \
'audio/libao audio/libao-oss
audio/libao audio/vorbis-tools
audio/libao-oss audio/vorbis-tools
devel/gmake editors/emacs20
devel/gmake textproc/dict-client
devel/libmaa textproc/dict-client
devel/libtool-base devel/libmaa
devel/libtool-base textproc/dict-client
editors/emacs textproc/dictem:EMACS_TYPE=emacs23
editors/emacs20 textproc/dictem:EMACS_TYPE=emacs20
editors/emacs21 textproc/dictem:EMACS_TYPE=emacs21
editors/emacs22 textproc/dictem
editors/emacs|editors/emacs22|editors/emacs21|editors/emacs20 wip/emterm
lang/f2c devel/libtool-base
lang/perl5 devel/p5-ExtUtils-CBuilder
sysutils/checkperms devel/gmake
sysutils/checkperms devel/libmaa
sysutils/checkperms devel/libtool-base
sysutils/checkperms devel/p5-ExtUtils-CBuilder
sysutils/checkperms editors/emacs20
sysutils/checkperms lang/f2c
sysutils/checkperms lang/perl5
sysutils/checkperms textproc/dict-client
sysutils/checkperms textproc/dictem
sysutils/checkperms textproc/dictem:EMACS_TYPE=emacs20
sysutils/checkperms textproc/dictem:EMACS_TYPE=emacs21
sysutils/checkperms textproc/dictem:EMACS_TYPE=emacs23
textproc/dict-client textproc/dictem
textproc/dict-client textproc/dictem:EMACS_TYPE=emacs20
textproc/dict-client textproc/dictem:EMACS_TYPE=emacs21
textproc/dict-client textproc/dictem:EMACS_TYPE=emacs23
'

pkg_summary2deps -dn src_summary10.txt 2>&1 >/dev/null | sort |
cmp 'pkg_summary2deps #21' \
'Cannot find dependency depends1 for package pkgtools/barbaz (barbaz)
Cannot find dependency depends2 for package pkgtools/barbaz (barbaz)
'

pkg_summary2deps -dln src_summary10.txt 2>&1 >/dev/null | sort |
cmp 'pkg_summary2deps #22' \
'd: not_found depends1 <- pkgtools/barbaz barbaz
d: not_found depends2 <- pkgtools/barbaz barbaz
'

pkg_summary2deps -dns src_summary.txt 2>&1 >/dev/null | sort |
cmp 'pkg_summary2deps #23' \
'Cannot find dependency libmaa>=1.2 for package wip/dict-server (dict-server-1.10.11nb2)
Cannot find dependency pkg_summary-utils>=0.19.0 for package wip/pkg_online-server (pkg_online-server-0.5.0)
'

pkg_summary2deps -dlns src_summary.txt 2>&1 >/dev/null | sort |
cmp 'pkg_summary2deps #24' \
'd: not_found libmaa>=1.2 <- wip/dict-server dict-server-1.10.11nb2
d: not_found pkg_summary-utils>=0.19.0 <- wip/pkg_online-server pkg_online-server-0.5.0
'

pkg_summary2deps -dns src_summary2.txt 2>&1 >/dev/null | sort |
cmp 'pkg_summary2deps #25' \
'Cannot find dependency pkg_online-client-0.5.0nb2 for package wip/pkg_online (pkg_online-0.5.0nb2)
Cannot find dependency pkg_online-server-0.5.0nb2 for package wip/pkg_online (pkg_online-0.5.0nb2)
'

pkg_summary2deps -dlns src_summary2.txt 2>&1 >/dev/null | sort |
cmp 'pkg_summary2deps #26' \
'd: not_found pkg_online-client-0.5.0nb2 <- wip/pkg_online pkg_online-0.5.0nb2
d: not_found pkg_online-server-0.5.0nb2 <- wip/pkg_online pkg_online-0.5.0nb2
'

pkg_summary2deps -dlns src_summary9.txt 2>&1 | sort |
cmp 'pkg_summary2deps #27' \
'd: not_found dbus>=0.91 <- editors/emacs emacs-23.2nb2
d: not_found desktop-file-utils>=0.10nb1 <- editors/emacs emacs-23.2nb2
d: not_found desktop-file-utils>=0.8 <- editors/emacs emacs-23.2nb2
d: not_found dict-client>=1.9.14 <- textproc/dictem dictem-1.0.2nb1
d: not_found fontconfig>=2.1nb2 <- editors/emacs emacs-23.2nb2
d: not_found fontconfig>=2.4.2 <- editors/emacs emacs-23.2nb2
d: not_found freetype2>=2.1.10nb1 <- editors/emacs emacs-23.2nb2
d: not_found freetype2>=2.1.3 <- editors/emacs emacs-23.2nb2
d: not_found freetype2>=2.1.8 <- editors/emacs emacs-23.2nb2
d: not_found gtk2+>=2.20.1nb2 <- editors/emacs emacs-23.2nb2
d: not_found gtk2+>=2.4.0 <- editors/emacs emacs-23.2nb2
d: not_found hicolor-icon-theme>=0.4 <- editors/emacs emacs-23.2nb2
d: not_found hicolor-icon-theme>=0.9nb1 <- editors/emacs emacs-23.2nb2
d: not_found jpeg>=8nb1 <- editors/emacs emacs-23.2nb2
d: not_found jpeg>=8nb1 <- editors/emacs emacs-23.2nb2
d: not_found jpeg>=8nb1 <- editors/emacs21 emacs-21.4anb19
d: not_found jpeg>=8nb1 <- editors/emacs21 emacs-21.4anb19
d: not_found jpeg>=8nb1 <- editors/emacs22 emacs-22.3nb10
d: not_found jpeg>=8nb1 <- editors/emacs22 emacs-22.3nb10
d: not_found libSM>=0.99.2 <- editors/emacs emacs-23.2nb2
d: not_found libXaw>=1.0.5 <- editors/emacs21 emacs-21.4anb19
d: not_found libXaw>=1.0.5 <- editors/emacs22 emacs-22.3nb10
d: not_found libXft>=2.1.10 <- editors/emacs emacs-23.2nb2
d: not_found libXpm>=3.5.4.2 <- editors/emacs emacs-23.2nb2
d: not_found libXpm>=3.5.4.2 <- editors/emacs21 emacs-21.4anb19
d: not_found libXpm>=3.5.4.2 <- editors/emacs22 emacs-22.3nb10
d: not_found libmaa>=1.2.0 <- wip/paexec paexec-0.14.0
d: not_found libotf>=0.9.7 <- editors/emacs emacs-23.2nb2
d: not_found librsvg>=2.12.6nb1 <- editors/emacs emacs-23.2nb2
d: not_found librsvg>=2.26.3nb2 <- editors/emacs emacs-23.2nb2
d: not_found libungif>=4.1.0 <- editors/emacs emacs-23.2nb2
d: not_found libungif>=4.1.0 <- editors/emacs21 emacs-21.4anb19
d: not_found libungif>=4.1.0 <- editors/emacs22 emacs-22.3nb10
d: not_found libungif>=4.1.0.1 <- editors/emacs21 emacs-21.4anb19
d: not_found libungif>=4.1.0.1 <- editors/emacs22 emacs-22.3nb10
d: not_found libungif>=4.1.3nb1 <- editors/emacs emacs-23.2nb2
d: not_found libungif>=4.1.3nb1 <- editors/emacs21 emacs-21.4anb19
d: not_found libungif>=4.1.3nb1 <- editors/emacs22 emacs-22.3nb10
d: not_found m17n-lib>=1.5.1 <- editors/emacs emacs-23.2nb2
d: not_found m17n-lib>=1.6.1 <- editors/emacs emacs-23.2nb2
d: not_found paexec>=0.15.0 <- wip/distbb distbb-0.38.2
d: not_found perl>=5.0 <- editors/emacs21 emacs-21.4anb19
d: not_found perl>=5.0 <- editors/emacs22 emacs-22.3nb10
d: not_found pipestatus>=0.6.0 <- wip/distbb distbb-0.38.2
d: not_found pkg_summary-utils>=0.46 <- wip/pkg_status pkg_status-0.11
d: not_found pkg_summary-utils>=0.47.0 <- wip/distbb distbb-0.38.2
d: not_found pkg_summary-utils>=0.49beta2 <- wip/pkgnih pkgnih-0.0.1
d: not_found png>=1.2.4 <- editors/emacs emacs-23.2nb2
d: not_found png>=1.2.4 <- editors/emacs21 emacs-21.4anb19
d: not_found png>=1.2.4 <- editors/emacs22 emacs-22.3nb10
d: not_found png>=1.4.2 <- editors/emacs emacs-23.2nb2
d: not_found png>=1.4.2 <- editors/emacs21 emacs-21.4anb19
d: not_found png>=1.4.2 <- editors/emacs22 emacs-22.3nb10
d: not_found runawk>=1.1.0 <- wip/distbb distbb-0.38.2
d: not_found runawk>=1.1.0 <- wip/pkg_summary-utils pkg_summary-utils-0.45
d: not_found tiff>=3.6.1 <- editors/emacs emacs-23.2nb2
d: not_found tiff>=3.6.1 <- editors/emacs21 emacs-21.4anb19
d: not_found tiff>=3.6.1 <- editors/emacs22 emacs-22.3nb10
d: not_found tiff>=3.9.2nb1 <- editors/emacs emacs-23.2nb2
d: not_found tiff>=3.9.2nb1 <- editors/emacs21 emacs-21.4anb19
d: not_found tiff>=3.9.2nb1 <- editors/emacs22 emacs-22.3nb10
digest distbb
emacs dictem
libmaa
pipestatus pkg_status
pipestatus pkg_summary-utils
pipestatus pkgnih
pkg_status pkgnih
runawk paexec
'

pkg_summary2deps -c src_summary9.txt 2>&1 | sort |
cmp 'pkg_summary2deps #28' \
'editors/emacs22 (emacs-22.3nb10) conflicts (emacs-[0-9]*) with editors/emacs (emacs-23.2nb2)
editors/emacs22 (emacs-22.3nb10) conflicts (emacs-[0-9]*) with editors/emacs21 (emacs-21.4anb19)
'

pkg_summary2deps -cl src_summary9.txt 2>&1 | sort |
cmp 'pkg_summary2deps #29' \
'c: conflict emacs-[0-9]* editors/emacs emacs-23.2nb2 <- editors/emacs22 emacs-22.3nb10
c: conflict emacs-[0-9]* editors/emacs21 emacs-21.4anb19 <- editors/emacs22 emacs-22.3nb10
'

pkg_summary2deps -cl src_summary12.txt 2>&1 >/dev/null | sort |
cmp 'pkg_summary2deps #30' \
'c: conflict awk-pkgsrc-dewey-[0-9]* wip/awk-pkgsrc-dewey awk-pkgsrc-dewey-0.5.6 <- wip/pkg_summary-utils pkg_summary-utils-0.49beta2
c: conflict egcs-current-19980608 somewhere/egcs-current egcs-current-19980608 <- lang/f2c f2c-20090411nb5
c: conflict glibtool-[0-9]* somewhere/glibtool glibtool-1.2.3 <- devel/libtool-base libtool-base-2.2.6bnb4
c: conflict libtool<=1.3.5nb11 somewhere/libtool libtool-1.3.4 <- devel/libtool-base libtool-base-2.2.6bnb4
c: conflict libtool<=1.3.5nb11 somewhere/libtool133 libtool-1.3.3 <- devel/libtool-base libtool-base-2.2.6bnb4
c: conflict libtool<=1.3.5nb11 somewhere/libtool136 libtool-1.3.6 <- devel/libtool-base libtool-base-2.2.6bnb4
c: conflict paexec<0.15.0 wip/paexec paexec-0.13.0 <- wip/pkg_summary-utils pkg_summary-utils-0.49beta2
c: conflict pkg_cmp_summary-[0-9]* somewhere/pkg_cmp_summary pkg_cmp_summary-0.0.1 <- wip/pkg_summary-utils pkg_summary-utils-0.49beta2
c: conflict pkg_src_update_summary-[0-9]* somewhere/pkg_src_update_summary pkg_src_update_summary-0.0.2 <- wip/pkg_summary-utils pkg_summary-utils-0.49beta2
c: conflict pkg_summary4view-[0-9]* somewhere/pkg_summary4view pkg_summary4view-0.0.4 <- wip/pkg_summary-utils pkg_summary-utils-0.49beta2
c: conflict pkg_update_summary-[0-9]* somewhere/pkg_update_summary pkg_update_summary-0.0.3 <- wip/pkg_summary-utils pkg_summary-utils-0.49beta2
'

pkg_summary2deps -cls src_summary12.txt 2>&1 >/dev/null | sort |
cmp 'pkg_summary2deps #30.1' \
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
'

pkg_summary2deps -Acldns src_summary12.txt 2>&1 | sort |
cmp 'pkg_summary2deps #31' \
'awk-pkgsrc-dewey
c: conflict awk-pkgsrc-dewey-[0-9]* wip/awk-pkgsrc-dewey awk-pkgsrc-dewey-0.5.6 <- wip/pkg_summary-utils pkg_summary-utils-0.49beta2
c: conflict egcs-current-19980608 somewhere/egcs-current egcs-current-19980608 <- lang/f2c f2c-20090411nb5
c: conflict glibtool-[0-9]* somewhere/glibtool glibtool-1.2.3 <- devel/libtool-base libtool-base-2.2.6bnb4
c: conflict libtool<=1.3.5nb11 somewhere/libtool libtool-1.3.4 <- devel/libtool-base libtool-base-2.2.6bnb4
c: conflict libtool<=1.3.5nb11 somewhere/libtool133 libtool-1.3.3 <- devel/libtool-base libtool-base-2.2.6bnb4
c: conflict paexec<0.15.0 wip/paexec paexec-0.13.0 <- wip/pkg_summary-utils pkg_summary-utils-0.49beta2
c: conflict pkg_cmp_summary-[0-9]* somewhere/pkg_cmp_summary pkg_cmp_summary-0.0.1 <- wip/pkg_summary-utils pkg_summary-utils-0.49beta2
c: conflict pkg_src_update_summary-[0-9]* somewhere/pkg_src_update_summary pkg_src_update_summary-0.0.2 <- wip/pkg_summary-utils pkg_summary-utils-0.49beta2
c: conflict pkg_summary4view-[0-9]* somewhere/pkg_summary4view pkg_summary4view-0.0.4 <- wip/pkg_summary-utils pkg_summary-utils-0.49beta2
c: conflict pkg_update_summary-[0-9]* somewhere/pkg_update_summary pkg_update_summary-0.0.3 <- wip/pkg_summary-utils pkg_summary-utils-0.49beta2
checkperms distbb
checkperms f2c
checkperms libmaa
checkperms libtool-base
checkperms mk-configure
checkperms paexec
checkperms pipestatus
checkperms pkg_status
checkperms pkg_summary-utils
checkperms runawk
d: not_found mk-configure>=0.20.0 <- wip/paexec paexec-0.13.0
d: not_found mk-configure>=0.20.0 <- wip/pkg_summary-utils pkg_summary-utils-0.49beta2
d: not_found mk-configure>=0.20.0 <- wip/runawk runawk-1.2.0
d: not_found paexec>=0.15.0 <- wip/distbb distbb-0.38.2
digest distbb
egcs-current
f2c libtool-base
glibtool
libmaa paexec
libtool
libtool-base libmaa
pipestatus distbb
pipestatus pkg_status
pipestatus pkg_summary-utils
pkg_cmp_summary
pkg_src_update_summary
pkg_summary-utils distbb
pkg_summary-utils pkg_status
pkg_summary4view
pkg_update_summary
runawk distbb
runawk paexec
runawk pkg_summary-utils
'

pkg_summary2deps -AplnrRa src_summary13.txt 2>&1 | sort |
cmp 'pkg_summary2deps #32' \
'audio/libao-oss;libao-oss-1.0.0|audio/libao-oss;libao-oss-1.0.0|audio/libao-alsa;libao-alsa-1.0.0|audio/libao-arts;libao-arts-1.0.0|audio/libao-esound;libao-esound-1.0.0|audio/libao-nas;libao-nas-1.0.0|audio/libao-pulse;libao-pulse-1.0.0 audio/vorbis-tools;vorbis-tools-1.2.0nb4 ( libao-[a-z]*-[0-9]* )
audio/libao;libao-1.0.0 audio/libao-alsa;libao-alsa-1.0.0 ( libao>=1.0.0 )
audio/libao;libao-1.0.0 audio/libao-arts;libao-arts-1.0.0 ( libao>=1.0.0 )
audio/libao;libao-1.0.0 audio/libao-esound;libao-esound-1.0.0 ( libao>=1.0.0 )
audio/libao;libao-1.0.0 audio/libao-nas;libao-nas-1.0.0 ( libao>=1.0.0 )
audio/libao;libao-1.0.0 audio/libao-oss;libao-oss-1.0.0 ( libao>=1.0.0 )
audio/libao;libao-1.0.0 audio/libao-pulse;libao-pulse-1.0.0 ( libao>=1.0.0 )
audio/libao;libao-1.0.0 audio/vorbis-tools;vorbis-tools-1.2.0nb4 ( libao>=1.0.0 )
d: not_found alsa-lib>=1.0.18 <- audio/libao-alsa libao-alsa-1.0.0
d: not_found arts>=1.1.4nb1 <- audio/libao-arts libao-arts-1.0.0
d: not_found arts>=1.5.8nb1 <- audio/libao-arts libao-arts-1.0.0
d: not_found curl>=7.19.7nb1 <- audio/vorbis-tools vorbis-tools-1.2.0nb4
d: not_found esound>=0.2.18 <- audio/libao-esound libao-esound-1.0.0
d: not_found esound>=0.2.35nb1 <- audio/libao-esound libao-esound-1.0.0
d: not_found flac>=1.1.3nb1 <- audio/vorbis-tools vorbis-tools-1.2.0nb4
d: not_found libXau>=1.0 <- audio/libao-nas libao-nas-1.0.0
d: not_found libogg>=1.1.2nb1 <- audio/vorbis-tools vorbis-tools-1.2.0nb4
d: not_found libvorbis>=1.1.0nb1 <- audio/vorbis-tools vorbis-tools-1.2.0nb4
d: not_found nas>=1.4.2 <- audio/libao-nas libao-nas-1.0.0
d: not_found nas>=1.7bnb2 <- audio/libao-nas libao-nas-1.0.0
d: not_found pulseaudio>=0.9.13 <- audio/libao-pulse libao-pulse-1.0.0
d: not_found speex>=1.2rc1 <- audio/vorbis-tools vorbis-tools-1.2.0nb4
'

pkg_summary2deps -AplnrR src_summary13.txt 2>&1 | sort |
cmp 'pkg_summary2deps #32.1' \
'audio/libao-oss;libao-oss-1.0.0 audio/vorbis-tools;vorbis-tools-1.2.0nb4 ( libao-[a-z]*-[0-9]* )
audio/libao;libao-1.0.0 audio/libao-alsa;libao-alsa-1.0.0 ( libao>=1.0.0 )
audio/libao;libao-1.0.0 audio/libao-arts;libao-arts-1.0.0 ( libao>=1.0.0 )
audio/libao;libao-1.0.0 audio/libao-esound;libao-esound-1.0.0 ( libao>=1.0.0 )
audio/libao;libao-1.0.0 audio/libao-nas;libao-nas-1.0.0 ( libao>=1.0.0 )
audio/libao;libao-1.0.0 audio/libao-oss;libao-oss-1.0.0 ( libao>=1.0.0 )
audio/libao;libao-1.0.0 audio/libao-pulse;libao-pulse-1.0.0 ( libao>=1.0.0 )
audio/libao;libao-1.0.0 audio/vorbis-tools;vorbis-tools-1.2.0nb4 ( libao>=1.0.0 )
d: not_found alsa-lib>=1.0.18 <- audio/libao-alsa libao-alsa-1.0.0
d: not_found arts>=1.1.4nb1 <- audio/libao-arts libao-arts-1.0.0
d: not_found arts>=1.5.8nb1 <- audio/libao-arts libao-arts-1.0.0
d: not_found curl>=7.19.7nb1 <- audio/vorbis-tools vorbis-tools-1.2.0nb4
d: not_found esound>=0.2.18 <- audio/libao-esound libao-esound-1.0.0
d: not_found esound>=0.2.35nb1 <- audio/libao-esound libao-esound-1.0.0
d: not_found flac>=1.1.3nb1 <- audio/vorbis-tools vorbis-tools-1.2.0nb4
d: not_found libXau>=1.0 <- audio/libao-nas libao-nas-1.0.0
d: not_found libogg>=1.1.2nb1 <- audio/vorbis-tools vorbis-tools-1.2.0nb4
d: not_found libvorbis>=1.1.0nb1 <- audio/vorbis-tools vorbis-tools-1.2.0nb4
d: not_found nas>=1.4.2 <- audio/libao-nas libao-nas-1.0.0
d: not_found nas>=1.7bnb2 <- audio/libao-nas libao-nas-1.0.0
d: not_found pulseaudio>=0.9.13 <- audio/libao-pulse libao-pulse-1.0.0
d: not_found speex>=1.2rc1 <- audio/vorbis-tools vorbis-tools-1.2.0nb4
'

pkg_summary2deps -Apna src_summary13.txt 2>/dev/null | sort |
cmp 'pkg_summary2deps #33' \
'audio/libao-oss;libao-oss|audio/libao-oss;libao-oss|audio/libao-alsa;libao-alsa|audio/libao-arts;libao-arts|audio/libao-esound;libao-esound|audio/libao-nas;libao-nas|audio/libao-pulse;libao-pulse audio/vorbis-tools;vorbis-tools
audio/libao;libao audio/libao-alsa;libao-alsa
audio/libao;libao audio/libao-arts;libao-arts
audio/libao;libao audio/libao-esound;libao-esound
audio/libao;libao audio/libao-nas;libao-nas
audio/libao;libao audio/libao-oss;libao-oss
audio/libao;libao audio/libao-pulse;libao-pulse
audio/libao;libao audio/vorbis-tools;vorbis-tools
'

pkg_summary2deps -Apn src_summary13.txt 2>/dev/null | sort |
cmp 'pkg_summary2deps #33.1' \
'audio/libao-oss;libao-oss audio/vorbis-tools;vorbis-tools
audio/libao;libao audio/libao-alsa;libao-alsa
audio/libao;libao audio/libao-arts;libao-arts
audio/libao;libao audio/libao-esound;libao-esound
audio/libao;libao audio/libao-nas;libao-nas
audio/libao;libao audio/libao-oss;libao-oss
audio/libao;libao audio/libao-pulse;libao-pulse
audio/libao;libao audio/vorbis-tools;vorbis-tools
'

pkg_summary2deps -Apa src_summary13.txt 2>/dev/null | sort |
cmp 'pkg_summary2deps #34' \
'audio/libao audio/libao-alsa
audio/libao audio/libao-arts
audio/libao audio/libao-esound
audio/libao audio/libao-nas
audio/libao audio/libao-oss
audio/libao audio/libao-pulse
audio/libao audio/vorbis-tools
audio/libao-oss|audio/libao-oss|audio/libao-alsa|audio/libao-arts|audio/libao-esound|audio/libao-nas|audio/libao-pulse audio/vorbis-tools
'

pkg_summary2deps -Ap src_summary13.txt 2>/dev/null | sort |
cmp 'pkg_summary2deps #34.1' \
'audio/libao audio/libao-alsa
audio/libao audio/libao-arts
audio/libao audio/libao-esound
audio/libao audio/libao-nas
audio/libao audio/libao-oss
audio/libao audio/libao-pulse
audio/libao audio/vorbis-tools
audio/libao-oss audio/vorbis-tools
'

pkg_summary2deps -Ana src_summary13.txt 2>/dev/null | sort |
cmp 'pkg_summary2deps #35' \
'libao libao-alsa
libao libao-arts
libao libao-esound
libao libao-nas
libao libao-oss
libao libao-pulse
libao vorbis-tools
libao-oss|libao-oss|libao-alsa|libao-arts|libao-esound|libao-nas|libao-pulse vorbis-tools
'

pkg_summary2deps -An src_summary13.txt 2>/dev/null | sort |
cmp 'pkg_summary2deps #35.1' \
'libao libao-alsa
libao libao-arts
libao libao-esound
libao libao-nas
libao libao-oss
libao libao-pulse
libao vorbis-tools
libao-oss vorbis-tools
'

pkg_summary2deps -Apa -Pwip/distbb,editors/emacs src_summary.txt | sort |
cmp 'pkg_summary2deps #36' \
'devel/gmake editors/emacs
devel/pkg-config editors/emacs
graphics/jpeg editors/emacs
graphics/libungif editors/emacs
graphics/png editors/emacs
graphics/tiff editors/emacs
lang/perl5 editors/emacs
pkgtools/x11-links editors/emacs
sysutils/checkperms editors/emacs
sysutils/checkperms wip/distbb
wip/paexec wip/distbb
wip/pkg_summary-utils wip/distbb
wip/runawk wip/distbb
'

echo 'wip/distbb' > $tmpfn4
echo 'editors/emacs' >> $tmpfn4
pkg_summary2deps -Apa -P"$tmpfn4" src_summary.txt | sort |
cmp 'pkg_summary2deps #36.1' \
'devel/gmake editors/emacs
devel/pkg-config editors/emacs
graphics/jpeg editors/emacs
graphics/libungif editors/emacs
graphics/png editors/emacs
graphics/tiff editors/emacs
lang/perl5 editors/emacs
pkgtools/x11-links editors/emacs
sysutils/checkperms editors/emacs
sysutils/checkperms wip/distbb
wip/paexec wip/distbb
wip/pkg_summary-utils wip/distbb
wip/runawk wip/distbb
'

pkg_summary2deps -dn -P'wip/distbb sysutils/checkperms' src_summary.txt | sort |
cmp 'pkg_summary2deps #37' \
'checkperms
paexec distbb
pkg_summary-utils distbb
runawk distbb
'

pkg_summary2deps -dp -P'wip/distbb sysutils/checkperms' src_summary.txt | sort |
cmp 'pkg_summary2deps #38' \
'sysutils/checkperms
wip/paexec wip/distbb
wip/pkg_summary-utils wip/distbb
wip/runawk wip/distbb
'

pkg_summary2deps -Apa -N distbb-0.22.0,emacs-22.1nb6 src_summary.txt | sort |
cmp 'pkg_summary2deps #39' \
'devel/gmake editors/emacs
devel/pkg-config editors/emacs
graphics/jpeg editors/emacs
graphics/libungif editors/emacs
graphics/png editors/emacs
graphics/tiff editors/emacs
lang/perl5 editors/emacs
pkgtools/x11-links editors/emacs
sysutils/checkperms editors/emacs
sysutils/checkperms wip/distbb
wip/paexec wip/distbb
wip/pkg_summary-utils wip/distbb
wip/runawk wip/distbb
'

pkg_summary2deps -dp -N 'distbb-0.22.0 emacs-22.1nb6' src_summary.txt | sort |
cmp 'pkg_summary2deps #40' \
'graphics/jpeg editors/emacs
graphics/libungif editors/emacs
graphics/png editors/emacs
graphics/tiff editors/emacs
lang/perl5 editors/emacs
wip/paexec wip/distbb
wip/pkg_summary-utils wip/distbb
wip/runawk wip/distbb
'

echo distbb-0.22.0 > "$tmpfn4"
echo emacs-22.1nb6 >> "$tmpfn4"
pkg_summary2deps -dp -N "$tmpfn4" src_summary.txt | sort |
cmp 'pkg_summary2deps #40.1' \
'graphics/jpeg editors/emacs
graphics/libungif editors/emacs
graphics/png editors/emacs
graphics/tiff editors/emacs
lang/perl5 editors/emacs
wip/paexec wip/distbb
wip/pkg_summary-utils wip/distbb
wip/runawk wip/distbb
'

pkg_summary2deps -dn bin_summary5.txt | sort |
cmp 'pkg_summary2deps #41' \
'php php-extensions
php php5-exif
php php53-exif
php5-exif php-extensions
php53-exif php-extensions
'

pkg_summary2deps -dnr bin_summary5.txt | sort |
cmp 'pkg_summary2deps #42' \
'php-5.2.17
php-5.2.17nb2
php-5.3.5
php-5.3.5nb1 php-extensions-5.2.17
php-5.3.5nb1 php-extensions-5.3.5
php-5.3.5nb1 php5-exif-5.2.17
php-5.3.5nb1 php5-exif-5.2.17nb2
php-5.3.5nb1 php53-exif-5.3.5
php-5.3.5nb1 php53-exif-5.3.5nb2
php5-exif-5.2.17nb2 php-extensions-5.2.17
php53-exif-5.3.5nb2 php-extensions-5.3.5
'

pkg_summary2deps -dnrs bin_summary5.txt | sort |
cmp 'pkg_summary2deps #42.1' \
'php-5.2.17
php-5.2.17nb2 php-extensions-5.2.17
php-5.2.17nb2 php5-exif-5.2.17
php-5.2.17nb2 php5-exif-5.2.17nb2
php-5.3.5
php-5.3.5nb1 php-extensions-5.3.5
php-5.3.5nb1 php53-exif-5.3.5
php-5.3.5nb1 php53-exif-5.3.5nb2
php5-exif-5.2.17nb2 php-extensions-5.2.17
php53-exif-5.3.5nb2 php-extensions-5.3.5
'

pkg_summary2deps -dnra bin_summary5.txt | sort |
cmp 'pkg_summary2deps #43' \
'php-5.2.17|php-5.2.17nb2|php-5.3.5|php-5.3.5nb1 php-extensions-5.2.17
php-5.2.17|php-5.2.17nb2|php-5.3.5|php-5.3.5nb1 php-extensions-5.3.5
php-5.2.17|php-5.2.17nb2|php-5.3.5|php-5.3.5nb1 php5-exif-5.2.17
php-5.2.17|php-5.2.17nb2|php-5.3.5|php-5.3.5nb1 php5-exif-5.2.17nb2
php-5.2.17|php-5.2.17nb2|php-5.3.5|php-5.3.5nb1 php53-exif-5.3.5
php-5.2.17|php-5.2.17nb2|php-5.3.5|php-5.3.5nb1 php53-exif-5.3.5nb2
php5-exif-5.2.17|php5-exif-5.2.17nb2 php-extensions-5.2.17
php53-exif-5.3.5|php53-exif-5.3.5nb2 php-extensions-5.3.5
'

pkg_summary2deps -dnras bin_summary5.txt | sort |
cmp 'pkg_summary2deps #43.1' \
'php-5.2.17|php-5.2.17nb2 php-extensions-5.2.17
php-5.2.17|php-5.2.17nb2 php5-exif-5.2.17
php-5.2.17|php-5.2.17nb2 php5-exif-5.2.17nb2
php-5.3.5|php-5.3.5nb1 php-extensions-5.3.5
php-5.3.5|php-5.3.5nb1 php53-exif-5.3.5
php-5.3.5|php-5.3.5nb1 php53-exif-5.3.5nb2
php5-exif-5.2.17|php5-exif-5.2.17nb2 php-extensions-5.2.17
php53-exif-5.3.5|php53-exif-5.3.5nb2 php-extensions-5.3.5
'

pkg_summary2deps -dpnra bin_summary5.txt | sort |
cmp 'pkg_summary2deps #44' \
'graphics/php-exif;php5-exif-5.2.17|graphics/php-exif;php5-exif-5.2.17nb2 meta-pkgs/php5-extensions;php-extensions-5.2.17
graphics/php-exif;php53-exif-5.3.5|graphics/php-exif;php53-exif-5.3.5nb2 meta-pkgs/php53-extensions;php-extensions-5.3.5
lang/php5;php-5.2.17|lang/php5;php-5.2.17nb2|lang/php53;php-5.3.5|lang/php53;php-5.3.5nb1 graphics/php-exif;php5-exif-5.2.17
lang/php5;php-5.2.17|lang/php5;php-5.2.17nb2|lang/php53;php-5.3.5|lang/php53;php-5.3.5nb1 graphics/php-exif;php5-exif-5.2.17nb2
lang/php5;php-5.2.17|lang/php5;php-5.2.17nb2|lang/php53;php-5.3.5|lang/php53;php-5.3.5nb1 graphics/php-exif;php53-exif-5.3.5
lang/php5;php-5.2.17|lang/php5;php-5.2.17nb2|lang/php53;php-5.3.5|lang/php53;php-5.3.5nb1 graphics/php-exif;php53-exif-5.3.5nb2
lang/php5;php-5.2.17|lang/php5;php-5.2.17nb2|lang/php53;php-5.3.5|lang/php53;php-5.3.5nb1 meta-pkgs/php5-extensions;php-extensions-5.2.17
lang/php5;php-5.2.17|lang/php5;php-5.2.17nb2|lang/php53;php-5.3.5|lang/php53;php-5.3.5nb1 meta-pkgs/php53-extensions;php-extensions-5.3.5
'

pkg_summary2deps -dpnras bin_summary5.txt | sort |
cmp 'pkg_summary2deps #44.1' \
'graphics/php-exif;php5-exif-5.2.17|graphics/php-exif;php5-exif-5.2.17nb2 meta-pkgs/php5-extensions;php-extensions-5.2.17
graphics/php-exif;php53-exif-5.3.5|graphics/php-exif;php53-exif-5.3.5nb2 meta-pkgs/php53-extensions;php-extensions-5.3.5
lang/php53;php-5.3.5|lang/php53;php-5.3.5nb1 graphics/php-exif;php53-exif-5.3.5
lang/php53;php-5.3.5|lang/php53;php-5.3.5nb1 graphics/php-exif;php53-exif-5.3.5nb2
lang/php53;php-5.3.5|lang/php53;php-5.3.5nb1 meta-pkgs/php53-extensions;php-extensions-5.3.5
lang/php5;php-5.2.17|lang/php5;php-5.2.17nb2 graphics/php-exif;php5-exif-5.2.17
lang/php5;php-5.2.17|lang/php5;php-5.2.17nb2 graphics/php-exif;php5-exif-5.2.17nb2
lang/php5;php-5.2.17|lang/php5;php-5.2.17nb2 meta-pkgs/php5-extensions;php-extensions-5.2.17
'

pkg_summary2deps -dpa bin_summary5.txt | sort |
cmp 'pkg_summary2deps #45' \
'graphics/php-exif|graphics/php-exif meta-pkgs/php5-extensions
graphics/php-exif|graphics/php-exif meta-pkgs/php53-extensions
lang/php5|lang/php5|lang/php53|lang/php53 graphics/php-exif
lang/php5|lang/php5|lang/php53|lang/php53 meta-pkgs/php5-extensions
lang/php5|lang/php5|lang/php53|lang/php53 meta-pkgs/php53-extensions
'

pkg_summary2deps -dpas bin_summary5.txt | sort |
cmp 'pkg_summary2deps #45.1' \
'graphics/php-exif|graphics/php-exif meta-pkgs/php5-extensions
graphics/php-exif|graphics/php-exif meta-pkgs/php53-extensions
lang/php53|lang/php53 graphics/php-exif
lang/php53|lang/php53 meta-pkgs/php53-extensions
lang/php5|lang/php5 graphics/php-exif
lang/php5|lang/php5 meta-pkgs/php5-extensions
'

pkg_summary2deps -dpa bin_summary6.txt 2>/dev/null | sort -k2 -k1 |
cmp 'pkg_summary2deps #46' \
'lang/ruby18-base lang/ruby
security/openssl lang/ruby
lang/ruby18-base lang/ruby18
security/openssl lang/ruby18
security/openssl lang/ruby18-base
lang/ruby19-base lang/ruby19
security/openssl lang/ruby19
security/openssl lang/ruby19-base
lang/ruby19-base lang/ruby:RUBY_VERSION_REQD=19
security/openssl lang/ruby:RUBY_VERSION_REQD=19
lang/ruby18-base textproc/ruby-eruby
security/openssl textproc/ruby-eruby
lang/ruby18-base www/ap-ruby
security/openssl www/ap-ruby
textproc/ruby-eruby www/ap-ruby
www/apache|www/apache2|www/apache22 www/ap-ruby
lang/ruby18-base www/ap-ruby:PKG_APACHE=apache13
security/openssl www/ap-ruby:PKG_APACHE=apache13
textproc/ruby-eruby www/ap-ruby:PKG_APACHE=apache13
www/apache|www/apache2|www/apache22 www/ap-ruby:PKG_APACHE=apache13
lang/ruby18-base www/ap-ruby:PKG_APACHE=apache2
security/openssl www/ap-ruby:PKG_APACHE=apache2
textproc/ruby-eruby www/ap-ruby:PKG_APACHE=apache2
www/apache|www/apache2|www/apache22 www/ap-ruby:PKG_APACHE=apache2
security/openssl www/apache2
security/openssl www/apache22
x11/qt3-docs x11/qt3
x11/qt3-libs x11/qt3
x11/qt3-tools x11/qt3
x11/qt3-libs x11/qt3-docs
x11/qt3-libs x11/qt3-mysql
x11/qt3-libs x11/qt3-pgsql
x11/qt3-libs x11/qt3-qscintilla
x11/qt3-libs x11/qt3-tools
x11/qt4-docs x11/qt4
x11/qt4-libs x11/qt4
x11/qt4-tools x11/qt4
x11/qt4-libs x11/qt4-docs
x11/qt4-libs x11/qt4-mng
x11/qt4-libs x11/qt4-mysql
x11/qt4-libs x11/qt4-pgsql
x11/qt4-libs x11/qt4-qdbus
x11/qt4-libs x11/qt4-qscintilla
x11/qt4-libs x11/qt4-sqlite3
x11/qt4-libs x11/qt4-tiff
x11/qt4-libs x11/qt4-tools
'

pkg_summary2deps -dpas bin_summary6.txt 2>/dev/null | sort -k2 -k1 |
cmp 'pkg_summary2deps #46.1' \
'lang/ruby18-base lang/ruby
security/openssl lang/ruby
lang/ruby18-base lang/ruby18
security/openssl lang/ruby18
security/openssl lang/ruby18-base
lang/ruby19-base lang/ruby19
security/openssl lang/ruby19
security/openssl lang/ruby19-base
lang/ruby19-base lang/ruby:RUBY_VERSION_REQD=19
security/openssl lang/ruby:RUBY_VERSION_REQD=19
lang/ruby18-base textproc/ruby-eruby
security/openssl textproc/ruby-eruby
lang/ruby18-base www/ap-ruby
security/openssl www/ap-ruby
textproc/ruby-eruby www/ap-ruby
www/apache22 www/ap-ruby
lang/ruby18-base www/ap-ruby:PKG_APACHE=apache13
security/openssl www/ap-ruby:PKG_APACHE=apache13
textproc/ruby-eruby www/ap-ruby:PKG_APACHE=apache13
www/apache www/ap-ruby:PKG_APACHE=apache13
lang/ruby18-base www/ap-ruby:PKG_APACHE=apache2
security/openssl www/ap-ruby:PKG_APACHE=apache2
textproc/ruby-eruby www/ap-ruby:PKG_APACHE=apache2
www/apache2 www/ap-ruby:PKG_APACHE=apache2
security/openssl www/apache2
security/openssl www/apache22
x11/qt3-docs x11/qt3
x11/qt3-libs x11/qt3
x11/qt3-tools x11/qt3
x11/qt3-libs x11/qt3-docs
x11/qt3-libs x11/qt3-mysql
x11/qt3-libs x11/qt3-pgsql
x11/qt3-libs x11/qt3-qscintilla
x11/qt3-libs x11/qt3-tools
x11/qt4-docs x11/qt4
x11/qt4-libs x11/qt4
x11/qt4-tools x11/qt4
x11/qt4-libs x11/qt4-docs
x11/qt4-libs x11/qt4-mng
x11/qt4-libs x11/qt4-mysql
x11/qt4-libs x11/qt4-pgsql
x11/qt4-libs x11/qt4-qdbus
x11/qt4-libs x11/qt4-qscintilla
x11/qt4-libs x11/qt4-sqlite3
x11/qt4-libs x11/qt4-tiff
x11/qt4-libs x11/qt4-tools
'

pkg_summary2deps -dp bin_summary11.txt | sort -k1 -k2 |
cmp 'pkg_summary2deps #47.1' \
'multimedia/farsight2 chat/pidgin
x11/py-gtk2 multimedia/farsight2
'

pkg_summary2deps -dn bin_summary11.txt | sort -k1 -k2 |
cmp 'pkg_summary2deps #47.2' \
'farsight2 pidgin
py26-gtk2
py27-gtk2 farsight2
'

pkg_summary2deps -dnr bin_summary11.txt | sort -k1 -k2 |
cmp 'pkg_summary2deps #47.3' \
'farsight2-0.0.26nb6 pidgin-2.10.3
py26-gtk2-2.24.0nb4
py27-gtk2-2.24.0nb4 farsight2-0.0.26nb6
'

pkg_summary2deps -dpnr bin_summary11.txt | sort -k1 -k2 |
cmp 'pkg_summary2deps #47.3' \
'multimedia/farsight2;farsight2-0.0.26nb6 chat/pidgin;pidgin-2.10.3
x11/py-gtk2;py26-gtk2-2.24.0nb4
x11/py-gtk2;py27-gtk2-2.24.0nb4 multimedia/farsight2;farsight2-0.0.26nb6
'

pkg_summary2deps -dpn bin_summary11.txt | sort -k1 -k2 |
cmp 'pkg_summary2deps #47.3' \
'multimedia/farsight2;farsight2 chat/pidgin;pidgin
x11/py-gtk2;py26-gtk2
x11/py-gtk2;py27-gtk2 multimedia/farsight2;farsight2
'

pkg_summary2deps -Aps2 src_summary15.txt | sort -k1 -k2 |
cmp 'pkg_summary2deps #48' \
'BUILD_DEPENDS lang/perl5 devel/p5-Parse-CPAN-Meta
DEPENDS devel/p5-CPAN-Meta devel/p5-ExtUtils-MakeMaker
DEPENDS devel/p5-CPAN-Meta-YAML devel/p5-Parse-CPAN-Meta
DEPENDS devel/p5-Parse-CPAN-Meta devel/p5-CPAN-Meta
'

pkg_summary2deps -Aps2 src_summary16.txt | sort -k1 -k2 |
cmp 'pkg_summary2deps #49' \
'DEPENDS devel/CCC devel/AAA
DEPENDS devel/EEE devel/AAA
devel/DDD
'
