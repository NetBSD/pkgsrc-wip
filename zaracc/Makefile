# $NetBSD$

DISTNAME=  	zaracc-0.1.10
CATEGORIES=	games	
MASTER_SITES=	https://sourceforge.net/projects/zaracc/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/zaracc/
COMMENT=	A C Compiler for Classic Amigas 
LICENSE=	Freeware/Shareware	

WRKSRC=		${WRKDIR}/zaracc
USE_LANGUAGES= 	C	

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zaracc ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
