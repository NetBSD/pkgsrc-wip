# $NetBSD$

DISTNAME=	raylib-3.5.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=raysan5/}

MAINTAINER=	dressupgeekout@gmail.com
COMMENT=	Simple library to enjoy videogames programming
LICENSE=	zlib

EXTRACT_USING=	gtar
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

CMAKE_ARGS+=	-DPLATFORM=Desktop
CMAKE_ARGS+=	-DUSE_EXTERNAL_GLFW:BOOL=ON
CMAKE_ARGS+=	-DBUILD_EXAMPLES:BOOL=OFF

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glfw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
