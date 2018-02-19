# $NetBSD$

DISTNAME=	mygui-git-20171012
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=MyGUI/}
GITHUB_PROJECT=	mygui
GITHUB_TAG=	b1e4bc802a63fef015fc1d213d45a520eddc99b3

HOMEPAGE=	http://mygui.info/
COMMENT=	Cross-platform library for creating GUIs for games and 3D programs
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DMYGUI_RENDERSYSTEM=7 # OpenGL 3.*

.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
