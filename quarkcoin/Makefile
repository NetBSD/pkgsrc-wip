# $NetBSD$

#DISTNAME=	v0.8.3.25
DISTNAME=	v0.9.2.4
PKGNAME=	quarkcoin-${DISTNAME:S/v//1}
CATEGORIES=	finance
MASTER_SITES=	https://github.com/MaxGuevara/quark/archive/
DIST_SUBDIR=	${PKGBASE}

MAINTAINER=	pkgsrc-users@users.sourceforge.net
HOMEPAGE=	http://quark.cc/
COMMENT=	Open source Internet currency
LICENSE=	mit

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config autoconf aclocal autoheader automake libtoolize
USE_LANGUAGES=	c c++
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:S/coin//1}
AUTO_MKDIRS=	yes
HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes

CFLAGS+=	-fPIC
#CXXFLAGS+=	-std=c++0x
CXXFLAGS+=	-Wl,-R${BUILDLINK_PREFIX.boost-libs}/lib/quarkcoin -L${BUILDLINK_PREFIX.boost-libs}/lib/quarkcoin
CXXFLAGS+=	-DBOOST_VARIANT_USE_RELAXED_GET_BY_DEFAULT=1
CXXFLAGS+=	-I${BUILDLINK_PREFIX.boost-libs}/include/boost


BUILDLINK_TRANSFORM+=	l:db_cxx:db4_cxx

CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-libs}
CONFIGURE_ARGS+=	--enable-hardening
CONFIGURE_ARGS+=	${PREFIX}/include/db4

LIBTOOLIZE=	${PREFIX}/bin/libtoolize



QMAKE_OPTIONS+=	BOOST_INCLUDE_PATH=${PREFIX}/include/boost
QMAKE_OPTIONS+=	BDB_INCLUDE_PATH=${PREFIX}/include/db4
QMAKE_OPTIONS+=	OPENSSL_INCLUDE_PATH=${PREFIX}/include/openssl

QMAKE_OPTIONS+=	BOOST_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	BDB_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	OPENSSL_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	LIB_RPATH=${PREFIX}/lib

RCD_SCRIPTS=		quarkcoind
OWN_DIRS=		${VARBASE}/quarkcoin
EGDIR=			${PREFIX}/share/examples/quarkcoin
CONF_FILES=		${EGDIR}/quarkcoin.conf ${PKG_SYSCONFDIR}/quarkcoin.conf
CONF_FILES_PERMS=	${EGDIR}/quarkcoin.conf ${PKG_SYSCONFDIR}/quarkcoin.conf ${ROOT_USER} ${ROOT_GROUP} 0600

pre-configure:
	cd ${WRKSRC};             \
        ${LIBTOOLIZE} --force;    \
        ${PREFIX}/bin/aclocal;    \
        ${PREFIX}/bin/autoheader; \
        ${PREFIX}/bin/automake -a --foreign -i  --add-missing; \
        ${PREFIX}/bin/autoconf; \
        ${PREFIX}/bin/autoreconf -i

#do-configure:
#	(cd ${WRKSRC} && env ${CONFIGURE_ENV} ${QTDIR}/bin/qmake "PREFIX=${PREFIX}" "QMAKE_CXXFLAGS=${CXXFLAGS}" ${QMAKE_OPTIONS} quarkcoin-qt.pro)
#
#do-build:
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE_OPTIONS} ${GMAKE};	\
#	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} CFLAGS+=-Iobj ${QMAKE_OPTIONS} ${GMAKE} -f makefile.unix
#
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/quark-cli ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/quarkd ${DESTDIR}${PREFIX}/sbin/quarkcoind
	${INSTALL_DATA} -m 600 ${FILESDIR}/quarkcoin.conf ${DESTDIR}${EGDIR}

.include "options.mk"

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
