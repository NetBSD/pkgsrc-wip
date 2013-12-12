# $NetBSD: Makefile,v 1.1 2013/12/12 20:45:11 noud4 Exp $

DISTNAME=	bitcoin-0.8.5-linux
PKGNAME=	${DISTNAME:S|-linux||}
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bitcoin/}

MAINTAINER=	noud4@home.nl
HOMEPAGE=	http://bitcoin.sourceforge.net/
COMMENT=	P2P electronic cash system
LICENSE=	mit

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c++
WRKSRC=		${WRKDIR}/${DISTNAME}/src
QMAKE_OPTIONS+=	BDB_INCLUDE_PATH=${PREFIX}/include/db4
INSTALLATION_DIRS+=	bin

do-configure:
	(cd ${WRKSRC} && ${QTDIR}/bin/qmake PREFIX=${PREFIX} ${QMAKE_OPTIONS} bitcoin-qt.pro)

post-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${GMAKE} -f makefile.unix

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/src/bitcoin-qt ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/src/src/bitcoind ${DESTDIR}${PREFIX}/bin

.include "options.mk"

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
