# $NetBSD$

DISTNAME=	Cytopia-0.2.1
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=CytopiaTeam/}
GITHUB_PROJECT=	Cytopia
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://www.cytopia.net/
COMMENT=	City building simulation game
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config

CMAKE_CONFIGURE_ARGS+=	-DUSE_PACKAGE_MANAGER=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_AUDIO=OFF

# for audio
#.include "../../audio/SDL2_mixer/buildlink3.mk"
#.include "../../audio/libvorbis/buildlink3.mk"
## TODO: openal-soft fails to build on my Linux host
#.include "../../audio/openal-soft/buildlink3.mk"
#.include "../../multimedia/libogg/buildlink3.mk"

# TODO: imgui
# TODO: libnoise
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
