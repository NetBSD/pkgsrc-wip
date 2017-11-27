# $NetBSD$

DISTNAME=	freeswitch-${VERSION}
VERSION=	1.6.19
CATEGORIES=	net
MASTER_SITES=	http://files.freeswitch.org/releases/freeswitch/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	angelmadames@gmail.com
HOMEPAGE=	http://www.freeswitch.org/
COMMENT=	FreeSwitch SoftSwitch
LICENSE=	mpl-1.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	libtool */libtool */*/libtool */*/*/libtool
USE_LANGUAGES=		c c++
USE_TOOLS+=		aclocal automake autoconf gmake perl pkg-config bash

BUILD_DEFS+=		VARBASE

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/bin
CONFIGURE_ARGS+=	--bindir=${PREFIX}/bin
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/db/freeswitch
CONFIGURE_ARGS+=	--datarootdir=${PREFIX}/share
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--htmldir=${PREFIX}/doc
CONFIGURE_ARGS+=	--dvidir=${PREFIX}/doc
CONFIGURE_ARGS+=	--psdir=${PREFIX}/doc
CONFIGURE_ARGS+=	--with-cachedir=${VARBASE}/cache/freeswitch
CONFIGURE_ARGS+=	--with-storagedir=${VARBASE}/db/freeswitch
CONFIGURE_ARGS+=	--with-rundir=${VARBASE}/run/freeswitch
CONFIGURE_ARGS+=	--with-logfiledir=${VARBASE}/log/freeswitch
CONFIGURE_ARGS+=	--with-dbdir=${VARBASE}/db/freeswitch
CONFIGURE_ARGS+=	--with-imagesdir=${PREFIX}/share/freeswitch/images
CONFIGURE_ARGS+=	--with-recordingsdir=${PREFIX}/freeswitch/recordings
CONFIGURE_ARGS+=	--with-modinstdir=${PREFIX}/freeswitch/modules
CONFIGURE_ARGS+=	--enable-zrtp
CONFIGURE_ARGS+=	--enable-core-pgsql-support
CONFIGURE_ARGS+=	--enable-xmlrpc-c
CONFIGURE_ARGS+=	--enable-64

REPLACE_PERL+=		scripts/rss/*.pl
REPLACE_PERL+=		scripts/perl/*.pl
REPLACE_PERL+=		scripts/perl/*.cgi
REPLACE_PERL+=		scripts/perl/multicast/send.pl
REPLACE_PERL+=		scripts/perl/add_user
REPLACE_PERL+=		scripts/perl/sendmail
REPLACE_PERL+=		scripts/perl/fslog
REPLACE_PERL+=		scripts/perl/g729_activate
REPLACE_PERL+=		scripts/perl/FreeSWITCH/debian/rules
REPLACE_PERL+=		scripts/perl/POE-Filter-FSSocket/lib/POE/Filter/FSSocket.pm
REPLACE_PERL+=		scripts/perl/POE-Filter-FSSocket/examples/*.pl
REPLACE_PERL+=		scripts/perl/POE-Filter-FSSocket/Makefile.PL
REPLACE_PERL+=		scripts/trace/sipgrep
REPLACE_PERL+=		scripts/fsxs.in
REPLACE_PERL+=		support-d/utils/*.pl
REPLACE_PERL+=		support-d/utils/gl
REPLACE_PERL+=		support-d/utils/btgrep
REPLACE_PERL+=		support-d/utils/hashfinder
REPLACE_PERL+=		build/*.pl
REPLACE_PERL+=		docs/phrase/phrase.pl
REPLACE_PERL+=		docs/Doxygen.conf
REPLACE_PERL+=		libs/sofia-sip/utils/Doxyfile.in
REPLACE_PERL+=		libs/sofia-sip/libsofia-sip-ua/tport/*.pl
REPLACE_PERL+=		libs/libzrtp/create_pack.pl
REPLACE_PERL+=		libs/libzrtp/doc/Doxyfile.in
REPLACE_PERL+=		libs/freetdm/docs/Doxygen.conf
REPLACE_PERL+=		libs/libvpx/libs.doxy_template
REPLACE_PERL+=		libs/libg722_1/doc/libg722_1-doxygen
REPLACE_PERL+=		libs/spandsp/doc/doxygen.in
REPLACE_PERL+=		libs/ilbc/doc/libilbc-doxygen
REPLACE_PERL+=		libs/libdingaling/docs/Doxygen.conf
REPLACE_PERL+=		libs/broadvoice/doc/broadvoice-doxygen
REPLACE_PERL+=		libs/xmlrpc-c/tools/binmode-rpc-kit/binmode-rpc2xml-rpc
REPLACE_PERL+=		libs/xmlrpc-c/tools/binmode-rpc-kit/oct2bin
REPLACE_PERL+=		libs/srtp/doc/Doxyfile
REPLACE_PERL+=		libs/esl/test.pl
REPLACE_PERL+=		libs/esl/perl/*.pl
REPLACE_PERL+=		libs/apr/helpers/apr_rename.pl
REPLACE_PERL+=		libs/libtpl-1.5/lang/perl/tests/*
REPLACE_PERL+=		libs/libtpl-1.5/doc/html/*.html
REPLACE_PERL+=		libs/libtpl-1.5/doc/txt/*.txt
REPLACE_PERL+=		libs/libtpl-1.5/tests/other/do_tests
REPLACE_PERL+=		libs/libtpl-1.5/tests/do_tests.cygwin
REPLACE_PERL+=		libs/libtpl-1.5/tests/do_tests
REPLACE_PERL+=		libs/libtpl-1.5/tests/sizes
REPLACE_PERL+=		src/mod/applications/mod_httapi/examples/perl/*.cgi
REPLACE_PERL+=		src/mod/applications/mod_avmd/scripts/*.pl
REPLACE_PERL+=		src/mod/endpoints/mod_skypopen/install/install.pl
REPLACE_PERL+=		src/mod/endpoints/mod_gsmopen/asterisk/ciapalo
REPLACE_PERL+=		src/mod/endpoints/mod_skinny/test-skinny.pl

REPLACE_BASH+=		devel-bootstrap.sh
REPLACE_BASH+=		scripts/*.sh
REPLACE_BASH+=		debian/*.sh
REPLACE_BASH+=		build/*.sh
REPLACE_BASH+=		src/mod/say/mod_say_pl/create_sound_files.sh
REPLACE_BASH+=		src/mod/endpoints/mod_khomp/tools/*.sh
REPLACE_BASH+=		src/mod/endpoints/mod_gsmopen/alsa_nogsmlib_nocplusplus/mod_gsmopen/configs/setmixers
REPLACE_BASH+=		src/mod/endpoints/mod_gsmopen/libctb-0.16/python/src/linux/makepy.sh
REPLACE_BASH+=		src/mod/endpoints/mod_gsmopen/gsmlib/gsmlib-1.10-patched-13ubuntu/contrib/gsmsmsrequeue
REPLACE_BASH+=		src/mod/endpoints/mod_gsmopen/gsmlib/gsmlib-1.10-patched-13ubuntu/contrib/gsmsmsspool
REPLACE_BASH+=		src/mod/endpoints/mod_skypopen/configs/old-stuff/multiple-instance-same-skype-username/multi.sh
REPLACE_BASH+=		build/fs_ivrd.init.redhat
REPLACE_BASH+=		build/freeswitch.init.redhat
REPLACE_BASH+=		build/standalone_module/bootstrap.sh
REPLACE_BASH+=		support-d/utils/pcap-extract.sh
REPLACE_BASH+=		libs/libcodec2/script/menu.sh
REPLACE_BASH+=		libs/libcodec2/unittest/run_tests.sh
REPLACE_BASH+=		libs/libsndfile/src/make-static-lib-hidden-privates.sh
REPLACE_BASH+=		libs/libsndfile/Octave/octave_test.sh
REPLACE_BASH+=		libs/libsndfile/tests/pedantic-header-test.sh.in
REPLACE_BASH+=		libs/libsndfile/Scripts/*.sh
REPLACE_BASH+=		libs/libvpx/tools/author_first_release.sh
REPLACE_BASH+=		libs/libvpx/tools/gen_authors.sh
REPLACE_BASH+=		libs/libvpx/build/make/*.sh
REPLACE_BASH+=		libs/freetdm/mod_freetdm/clean.sh
REPLACE_BASH+=		libs/freetdm/cyginstall.sh
REPLACE_BASH+=		libs/freetdm/mkrelease.sh
REPLACE_BASH+=		libs/libyuv/tools/valgrind-libyuv/libyuv_tests.sh
REPLACE_BASH+=		libs/silk/test_vectors/test_*.sh
REPLACE_BASH+=		html5/verto/verto_communicator/debian8-install.sh
REPLACE_BASH+=		scripts/ci/test_build.sh

RCD_SCRIPTS=		freeswitch

INSTALLATION_DIRS+=	share/freeswitch/scripts
INSTALLATION_DIRS+=	share/freeswitch/grammar
INSTALLATION_DIRS+=	freeswitch/modules
INSTALLATION_DIRS+=	freeswitch/sounds
INSTALLATION_DIRS+=	freeswitch/recordings

CONFLICTS=      	xmlrpc-c-[0-9]*

DEPENDS+=        	flite-[0-9]*:../../audio/flite
DEPENDS+=        	libyaml-[0-9]*:../../textproc/libyaml

.include "../../mk/bsd.prefs.mk"

FS_USER?=		freeswitch
FS_GROUP?=		freeswitch
PKG_USERS_VARS=		FS_USER
PKG_GROUPS_VARS=	FS_GROUP
PKG_GROUPS=		${FS_GROUP}
PKG_USERS=		${FS_USER}:${FS_GROUP}

PKG_GECOS.${FS_USER}=	FreeSWITCH
PKG_SHELL.${FS_USER}=	${NOLOGIN}

MAKE_DIRS+=		${VARBASE}/log/freeswitch
MAKE_DIRS+=		${VARBASE}/db/freeswitch
MAKE_DIRS_PERMS+=	${VARBASE}/log/freeswitch ${FS_USER} ${FS_GROUP} 0644
MAKE_DIRS_PERMS+=	${VARBASE}/db/freeswitch ${FS_USER} ${FS_GROUP} 0755
OWN_DIRS=		${PREFIX}/freeswitch
OWN_DIRS+=		${PREFIX}/share/freeswitch
OWN_DIRS_PERMS+=	${PREFIX}/freeswitch ${FS_USER} ${FS_GROUP} 0755
OWN_DIRS_PERMS+=	${PREFIX}/share/freeswitch ${FS_USER} ${FS_GROUP} 0755

PKG_SYSCONFSUBDIR=	freeswitch
PKG_SYSCONFDIR_PERMS=	${FS_USER} ${FS_GROUP} 0755

BUILDLINK_TRANSFORM+=	rm:-Werror
CFLAGS+=        	-Wno-c11-extensions -Wno-deprecated-declarations \
			-Wno-zero-length-array -Wno-incompatible-pointer-types

post-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libs/srtp/libsrtp.la ${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libs/spandsp/src/libspandsp.la ${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libs/tiff-4.0.2/libtiff/libtiff.la ${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libs/tiff-4.0.2/libtiff/libtiffxx.la ${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --finish ${PREFIX}/lib

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/libmemcached/buildlink3.mk"
.include "../../lang/lua52/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../net/ldns/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
#.include "../../wip/libzrtp/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
