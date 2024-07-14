# $NetBSD$

DISTNAME=  	py-pcs-0.1.3	
CATEGORIES=	games	
MASTER_SITES=	https://sourceforge.net/projects/py-pcs/files/

MAINTAINER=	winged.goon.mage@gmail.com
HOMEPAGE=	https://sourceforge.net/projects/py-pcs/
COMMENT=	Python - pygame (SDL 1.2) character sheets library 
LICENSE=	PFL	

WRKSRC=		${WRKDIR}/py-pcs
USE_LANGUAGES= 	Python	

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/py-pcs ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
