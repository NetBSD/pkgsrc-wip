# $NetBSD$

DISTNAME=	amnesia-tdd-0.0.0
CATEGORIES=	games
#MASTER_SITES=	${MASTER_SITE_GITHUB:=shamazmazum/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=dressupgeekout/}
GITHUB_PROJECT=	AmnesiaTheDarkDescent
# the 'netbsd_again' branch:
GITHUB_TAG=	3086f2c562e73948f60ff32746f44552ca39c2c8

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://frictionalgames.com/
COMMENT=	Amnesia: The Dark Descent
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
