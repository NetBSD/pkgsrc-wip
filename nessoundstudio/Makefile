# $NetBSD$

DISTNAME=	nessoundstudio-0.3.2
CATEGORIES=	audio
MASTER_SITES=	https://sourceforge.net/projects/nessoundstudio/files/

MAINTAINER=	zara.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/nessoundstudio/
COMMENT=	NES music player and composing system
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/nessoundstudio-0.3
USE_LANGUAGES=	c++

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nessoundstudio ${DESTDIR}${PREFIX}/bin

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
