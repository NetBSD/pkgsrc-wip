# $NetBSD: Makefile,v 1.2 2012/02/24 21:17:45 reinoudz70 Exp $
#

PKGNAME=	opencsg-1.3.2
DISTNAME=	OpenCSG-1.3.2
CATEGORIES=	wip
MASTER_SITES=	http://www.opencsg.org/

MAINTAINER=	reinoud@tomaatnet.nl
HOMEPAGE=	http://www.opencsg.org/
COMMENT=	Image based CSG rendering library using OpenGL
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

do-install:
	${INSTALL_LIB} -d ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} -d ${DESTDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/lib/* ${DESTDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/include/* ${DESTDIR}${PREFIX}/include/

.include "../../mk/x11.buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
