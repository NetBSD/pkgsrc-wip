# $NetBSD: Makefile,v 1.1 2014/08/07 17:40:11 darcycain Exp $

DISTNAME=	freeswitch-${VERSION}
PKGNAME=	freeswitch-core-${VERSION}
VERSION=	1.2.5
CATEGORIES=	net
MASTER_SITES=	http://files.freeswitch.org/
EXTRACT_SUFX=	.tar.bz2
DIST_SUBDIR=	freeswitch

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://www.freeswitch.org/
COMMENT=	FreeSwitch SoftSwitch Port
LICENSE=	mpl-1.1

USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++ fortran
USE_TOOLS+=		perl automake autoconf
USE_TOOLS+=		gmake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--prefix=${DESTDIR}${PREFIX} \
		--bindir=${DESTDIR}${PREFIX}/bin \
		--datadir=/var/db/freeswitch \
		--includedir=${DESTDIR}${PREFIX}/include/freeswitch \
		--libdir=${DESTDIR}${PREFIX}/lib/freeswitch/lib \
		--localstatedir=/var \
		--sysconfdir=${DESTDIR}${PREFIX}/etc/freeswitch/conf \
		--with-htdocsdir=${DESTDIR}${PREFIX}/www/freeswitch/htdocs \
		--with-soundsdir=${DESTDIR}${PREFIX}/share/freeswitch/sounds \
		--with-grammardir=${DESTDIR}${PREFIX}/etc/freeswitch/grammar \
		--with-scriptdir=${DESTDIR}${PREFIX}/etc/freeswitch/scripts \
		--with-modinstdir=${DESTDIR}${PREFIX}/lib/freeswitch/mod \
		--with-pkgconfigdir=${DESTDIR}${PREFIX}/libdata/pkgconfig \
		--with-storagedir=/var/freeswitch \
		--with-recordingsdir=/var/freeswitch/recordings \
		--with-ogg=${DESTDIR}${PREFIX} \
		--with-ogg-libraries=${DESTDIR}${PREFIX}/lib \
		--with-ogg-includes=${DESTDIR}${PREFIX}/include

ETCDIR=	${PREFIX}/etc/freeswitch
WWWDIR=	${PREFIX}/www/freeswitch

post-extract:
	${RM} -rf ${WRKSRC}/libs/js
	${RM} -rf ${WRKSRC}/libs/xmlrpc-c
	${RM} -rf ${WRKSRC}/libs/win32/xmlrpc-c
	${RM} -rf ${WRKSRC}/src/mod/languages/mod_spidermonkey
	${RM} -rf ${WRKSRC}/src/mod/xml_int/mod_xml_rpc
	${RM} -rf ${WRKSRC}/w32
	${RM} -rf ${WRKSRC}/conf/curl/autoload_configs/spidermonkey.conf.xml
	${RM} -rf ${WRKSRC}/conf/vanilla/autoload_configs/spidermonkey.conf.xml
	${RM} -rf ${WRKSRC}/conf/insideout/autoload_configs/spidermonkey.conf.xml

pre-install:
	${CHMOD} 664 ${WRKSRC}/libs/freetdm/conf/*
	${MKDIR} ${ETCDIR}/conf

post-install:
	${SETENV} PKG_PREFIX=${PREFIX} \
	    ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	${CHOWN} -R ${USERS}:${GROUPS} ${ETCDIR} ${DATADIR} \
		${PREFIX}/include/freeswitch \
		${PREFIX}/lib/freeswitch
	${FIND} ${ETCDIR} -type d | ${XARGS} ${CHMOD} 770
	${MKDIR} ${DATADIR}/sounds
	${CHMOD} -R 770 ${DATADIR}
	${FIND} ${ETCDIR} ${WWWDIR} -type f | ${XARGS} ${CHMOD} 660

.include "../../mk/jpeg.buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/libwww/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
