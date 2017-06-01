# $NetBSD$

DISTNAME=       freeswitch-${VERSION}
VERSION=        1.6.17
CATEGORIES=     net
MASTER_SITES=   http://files.freeswitch.org/
EXTRACT_SUFX=   .tar.xz

MAINTAINER=     pkgsrc-users@NetBSD.org
HOMEPAGE=       http://www.freeswitch.org/
COMMENT=        FreeSwitch SoftSwitch Port
LICENSE=        mpl-1.1

GNU_CONFIGURE=  	yes
USE_LIBTOOL=    	yes
LIBTOOL_OVERRIDE=	libtool */libtool */*/libtool */*/*/libtool
USE_LANGUAGES=  	c c++
USE_TOOLS+=     	automake autoconf gmake perl pkg-config

BUILD_DEFS+=		VARBASE FREESWITCH_CONFDIR FREESWITCH_DATADIR FREESWITCH_SHAREDIR

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/bin
CONFIGURE_ARGS+=	--bindir=${PREFIX}/bin
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/db/freeswitch
CONFIGURE_ARGS+= 	--datarootdir=${PREFIX}/share
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
CONFIGURE_ARGS+=	--disable-libvpx
CONFIGURE_ARGS+=	--enable-srtp
CONFIGURE_ARGS+=	--enable-zrtp
CONFIGURE_ARGS+=	--enable-core-pgsql-support
CONFIGURE_ARGS+=	--enable-xmlrpc-c

REPLACE_PERL+=	support-d/utils/filebug.pl
REPLACE_PERL+=	support-d/utils/gl
REPLACE_PERL+=	support-d/utils/hashfinder
REPLACE_PERL+=	support-d/utils/rwlock.pl
REPLACE_PERL+=	support-d/utils/fixbug.pl
REPLACE_PERL+=	support-d/utils/btgrep
REPLACE_PERL+=	build/strip.pl
REPLACE_PERL+=	libs/xmlrpc-c/tools/binmode-rpc-kit/binmode-rpc2xml-rpc
REPLACE_PERL+=	libs/xmlrpc-c/tools/binmode-rpc-kit/oct2bin
REPLACE_PERL+=	libs/apr/helpers/apr_rename.pl
REPLACE_PERL+=	libs/sofia-sip/libsofia-sip-ua/tport/make_node_cert.pl
REPLACE_PERL+=	libs/sofia-sip/libsofia-sip-ua/tport/make_root_cert.pl
REPLACE_PERL+=	libs/libzrtp/create_pack.pl
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tplfmt
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tplxml
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/test13
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/test6
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/test9
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/test12
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/test2
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/test21
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/test16
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/test8
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/test22
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/test14
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/test4
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/test7
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/test15
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/test18
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/test1
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/do_tests
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/test20
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/test23
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/test11
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/test10
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/client.pl
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/test3
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/test19
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/test5
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/server.pl
REPLACE_PERL+=	libs/libtpl-1.5/lang/perl/tests/test17
REPLACE_PERL+=	libs/libtpl-1.5/tests/other/do_tests
REPLACE_PERL+=	libs/libtpl-1.5/tests/sizes
REPLACE_PERL+=	libs/libtpl-1.5/tests/do_tests
REPLACE_PERL+=	libs/libtpl-1.5/tests/do_tests.cygwin
REPLACE_PERL+=	libs/libtpl-1.5/doc/txt/perl.txt
REPLACE_PERL+=	libs/libtpl-1.5/doc/txt/perl.txt
REPLACE_PERL+=	libs/libtpl-1.5/doc/txt/perl.txt
REPLACE_PERL+=	libs/libtpl-1.5/doc/txt/perl.txt
REPLACE_PERL+=	libs/libtpl-1.5/doc/txt/perl.txt
REPLACE_PERL+=	libs/libtpl-1.5/doc/html/perl.html
REPLACE_PERL+=	libs/libtpl-1.5/doc/html/perl.html
REPLACE_PERL+=	libs/libtpl-1.5/doc/html/perl.html
REPLACE_PERL+=	libs/libtpl-1.5/doc/html/perl.html
REPLACE_PERL+=	libs/libtpl-1.5/doc/html/perl.html
REPLACE_PERL+=	libs/esl/test.pl
REPLACE_PERL+=	libs/esl/perl/send_notify.pl
REPLACE_PERL+=	libs/esl/perl/single_command.pl
REPLACE_PERL+=	libs/esl/perl/dump_events.pl
REPLACE_PERL+=	libs/esl/perl/info.pl
REPLACE_PERL+=	libs/esl/perl/sendevent.pl
REPLACE_PERL+=	libs/esl/perl/send_info.pl
REPLACE_PERL+=	libs/esl/perl/dispatch.pl
REPLACE_PERL+=	scripts/rss/rss2ivr.pl
REPLACE_PERL+=	scripts/rss/syncrss.pl
REPLACE_PERL+=	scripts/fsxs.in
REPLACE_PERL+=	scripts/perl/mkgws.pl
REPLACE_PERL+=	scripts/perl/fslog
REPLACE_PERL+=	scripts/perl/wplookup.cgi
REPLACE_PERL+=	scripts/perl/analyze-debug-alloc.pl
REPLACE_PERL+=	scripts/perl/cnam.cgi
REPLACE_PERL+=	scripts/perl/call.cgi
REPLACE_PERL+=	scripts/perl/timezone-gen.pl
REPLACE_PERL+=	scripts/perl/f-off-friendly-scanner.pl
REPLACE_PERL+=	scripts/perl/sock.pl
REPLACE_PERL+=	scripts/perl/sendmail
REPLACE_PERL+=	scripts/perl/honeypot.pl
REPLACE_PERL+=	scripts/perl/randomize-passwords.pl
REPLACE_PERL+=	scripts/perl/add_user
REPLACE_PERL+=	scripts/perl/combineconf.pl
REPLACE_PERL+=	scripts/perl/fsconsole.pl
REPLACE_PERL+=	scripts/perl/multicast/send.pl
REPLACE_PERL+=	scripts/perl/rpc.cgi
REPLACE_PERL+=	scripts/perl/fs.pl
REPLACE_PERL+=	scripts/perl/ftc_dnc_register.pl
REPLACE_PERL+=	scripts/perl/extract_log_range.pl
REPLACE_PERL+=	scripts/perl/blacklist.pl
REPLACE_PERL+=	scripts/perl/POE-Filter-FSSocket/Makefile.PL
REPLACE_PERL+=	scripts/perl/POE-Filter-FSSocket/examples/fsconsole.pl
REPLACE_PERL+=	scripts/perl/POE-Filter-FSSocket/examples/poetest.pl
REPLACE_PERL+=	scripts/perl/POE-Filter-FSSocket/lib/POE/Filter/FSSocket.pm
REPLACE_PERL+=	scripts/perl/tag.pl
REPLACE_PERL+=	scripts/perl/dhcp-inform.pl
REPLACE_PERL+=	scripts/perl/g729_activate
REPLACE_PERL+=	scripts/perl/puppet.cgi
REPLACE_PERL+=	scripts/perl/fax.cgi
REPLACE_PERL+=	scripts/perl/snom-pnpd.pl
REPLACE_PERL+=	scripts/trace/sipgrep
REPLACE_PERL+=	src/mod/applications/mod_httapi/examples/perl/ext_pin.cgi
REPLACE_PERL+=	src/mod/applications/mod_httapi/examples/perl/dialer.cgi
REPLACE_PERL+=	src/mod/applications/mod_httapi/examples/perl/speech.cgi
REPLACE_PERL+=	src/mod/applications/mod_httapi/examples/perl/apps.cgi
REPLACE_PERL+=	src/mod/applications/mod_httapi/examples/perl/record_name.cgi
REPLACE_PERL+=	src/mod/applications/mod_avmd/scripts/avmd_test.pl
REPLACE_PERL+=	src/mod/endpoints/mod_skinny/test-skinny.pl
REPLACE_PERL+=	src/mod/endpoints/mod_skypopen/install/install.pl
REPLACE_PERL+=	src/mod/endpoints/mod_gsmopen/asterisk/ciapalo
REPLACE_PERL+=	docs/phrase/phrase.pl

RCD_SCRIPTS=            freeswitch

INSTALLATION_DIRS+= 	${PREFIX}/freeswitch
INSTALLATION_DIRS+= 	${PREFIX}/freeswitch/modules
INSTALLATION_DIRS+= 	${PREFIX}/freeswitch/sounds
INSTALLATION_DIRS+= 	${PREFIX}/freeswitch/recordings

.include "../../mk/bsd.prefs.mk"

FREESWITCH_USER?=		freeswitch
FREESWITCH_GROUP?=		freeswitch
PKG_GROUPS=			${FREESWITCH_GROUP}
PKG_USERS=			${FREESWITCH_USER}:${FREESWITCH_GROUP}
PKG_GECOS.${FREESWITCH_USER}=	FreeSWITCH
PKG_GROUPS_VARS=		FREESWITCH_GROUP
PKG_USERS_VARS=			FREESWITCH_USER

FREESWITCH_CONFDIR?=	${PREFIX}/etc/freeswitch
FREESWITCH_DATADIR?=	${PREFIX}/freeswitch
FREESWITCH_SHAREDIR?=	${PREFIX}/share/freeswitch

PKG_SYSCONFSUBDIR=      freeswitch
PKG_SYSCONFDIR_PERMS=   ${FREESWITCH_USER} ${FREESWITCH_GROUP} 0755

BUILDLINK_TRANSFORM+= rm:-Werror

post-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libs/srtp/libsrtp.la ${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libs/spandsp/src/libspandsp.la ${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libs/tiff-4.0.2/libtiff/libtiff.la ${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libs/tiff-4.0.2/libtiff/libtiffxx.la ${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --finish ${PREFIX}/lib

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../devel/libmemcached/buildlink3.mk"
.include "../../lang/lua52/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../net/ldns/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
