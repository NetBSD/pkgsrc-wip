# $NetBSD$

DISTNAME=  	py-zeliard-0.2.1
CATEGORIES=	games	
MASTER_SITES=	https://sourceforge.net/projects/py-zeliard/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/py-zeliard/
COMMENT=	A Zeliard based game	
LICENSE=	GPL	

WRKSRC=		${WRKDIR}/py-zeliard
USE_LANGUAGES= 	Python 

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/py-zeliard ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
