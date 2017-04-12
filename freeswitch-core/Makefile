# $NetBSD: Makefile,v 1.1 2014/08/07 17:40:11 darcycain Exp $

DISTNAME=	freeswitch-${VERSION}
PKGNAME=	freeswitch-core-${VERSION}
VERSION=	1.6.5
CATEGORIES=	net
MASTER_SITES=	http://files.freeswitch.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://www.freeswitch.org/
COMMENT=	FreeSwitch SoftSwitch Port
LICENSE=	mpl-1.1

#DEPENDS+=	flite>=1.3.0:../../audio/flite

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++ fortran
USE_TOOLS+=	automake autoconf gmake perl pkg-config libtool
ONLY_FOR_COMPILER=	gcc
#GCC_REQD+=		4.9

PTLIB_CFLAGS+=          -I${BUILDLINK_PREFIX.ptlib}/share/ptlib/
MP4V2_CFLAGS+=		-c -Wall -I${BUILDLINK_PREFIX.mp4v2}/include/mp4v2
DATADIR=		${VARBASE}/db/freeswitch
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--bindir=${PREFIX}/bin
CONFIGURE_ARGS+=	--datadir=${DATADIR}
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/freeswitch
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/freeswitch/lib
CONFIGURE_ARGS+=	--localstatedir=/var
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc/freeswitch/conf
CONFIGURE_ARGS+=	--with-htdocsdir=${PREFIX}/share/doc/html/freeswitch/htdocs
CONFIGURE_ARGS+=	--with-soundsdir=${PREFIX}/share/freeswitch/sounds
CONFIGURE_ARGS+=	--with-grammardir=${PREFIX}/etc/freeswitch/grammar
CONFIGURE_ARGS+=	--with-scriptdir=${PREFIX}/etc/freeswitch/scripts
CONFIGURE_ARGS+=	--with-modinstdir=${PREFIX}/lib/freeswitch/mod
CONFIGURE_ARGS+=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
CONFIGURE_ARGS+=	--with-storagedir=/var/freeswitch
CONFIGURE_ARGS+=	--with-recordingsdir=/var/freeswitch/recordings
CONFIGURE_ARGS+=	--with-memcached=yes	
CONFIGURE_ARGS+=	--with-memcached=${PREFIX}
CONFIGURE_ARGS+=	--with-memcached-libraries=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-memcached-includes=${PREFIX}/include
CONFIGURE_ARGS+=	--with-ogg=${PREFIX}
CONFIGURE_ARGS+=	--with-ogg-libraries=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-ogg-includes=${PREFIX}/include
#CONFIGURE_ARGS+=	--disable-core-libedit-support
CONFIGURE_ARGS+=	--with-libedit=${BUILDLINK_PREFIX.editline}
CONFIGURE_ARGS+=	--enable-system-xmlrpc-c --enable-zrtp
CONFIGURE_ARGS+=	--enable-core-pgsql-support

ETCDIR=			${PREFIX}/etc/freeswitch
WWWDIR=			${PREFIX}/www/freeswitch

.include "../../mk/bsd.prefs.mk"
#.include "../../wip/freeswitch-core/options.mk"

CFLAGS+=		-I${BUILDLINK_PREFIX.sofia-sip}/include/sofia-sip-1.12
CFLAGS+=		-I${BUILDLINK_PREFIX.srtp}/include/srtp
CFLAGS+=		-I${BUILDLINK_PREFIX.mp4v2}/include/mp4v2
CFLAGS+=		-I${BUILDLINK_PREFIX.flite}/include/flite
CFLAGS+=		-I${PREFIX}/include/flite
FLITE_LIBS+=		-I${BUILDLINK_PREFIX.flite}/include/flite
FLITE_LIBS+=		-I${PREFIX}/include/flite
FLITE_CFLAGS+=		-I${BUILDLINK_PREFIX.flite}/include/flite -L${BUILDLINK_PREFIX.flite}/include/flite
FLITE_CFLAGS+=		-I${PREFIX}/include/flite -L${PREFIX}/include/flite
CXXFLAGS+=		-I${BUILDLINK_PREFIX.flite}/include/flite -L${BUILDLINK_PREFIX.flite}/include/flite
CXXFLAGS+=		-I${PREFIX}/include/flite -L${PREFIX}/include/flite

