# $NetBSD$

DISTNAME=	primecoin-0.1.2-linux
PKGNAME=	${DISTNAME:S/-linux//1}
CATEGORIES=	finance
MASTER_SITES=	http://sourceforge.net/projects/primecoin/files/0.1.2/

MAINTAINER=	pkgsrc-users@users.sourceforge.net
HOMEPAGE=	http://primecoin.io/
COMMENT=	Cryptocurrency based on searching for prime numbers
LICENSE=	mit

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++
WRKSRC=		${WRKDIR}/${DISTNAME}/src
AUTO_MKDIRS=	yes

CXXFLAGS+=	-DBOOST_VARIANT_USE_RELAXED_GET_BY_DEFAULT

QMAKE_OPTIONS+=	BOOST_INCLUDE_PATH=${PREFIX}/include/boost
QMAKE_OPTIONS+=	BDB_INCLUDE_PATH=${PREFIX}/include/db4
QMAKE_OPTIONS+=	OPENSSL_INCLUDE_PATH=${PREFIX}/include/openssl

QMAKE_OPTIONS+=	BOOST_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	BDB_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	OPENSSL_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	LIB_RPATH=${PREFIX}/lib

RCD_SCRIPTS=		primecoind
OWN_DIRS=		${VARBASE}/primecoin
EGDIR=			${PREFIX}/share/examples/primecoin
CONF_FILES=		${EGDIR}/primecoin.conf ${PKG_SYSCONFDIR}/primecoin.conf
CONF_FILES_PERMS=	${EGDIR}/primecoin.conf ${PKG_SYSCONFDIR}/primecoin.conf ${ROOT_USER} ${ROOT_GROUP} 0600
INSTALLATION_DIRS+=	share/examples/primecoin

do-configure:
	(cd ${WRKSRC} && env ${CONFIGURE_ENV} ${QTDIR}/bin/qmake "PREFIX=${PREFIX}" "QMAKE_CXXFLAGS=${CXXFLAGS}" ${QMAKE_OPTIONS} bitcoin-qt.pro)

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE_OPTIONS} ${GMAKE};	\
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} CFLAGS+=-Iobj ${QMAKE_OPTIONS} ${GMAKE} -f makefile.unix

do-install:
#	${INSTALL_PROGRAM} ${WRKSRC}/primecoin-qt ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/primecoind ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} -m 600 ${FILESDIR}/primecoin.conf ${DESTDIR}${EGDIR}

.include "options.mk"

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
