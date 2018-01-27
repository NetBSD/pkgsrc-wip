# $NetBSD: Makefile,v 1.5 2012/09/24 16:56:38 asau Exp $
#

DISTNAME=	argtable2-13
PKGNAME=	argtable2-2.13
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=argtable/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://argtable.sourceforge.net/
COMMENT=	ANSI C Library for parsing GNU style command line arguments
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	argtable2.pc.in

INSTALLATION_DIRS=	include ${PKGMANDIR}/man3 share/doc/argtable

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/argtable2.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/doc/*.3 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${DESTDIR}${PREFIX}/share/doc/argtable
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DESTDIR}${PREFIX}/share/doc/argtable
	${INSTALL_DATA} ${WRKSRC}/doc/*.gif ${DESTDIR}${PREFIX}/share/doc/argtable
	${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${DESTDIR}${PREFIX}/share/doc/argtable


.include "../../mk/bsd.pkg.mk"
