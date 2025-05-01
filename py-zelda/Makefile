# $NetBSD$

DISTNAME=  	py-zelda-The-Legend-of-Zelda-0.2.6
CATEGORIES=	games	
MASTER_SITES=	https://sourceforge.net/projects/py-zelda/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/py-zelda/
COMMENT=	Classic Zelda with AI	
LICENSE=	(Nethack) General Public License	

WRKSRC=		${WRKDIR}/py-zelda
USE_LANGUAGES= 	Python 

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/py-zelda ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
