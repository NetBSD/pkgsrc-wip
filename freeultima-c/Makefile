# $NetBSD$

DISTNAME=  	freeultima-c-0.1.1
CATEGORIES=	games	
MASTER_SITES=	https://sourceforge.net/projects/freeultima/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/freeultima/
COMMENT=	C language supporting library	
LICENSE=	Freeware	

WRKSRC=		${WRKDIR}/freeultima-c-0.1.1
USE_LANGUAGES= 	C 

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freeultima-c-0.1.1 ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
