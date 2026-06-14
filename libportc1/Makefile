# $NetBSD$

DISTNAME=  	libportc1-0.1.17
CATEGORIES=	devel	
MASTER_SITES=	https://sourceforge.net/projects/libportc/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/libportc/
COMMENT=	C language supporting library	
LICENSE=	General Public License	

WRKSRC=		${WRKDIR}/libportc1
USE_LANGUAGES= 	C 

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libportc1 ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