BUILDLINK_TRANSFORM+=	rm:-Werror
LDFLAGS+=		-Wl,-R${BUILDLINK_PREFIX.srtp}/lib
LDFLAGS+=		-Wl,-L${BUILDLINK_PREFIX.srtp}/lib
INSTALLATION_DIRS+=	lib/freeswitch/mod ${DATADIR}/sounds

RCD_SCRIPTS=            freeswitch
RCD_SCRIPT_SRC.bitlbee= ${FILESDIR}/freeswitch.in

#post-extract:
	#${RM} -rf ${WRKSRC}/libs/js
	#${RM} -rf ${WRKSRC}/libs/xmlrpc-c
	#${RM} -rf ${WRKSRC}/libs/win32/xmlrpc-c
	#${RM} -rf ${WRKSRC}/src/mod/languages/mod_spidermonkey
	#${RM} -rf ${WRKSRC}/src/mod/xml_int/mod_xml_rpc
	#${RM} -rf ${WRKSRC}/w32
	#${RM} -rf ${WRKSRC}/conf/curl/autoload_configs/spidermonkey.conf.xml
	#${RM} -rf ${WRKSRC}/conf/vanilla/autoload_configs/spidermonkey.conf.xml
	#${RM} -rf ${WRKSRC}/conf/insideout/autoload_configs/spidermonkey.conf.xml

#pre-install:
	#${CHMOD} 664 ${WRKSRC}/libs/freetdm/conf/*
	#${MKDIR} ${ETCDIR}/conf

post-install:
	#${SETENV} PKG_PREFIX=${PREFIX} 
	    #${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	#${CHOWN} -R ${USERS}:${GROUPS} ${ETCDIR} ${DATADIR} \
		#${PREFIX}/include/freeswitch 
		#${PREFIX}/lib/freeswitch
	#${FIND} ${ETCDIR} -type d | ${XARGS} ${CHMOD} 770
	#${CHMOD} -R 770 ${DATADIR}
	#${FIND} ${ETCDIR} ${WWWDIR} -type f | ${XARGS} ${CHMOD} 660

# libtpl : https://github.com/troydhanson/tpl/releases
.include "../../comms/spandsp/buildlink3.mk"
# iksemel
.include "../../textproc/iksemel/buildlink3.mk"
.include "../../devel/sofia-sip/buildlink3.mk"
# unimrcp : https://github.com/unispeech/unimrcp/releases
# libwat : no releases
.include "../../devel/check/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
#.include "../../graphics/tiff/buildlink3.mk"
.include "../../comms/srtp/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../lang/erlang/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
# php
# java
.include "../../security/openssl/buildlink3.mk"
# ldap
# libsmpp : http://cgit.osmocom.org/libsmpp34/
# hiredis
# libedit
.include "../../devel/editline/buildlink3.mk"
# tap
#pgsql
.include "../../mk/pgsql.buildlink3.mk"
# libtool-fortran
.include "../../mk/bsd.pkg.use.mk"
# librmq
# flite
.include "../../audio/flite/buildlink3.mk"
# libmemcached
.include "../../devel/libmemcached/buildlink3.mk"
# mongo
.include "../../audio/soundtouch/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
# codec2
.include "../../ham/codec2/buildlink3.mk"
# package g722
.include "../../wip/libilbc/buildlink3.mk"
# broadvoice
# Package silk : https://tools.netsa.cert.org/silk/download.html
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/opencv/buildlink3.mk"
#.include "../../multimedia/vlc21/buildlink3.mk"
.include "../../multimedia/ffmpeg2/buildlink3.mk"
#lame
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libshout/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../net/ldns/buildlink3.mk"
.include "../../audio/portaudio-devel/buildlink3.mk"
#.include "../../textproc/xmlrpc-c/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
# alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/resolv.buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
#.include "../../devel/apr-util/buildlink3.mk"
#.include "../../devel/apr/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/libwww/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
