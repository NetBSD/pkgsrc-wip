# $NetBSD$

DISTNAME=  	py-castlevania-widgets-0.1.3
CATEGORIES=	games	
MASTER_SITES=	https://sourceforge.net/projects/py-castlevania/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/py-castlevania/
COMMENT=	General purpose widget kit using Python and pygame	
LICENSE=	Nethack General Public License	

WRKSRC=		${WRKDIR}/py-castlevania
USE_LANGUAGES= 	Python 

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/py-castlevania ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
