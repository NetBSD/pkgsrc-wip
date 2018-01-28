# $NetBSD$

#DISTNAME=	v0.8.7.2
DISTNAME=	v0.10.2.2
PKGNAME=	litecoin-${DISTNAME:S/v//1}
CATEGORIES=	finance
MASTER_SITES=	https://github.com/litecoin-project/litecoin/archive/

MAINTAINER=	pkgsrc-users@users.sourceforge.net
HOMEPAGE=	http://www.litecoin.org
COMMENT=	Lite version of Bitcoin using scrypt as a proof-of-work algorithm
LICENSE=	mit

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config autoconf aclocal autoheader automake libtoolize
USE_LANGUAGES=	c c++
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
AUTO_MKDIRS=	yes
HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes

CXXFLAGS+=		-I${BUILDLINK_PREFIX.boost-libs}/include/boost
CFLAGS+=		-fPIC
CXXFLAGS+=		-Wl,-R${BUILDLINK_PREFIX.boost-libs}/lib/litecoin -L${BUILDLINK_PREFIX.boost-libs}/lib/litecoin
BUILDLINK_TRANSFORM+=	l:db_cxx:db4_cxx
BOOST_LDFLAGS=		-Wl,-R${BUILDLINK_TRANSFORM.boost-libs}/lib -Wl,-L${BUILDLINK_PREFIX.boost-libs}/lib
#LDFLAGS+=		${BOOST_LDFLAGS:Q}
#LDFLAGS+=		${PREFIX}/qt4/lib
#CPPFLAGS+=		-I${PREFIX}/qt4/include/

CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-libs}
CONFIGURE_ARGS+=	--enable-hardening
CONFIGURE_ARGS+=	${PREFIX}/include/db4 
#CONFIGURE_ARGS+=	--without-gui

LIBTOOLIZE=	${PREFIX}/bin/libtoolize

QMAKE_CXXFLAGS+=	-stdlib=libstdc++

QMAKE_OPTIONS+=	BOOST_INCLUDE_PATH=${PREFIX}/include/boost
QMAKE_OPTIONS+=	BDB_INCLUDE_PATH=${PREFIX}/include/db4
QMAKE_OPTIONS+=	OPENSSL_INCLUDE_PATH=${PREFIX}/include/openssl

QMAKE_OPTIONS+=	BOOST_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	BDB_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	OPENSSL_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	LIB_RPATH=${PREFIX}/lib


RCD_SCRIPTS=		litecoind
OWN_DIRS=		${VARBASE}/litecoin
EGDIR=			${PREFIX}/share/examples/litecoin
CONF_FILES=		${EGDIR}/litecoin.conf ${PKG_SYSCONFDIR}/litecoin.conf
CONF_FILES_PERMS=	${EGDIR}/litecoin.conf ${PKG_SYSCONFDIR}/litecoin.conf ${ROOT_USER} ${ROOT_GROUP} 0600
INSTALLATION_DIRS+=	lib share/examples/litecoin

.include "options.mk"

pre-configure:
#	cd ${WRKSRC}; \
#	aclocal; autoheader; automake -a --foreign -i  --add-missing; autoconf; autoreconf -i
	cd ${WRKSRC};             \
        ${LIBTOOLIZE} --force;    \
        ${PREFIX}/bin/aclocal;    \
        ${PREFIX}/bin/autoheader; \
        ${PREFIX}/bin/automake -a --foreign -i  --add-missing; \
        ${PREFIX}/bin/autoconf; \
        ${PREFIX}/bin/autoreconf -i
#do-configure:
#	#(cd ${WRKSRC} && env ${CONFIGURE_ENV} ${QTDIR}/bin/qmake "PREFIX=${PREFIX}" "QMAKE_CXXFLAGS=${CXXFLAGS}" ${QMAKE_OPTIONS} bitcoin-qt.pro)
#	(cd ${WRKSRC} && env ${CONFIGURE_ENV} ${QTDIR}/bin/qmake "PREFIX=${PREFIX}" "QMAKE_CXXFLAGS=${CXXFLAGS}" ${QMAKE_OPTIONS})

#do-build:
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE_OPTIONS} ${GMAKE};	\
#	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} CFLAGS+=-Iobj ${QMAKE_OPTIONS} ${GMAKE} -f makefile.unix
#
do-install:
#	${INSTALL_PROGRAM} ${WRKSRC}/litecoin-qt ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/litecoind ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/litecoin-tx ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/litecoin-cli ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} -m 644 ${WRKSRC}/src/secp256k1/libsecp256k1.la ${DESTDIR}${PREFIX}/lib/litecoin
	${INSTALL_LIB} ${WRKSRC}/src/secp256k1/.libs/libsecp256k1.so.0 ${DESTDIR}${PREFIX}/lib/litecoin
	${LN} -fs ${DESTDIR}${PREFIX}/lib/litecoin/libsecp256k1.so.0 ${DESTDIR}${PREFIX}/lib/litecoin/libsecp256k1.so
	${INSTALL_DATA} -m 600 ${FILESDIR}/litecoin.conf ${DESTDIR}${EGDIR}


.include "../../databases/db4/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
