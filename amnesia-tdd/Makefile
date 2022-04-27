# $NetBSD$

DISTNAME=	amnesia-tdd-0.0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=dressupgeekout/}
GITHUB_PROJECT=	AmnesiaTheDarkDescent
GITHUB_TAG=	be59f8410e0e9a8db583b42f588776d292ac9466

MAINTAINER=	dressupgeekout@gmail.com
HOMEPAGE=	https://frictionalgames.com
COMMENT=	Amnesia: The Dark Desceent
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	perl

USE_CMAKE=	yes
CMAKE_ARGS+=	-DSYSTEMWIDE_RESOURCES=ON
CMAKE_ARGS+=	-DSYSTEMWIDE_RESOURCES_LOCATION="${PREFIX}/share/amnesia-tdd"
CMAKE_ARGS+=	./amnesia/src

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/devIL/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
