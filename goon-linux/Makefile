# $NetBSD$

DISTNAME=  	goon-linux-world-0.1.1
CATEGORIES= 	devel	
MASTER_SITES=	https://sourceforge.net/projects/goon-linux/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/goon-linux/
COMMENT= 	goon's personal GNU/Linux distribution	
LICENSE=	GPL	

WRKSRC=		${WRKDIR}/goon-linux-world-0.1.1/
USE_LANGUAGES=  Python 

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/goon-linux-world ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
