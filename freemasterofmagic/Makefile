# $NetBSD$

DISTNAME=  	freemasterofmagic-cpp-0.1.3
CATEGORIES=	games	
MASTER_SITES=	https://sourceforge.net/projects/freemasterofmagic/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/freemasterofmagic/
COMMENT=	A Master of Magic game 
LICENSE=	Freeware/Shareware	

WRKSRC=		${WRKDIR}/freemasterofmagic
USE_LANGUAGES= 	C	

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freemasterofmagic ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
