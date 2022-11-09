# $NetBSD$

DISTNAME=	SuperTuxKart-1.4-src
PKGNAME=	${DISTNAME:tl:S/-src//}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=supertuxkart/}
GITHUB_PROJECT=	stk-code
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://supertuxkart.net/Main_Page
COMMENT=	Free 3D kart racing game
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	cmake pkg-config

CMAKE_ARGS+=	-DUSE_WIIUSE=OFF
CMAKE_ARGS+=	-DBUILD_RECORDER=OFF
CMAKE_ARGS+=	-DUSE_SYSTEM_SQUISH=OFF

# Needs linux joystick support.
CMAKE_ARGS+=	-DENABLE_WAYLAND_DEVICE=OFF

# -std=gnu++0x
GCC_REQD+=	4.8

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../net/enet/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
