# $NetBSD$

DISTNAME=	mygui-git-20170211
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=MyGUI/}

HOMEPAGE=	http://mygui.info/
COMMENT=	Cross-platform library for creating GUIs for games and 3D programs
LICENSE=	mit

GITHUB_PROJECT=	mygui
GITHUB_TAG=	2da9599df1985eb252bfc9ce1dd5bac0999c6a18

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DMYGUI_RENDERSYSTEM=7 # OpenGL 3.*

.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
