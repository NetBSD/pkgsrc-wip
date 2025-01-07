# $NetBSD$

DISTNAME=  	xdg-0.9.0
CATEGORIES=	x11	
MASTER_SITES=	https://sourceforge.net/projects/xdg/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/xdg/
COMMENT=	General purpose X11 library. Usable for anything graphical e.g. window managers or 3D.		
LICENSE=	GPL	

WRKSRC=		${WRKDIR}/xdg-0.9.0/
USE_LANGUAGES=  C++	

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdg ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
