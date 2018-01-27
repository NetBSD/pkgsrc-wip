# $NetBSD$

#DISTNAME=	v0.8.6.2
DISTNAME=	v0.8.7.1
PKGNAME=	feathercoin-${DISTNAME:S/v//1}
CATEGORIES=	finance
MASTER_SITES=	https://github.com/FeatherCoin/Feathercoin/archive/
DIST_SUBDIR=	${PKGBASE}

MAINTAINER=	pkgsrc-users@users.sourceforge.net
HOMEPAGE=	http://feathercoin.com/
COMMENT=	Open source Internet currency
LICENSE=	mit

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:S/f/F/1}
AUTO_MKDIRS=	yes

#CXXFLAGS+=	-std=c++0x -DBOOST_TT_HAS_OPERATOR_HPP_INCLUDED 
CXXFLAGS+=	-DBOOST_TT_HAS_OPERATOR_HPP_INCLUDED 
CXXFLAGS+=	-DBOOST_SYSTEM_NO_DEPRECATED 
CXXFLAGS+=	-Wall -g -I${PREFIX}/include/boost
#CXXFLAGS+=	-std=c++0x -Wall -g -I${PREFIX}/include/boost

QMAKE_OPTIONS+=	BOOST_INCLUDE_PATH=${PREFIX}/include/boost
QMAKE_OPTIONS+=	BDB_INCLUDE_PATH=${PREFIX}/include/db4
QMAKE_OPTIONS+=	OPENSSL_INCLUDE_PATH=${PREFIX}/include/openssl

QMAKE_OPTIONS+=	BOOST_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	BDB_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	OPENSSL_LIB_PATH=${PREFIX}/lib
QMAKE_OPTIONS+=	LIB_RPATH=${PREFIX}/lib

QMAKE_MOC +=	QMAKE_MOC -DBOOST_TT_HAS_OPERATOR_HPP_INCLUDED

RCD_SCRIPTS=		feathercoind
OWN_DIRS=		${VARBASE}/feathercoin
EGDIR=			${PREFIX}/share/examples/feathercoin
CONF_FILES=		${EGDIR}/feathercoin.conf ${PKG_SYSCONFDIR}/feathercoin.conf
CONF_FILES_PERMS=	${EGDIR}/feathercoin.conf ${PKG_SYSCONFDIR}/feathercoin.conf ${ROOT_USER} ${ROOT_GROUP} 0600

CONFIGURE_ARGS+=	--without-gui
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-libs}
BUILDLINK_TRANSFORM+=	l:db_cxx:db4_cxx

do-configure:
	(cd ${WRKSRC} && env ${CONFIGURE_ENV} ${QTDIR}/bin/qmake "PREFIX=${PREFIX}" "QMAKE_CXXFLAGS=${CXXFLAGS}" ${QMAKE_OPTIONS} feathercoin-qt.pro)

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE_OPTIONS} ${GMAKE};	\
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} CFLAGS+=-Iobj ${QMAKE_OPTIONS} ${GMAKE} USE_UPNP= -f makefile.unix

do-install:
	#${INSTALL_PROGRAM} ${WRKSRC}/feathercoin-qt ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/feathercoind ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} -m 600 ${FILESDIR}/feathercoin.conf ${DESTDIR}${EGDIR}


.include "options.mk"

DL_AUTO_VARS=           yes
.include "../../mk/dlopen.buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
