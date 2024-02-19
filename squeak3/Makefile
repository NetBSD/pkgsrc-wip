# $NetBSD$

DISTNAME=  	squeak3-03.7.7	
CATEGORIES=	lang	
MASTER_SITES=	https://sourceforge.net/projects/squeak3/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/squeak3/
COMMENT=	Squeak version 3.x	
LICENSE=	GPLv2	

WRKSRC=		${WRKDIR}/squeak3
USE_LANGUAGES= 	C	

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/squeak3 ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
