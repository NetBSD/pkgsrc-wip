# $NetBSD$

DISTNAME=       bitcoin-0.11.2
PKGREVISION=    rc1
PKGNAME=        ${DISTNAME}
CATEGORIES=	finance
MASTER_SITES=   ${MASTER_SITE_GITHUB:=bitcoin/}
GITHUB_TAG=     v${PKGVERSION_NOREV}


MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://bitcoin.sourceforge.net/
COMMENT=	P2P electronic cash system
LICENSE=	mit

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config autoconf aclocal autoheader automake libtoolize
USE_LANGUAGES=	c c++
WRKSRC=		${WRKDIR}/${DISTNAME}
AUTO_MKDIRS=	yes
HAS_CONFIGURE=	yes
GNU_CONFIGURE=  yes

CXXFLAGS+=	-std=c++0x -I${BUILDLINK_PREFIX.boost-libs}/include/boost
CXXFLAGS+=	-Wl,-R${BUILDLINK_PREFIX.boost-libs}/lib/bitcoin -L${BUILDLINK_PREFIX.boost-libs}/lib/bitcoin
CFLAGS+=        -fPIC -Wl,-R${BUILDLINK_PREFIX.boost-libs}/lib/bitcoin -L${BUILDLINK_PREFIX.boost-libs}/lib/bitcoin
BOOST_LDFLAGS=  -L${BUILDLINK_PREFIX.boost-libs}/lib
BOOST_CPPFLAGS= -I${BUILDLINK_PREFIX.boost-libs}/include

BUILDLINK_TRANSFORM+=   l:db_cxx:db4_cxx

CPPFLAGS+=-I${BUILDLINK_PREFIX.boost-headers}/include/boost, -Wl,-R${BUILDLINK_PREFIX.boost-libs}/lib/bitcoin
CPPFLAGS+=-L${BUILDLINK_PREFIX.boost-libs}/lib/bitcoin
CONFIGURE_ARGS+=  --with-boost=${BUILDLINK_PREFIX.boost-libs}
#CONFIGURE_ARGS+=  --with-boost=${PREFIX}/include/boost
#CONFIGURE_ARGS+=  --with-boost-libdir=${PREFIX}/lib
CONFIGURE_ARGS+=  --enable-hardening
CONFIGURE_ARGS+=  ${PREFIX}/include/db4

LIBTOOLIZE=     ${PREFIX}/bin/libtoolize

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
#SUBST_FILES.pkg+=	contrib/debian/bitcoin-qt.desktop
SUBST_SED.pkg=		-e "s|/usr/|${PREFIX}/|g"
SUBST_MESSAGE.pkg=	"Fixing dirs."

pre-configure:
#	cd ${WRKDIR}/${DISTNAME}/src && \
#	${SETENV} ${CONFIGURE_ENV} ${CONFIG_SHELL} ../autogen.sh;
#	cd ${WRKDIR}/${DISTNAME}/src;             \
#	${SETENV} ${CONFIGURE_ENV} ${CONFIG_SHELL} ../configure;
	cd ${WRKSRC};             \
        ${LIBTOOLIZE} --force;    \
        ${PREFIX}/bin/aclocal;    \
        ${PREFIX}/bin/autoheader; \
        ${PREFIX}/bin/automake -a --foreign -i  --add-missing; \
        ${PREFIX}/bin/autoconf; \
        ${PREFIX}/bin/autoreconf -i

#do-configure:
#	(cd ${WRKSRC} && env ${CONFIGURE_ENV} ${QTDIR}/bin/qmake "PREFIX=${PREFIX}" "QMAKE_CXXFLAGS=${CXXFLAGS}" ${QMAKE_OPTIONS} bitcoin-qt.pro)
#
#do-build:
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE_OPTIONS} ${GMAKE};	\
#	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} CFLAGS+=-Iobj ${QMAKE_OPTIONS} ${GMAKE} -f makefile.unix
#
#do-install:
#	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/bin
#	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/sbin
#	${INSTALL_PROGRAM} ${WRKSRC}/bitcoin-qt ${DESTDIR}${PREFIX}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/src/bitcoind ${DESTDIR}${PREFIX}/sbin
#	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
#	${INSTALL_DATA} -m 600 ${FILESDIR}/bitcoin.conf ${DESTDIR}${EGDIR}
#	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/pixmaps
#	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/applications
#	${INSTALL_DATA} ${WRKSRC}/share/pixmaps/bitcoin128.png ${DESTDIR}${PREFIX}/share/pixmaps
#	${INSTALL_DATA} ${WRKSRC}/contrib/debian/bitcoin-qt.desktop ${DESTDIR}${PREFIX}/share/applications/
do-install:
#       ${INSTALL_PROGRAM} ${WRKSRC}/bitcoin-qt ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/bitcoin-cli ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/bitcoind ${DESTDIR}${PREFIX}/sbin
	${INSTALL_LIB} -m 644 ${WRKSRC}/src/secp256k1/libsecp256k1.la ${DESTDIR}${PREFIX}/lib/bitcoin
	${INSTALL_LIB} ${WRKSRC}/src/secp256k1/.libs/libsecp256k1.so.0 ${DESTDIR}${PREFIX}/lib/bitcoin
	${LN} -fs ${DESTDIR}${PREFIX}/lib/bitcoin/libsecp256k1.so.0 ${DESTDIR}${PREFIX}/lib/bitcoin/libsecp256k1.so
	${INSTALL_DATA} -m 600 ${FILESDIR}/bitcoin.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/share/pixmaps/bitcoin128.png ${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/contrib/debian/bitcoin-qt.desktop ${DESTDIR}${PREFIX}/share/applications/

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
