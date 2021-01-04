# $NetBSD$

DISTNAME=	pioneer-${VERSION}
VERSION=	${GITHUB_TAG}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=pioneerspacesim/}
GITHUB_TAG=	20200203

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://pioneerspacesim.net/
COMMENT=	Game of lonely space adventure
LICENSE=	gnu-gpl-v3

USE_LANGUAGES+=	c c++
USE_CMAKE=	yes

CMAKE_ARGS+=	-DPIONEER_DATA_DIR=${PREFIX}/share/pioneer/data
CMAKE_ARGS+=	-DUSE_SYSTEM_LIBGLEW=ON
CMAKE_ARGS+=	-DUSE_SYSTEM_LIBLUA=ON

.include "../../archivers/lz4/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../multimedia/assimp/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../lang/lua52/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
