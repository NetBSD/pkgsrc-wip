# $NetBSD$

DISTNAME=  	py-castlevania-0.1.8
CATEGORIES=	games	
MASTER_SITES=	https://sourceforge.net/projects/py-castlevania/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/py-castlevania/
COMMENT=	Classic Castlevania	
LICENSE=	Nethack General Public License	

WRKSRC=		${WRKDIR}/py-castlevania
USE_LANGUAGES= 	Python 

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/py-castlevania ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
