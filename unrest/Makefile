# $NetBSD$

DISTNAME=	unrest-1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=dressupgeekout/}
GITHUB_TAG=	dressupgeekout-${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://pyrodactyl.com/unrest/
COMMENT=	Engine for Unrest, by Pyrodactyl Games
LICENSE=	mit

WRKSRC=		${WRKDIR}/unrest-${GITHUB_TAG}/CRAB

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

NO_CONFIGURE=	yes

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
