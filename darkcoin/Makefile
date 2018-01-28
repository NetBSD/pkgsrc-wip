# $NetBSD$

#DISTNAME=	v0.9.12.32
DISTNAME=	v0.12.0.55
#PKGNAME=	darkcoin-${DISTNAME:S/v//1}
PKGNAME=	dash-${DISTNAME:S/v//1}
CATEGORIES=	finance
MASTER_SITES=	https://github.com/darkcoinproject/darkcoin/archive/

MAINTAINER=	pkgsrc-users@users.sourceforge.net
HOMEPAGE=	http://www.darkcoin.io/
COMMENT=	Secure, decentralized, and anonymous digital currency
LICENSE=	mit

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config autoconf aclocal autoheader automake libtoolize
USE_LANGUAGES=	c c++
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
AUTO_MKDIRS=	yes
HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes

#CXXFLAGS+=		-std=c++0x
CXXFLAGS+=		-Wl,-R${BUILDLINK_PREFIX.boost-libs}/lib/dash -L${BUILDLINK_PREFIX.boost-libs}/lib/dash
CXXFLAGS+=		-I${BUILDLINK_PREFIX.boost-libs}/include/boost
CFLAGS+=		-fPIC
BUILDLINK_TRANSFORM+=	l:db_cxx:db4_cxx

CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-libs}
CONFIGURE_ARGS+=	--enable-hardening
CONFIGURE_ARGS+=	${PREFIX}/include/db4

QMAKE_OPTIONS+=	BOOST_INCLUDE_PATH=${PREFIX}/include/boost
QMAKE_OPTIONS+=	BDB_INCLUDE_PATH=${PREFIX}/include/db4
QMAKE_OPTIONS+=	OPENSSL_INCLUDE_PATH=${PREFIX}/include/openssl

QMAKE_OPTIONS+=	BOOST_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	BDB_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	OPENSSL_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	LIB_RPATH=${PREFIX}/lib

RCD_SCRIPTS=		dashd
OWN_DIRS=		${VARBASE}/dash
EGDIR=			${PREFIX}/share/examples/dash
CONF_FILES=		${EGDIR}/dash.conf ${PKG_SYSCONFDIR}/dash.conf
CONF_FILES_PERMS=	${EGDIR}/dash.conf ${PKG_SYSCONFDIR}/dash.conf ${ROOT_USER} ${ROOT_GROUP} 0600
INSTALLATION_DIRS+=	share/examples/dash

pre-configure:
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
#	${INSTALL_PROGRAM} ${WRKSRC}/darkcoin-qt ${DESTDIR}${PREFIX}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/src/darkcoind ${DESTDIR}${PREFIX}/sbin
#	${INSTALL_DATA} -m 600 ${FILESDIR}/darkcoin.conf ${DESTDIR}${EGDIR}
#
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/dashd ${DESTDIR}${PREFIX}/sbin/dashd
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/dash-tx ${DESTDIR}${PREFIX}/bin/dash-tx
	${INSTALL_PROGRAM} ${WRKSRC}/src/dash-cli ${DESTDIR}${PREFIX}/bin/dash-cli
	${INSTALL_LIB} -m 644 ${WRKSRC}/src/secp256k1/libsecp256k1.la ${DESTDIR}${PREFIX}/lib/dash
	${INSTALL_LIB} ${WRKSRC}/src/secp256k1/.libs/libsecp256k1.so.0 ${DESTDIR}${PREFIX}/lib/dash
	${LN} -fs ${DESTDIR}${PREFIX}/lib/dash/libsecp256k1.so.0 ${DESTDIR}${PREFIX}/lib/dash/libsecp256k1.so
	${INSTALL_DATA} -m 600 ${FILESDIR}/dash.conf ${DESTDIR}${EGDIR}


.include "options.mk"

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
