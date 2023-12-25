# $NetBSD$

DISTNAME=  	falcons-eye2-0.1.1
CATEGORIES=	games	
MASTER_SITES=	https://sourceforge.net/projects/falcons-eye2/files/

MAINTAINER=	zara.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/falcons-eye2/
COMMENT=	A 3D Falcon's Eye nethack game 
LICENSE=	Nethack General Public License	

WRKSRC=		${WRKDIR}/falcons-eye2
USE_LANGUAGES=  C	

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fastcol ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
