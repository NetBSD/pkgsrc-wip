# $NetBSD$

#DISTNAME=	v0.4.0ppc
#DISTNAME=	v0.6.2.2
DISTNAME=	master
PKGNAME=	peercoin-${DISTNAME:C/v([0-9]\.[0-9]\.[0-9]).*/\1/1}
CATEGORIES=	finance
#MASTER_SITES=	https://github.com/ppcoin/ppcoin/archive/
MASTER_SITES=	${MASTER_SITE_GITHUB:=ppcoin/ppcoin/archive/}
DIST_SUBDIR=	${PKGBASE}

MAINTAINER=	pkgsrc-users@users.sourceforge.net
HOMEPAGE=	http://peercoin.com/
COMMENT=	Open source peer-to-peer digital currency, favored by Shiba Inus
LICENSE=	mit

USE_LIBTOOL=	yes
#USE_TOOLS+=	gmake pkg-config autoconf aclocal autoheader automake libtoolize
USE_TOOLS+=	gmake pkg-config autoconf aclocal autoheader automake
USE_LANGUAGES=	c c++
WRKSRC=		${WRKDIR}/ppcoin-${DISTNAME:S/v//1}
AUTO_MKDIRS=	yes

#CXXFLAGS+=	-std=c++0x
CXXFLAGS+=	-I${BUILDLINK_PREFIX.boost-libs}/include/boost
CXXFLAGS+=	-I/usr/include

BUILDLINK_TRANSFORM+=	l:db_cxx:db4_cxx


QMAKE_OPTIONS+=	BOOST_INCLUDE_PATH=${PREFIX}/include/boost
QMAKE_OPTIONS+=	BDB_INCLUDE_PATH=${PREFIX}/include/db4
QMAKE_OPTIONS+=	OPENSSL_INCLUDE_PATH=${PREFIX}/include/openssl

QMAKE_OPTIONS+=	BOOST_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	BDB_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	OPENSSL_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	LIB_RPATH=${PREFIX}/lib

RCD_SCRIPTS=		peercoind
OWN_DIRS=		${VARBASE}/peercoin
EGDIR=			${PREFIX}/share/examples/peercoin
CONF_FILES=		${EGDIR}/peercoin.conf ${PKG_SYSCONFDIR}/peercoin.conf
CONF_FILES_PERMS=	${EGDIR}/peercoin.conf ${PKG_SYSCONFDIR}/peercoin.conf ${ROOT_USER} ${ROOT_GROUP} 0600


do-configure:
	(cd ${WRKSRC} && env ${CONFIGURE_ENV} ${QTDIR}/bin/qmake "PREFIX=${PREFIX}" "QMAKE_CXXFLAGS=${CXXFLAGS}" ${QMAKE_OPTIONS} bitcoin-qt.pro)

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE_OPTIONS} ${GMAKE};	\
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} CFLAGS+=-Iobj ${QMAKE_OPTIONS} ${GMAKE} -f makefile.unix

do-install:
	# XXX: Not building?
	#${INSTALL_PROGRAM} ${WRKSRC}/src/bitcoin-qt ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/ppcoind ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} -m 600 ${FILESDIR}/peercoin.conf ${DESTDIR}${EGDIR}

.include "options.mk"

# for backtrace
.if ${OPSYS} == "FreeBSD"
.include "../../devel/libexecinfo/buildlink3.mk"
LIBS+=  -lexecinfo
.endif

DL_AUTO_VARS=		yes

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
