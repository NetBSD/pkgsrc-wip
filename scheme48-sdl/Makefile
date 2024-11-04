# $NetBSD$

DISTNAME=  	scheme48-sdl-1.9.3
CATEGORIES=	devel
MASTER_SITES=	https://sourceforge.net/projects/scheme48-sdl/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/scheme48-sdl/
COMMENT=	scheme48 with SDL bindings	
LICENSE=	BSD	

WRKSRC=		${WRKDIR}/scheme48-sdl/
USE_LANGUAGES=  C	

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scheme48-sdl ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
