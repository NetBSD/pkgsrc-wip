# $NetBSD: Makefile,v 1.5 2014/10/20 09:49:29 noud4 Exp $

DISTNAME=	bitcoin-0.8.6-linux
PKGREVISION=	2
PKGNAME=	${DISTNAME:S|-linux||}
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bitcoin/}

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://bitcoin.sourceforge.net/
COMMENT=	P2P electronic cash system
LICENSE=	mit

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c++
WRKSRC=		${WRKDIR}/${DISTNAME}/src
AUTO_MKDIRS=	yes	# XXX

CXXFLAGS+=	-std=c++0x

QMAKE_OPTIONS+=	BOOST_INCLUDE_PATH=${PREFIX}/include/boost
QMAKE_OPTIONS+=	BDB_INCLUDE_PATH=${PREFIX}/include/db4
QMAKE_OPTIONS+=	OPENSSL_INCLUDE_PATH=${PREFIX}/include/openssl

QMAKE_OPTIONS+=	BOOST_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	BDB_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	OPENSSL_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	LIB_RPATH=${PREFIX}/lib

RCD_SCRIPTS=	bitcoind
OWN_DIRS=	${VARBASE}/bitcoin
EGDIR=		${PREFIX}/share/examples/bitcoin
CONF_FILES=	${EGDIR}/bitcoin.conf ${PKG_SYSCONFDIR}/bitcoin.conf
CONF_FILES_PERMS=	${EGDIR}/bitcoin.conf ${PKG_SYSCONFDIR}/bitcoin.conf ${ROOT_USER} ${ROOT_GROUP} 0600

SUBST_CLASSES+= 	pkg
SUBST_STAGE.pkg= 	post-patch
SUBST_FILES.pkg+=	src/contrib/debian/bitcoin-qt.desktop
SUBST_SED.pkg=		-e "s|/usr/|${PREFIX}/|g"
SUBST_MESSAGE.pkg=	"Fixing dirs."

do-configure:
	(cd ${WRKSRC} && env ${CONFIGURE_ENV} ${QTDIR}/bin/qmake "PREFIX=${PREFIX}" "QMAKE_CXXFLAGS=${CXXFLAGS}" ${QMAKE_OPTIONS} bitcoin-qt.pro)

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE_OPTIONS} ${GMAKE};	\
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} CFLAGS+=-Iobj ${QMAKE_OPTIONS} ${GMAKE} -f makefile.unix

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/bin
	${MKDIR} ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/bitcoin-qt ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/bitcoind ${DESTDIR}${PREFIX}/sbin
	${MKDIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} -m 600 ${FILESDIR}/bitcoin.conf ${DESTDIR}${EGDIR}
	${MKDIR} ${DESTDIR}${PREFIX}/share/pixmaps
	${MKDIR} ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} -m 600 ${WRKSRC}/share/pixmaps/bitcoin128.png ${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} -m 600 ${WRKSRC}/contrib/debian/bitcoin-qt.desktop ${DESTDIR}${PREFIX}/share/applications/

.include "options.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
