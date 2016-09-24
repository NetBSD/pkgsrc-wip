# $NetBSD: Makefile,v 1.1 2014/09/22 11:17:11 othyro Exp $

DISTNAME=	darkcoin-0.9.12.32
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=darkcoinproject/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@users.sourceforge.net
HOMEPAGE=	http://www.darkcoin.io/
COMMENT=	Secure, decentralized, and anonymous digital currency
LICENSE=	mit

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
AUTO_MKDIRS=	yes

CXXFLAGS+=	-std=c++0x

QMAKE_OPTIONS+=	BOOST_INCLUDE_PATH=${PREFIX}/include/boost
QMAKE_OPTIONS+=	BDB_INCLUDE_PATH=${PREFIX}/include/db4
QMAKE_OPTIONS+=	OPENSSL_INCLUDE_PATH=${PREFIX}/include/openssl

QMAKE_OPTIONS+=	BOOST_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	BDB_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	OPENSSL_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	LIB_RPATH=${PREFIX}/lib

RCD_SCRIPTS=	darkcoind
OWN_DIRS=	${VARBASE}/darkcoin
EGDIR=		${PREFIX}/share/examples/darkcoin
CONF_FILES=	${EGDIR}/darkcoin.conf ${PKG_SYSCONFDIR}/darkcoin.conf
CONF_FILES_PERMS=	${EGDIR}/darkcoin.conf ${PKG_SYSCONFDIR}/darkcoin.conf ${ROOT_USER} ${ROOT_GROUP} 0600
INSTALLATION_DIRS+=	share/examples/darkcoin

do-configure:
	(cd ${WRKSRC} && env ${CONFIGURE_ENV} ${QTDIR}/bin/qmake "PREFIX=${PREFIX}" "QMAKE_CXXFLAGS=${CXXFLAGS}" ${QMAKE_OPTIONS} bitcoin-qt.pro)

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE_OPTIONS} ${GMAKE};	\
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} CFLAGS+=-Iobj ${QMAKE_OPTIONS} ${GMAKE} -f makefile.unix

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/darkcoin-qt ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/darkcoind ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} -m 600 ${FILESDIR}/darkcoin.conf ${DESTDIR}${EGDIR}

.include "options.mk"

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
