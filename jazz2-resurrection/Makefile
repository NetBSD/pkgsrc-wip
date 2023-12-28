# $NetBSD$

GITHUB_PROJECT=	jazz2-native
GITHUB_TAG=	2.4.0
DISTNAME=	${GITHUB_TAG}
PKGNAME=	jazz2-resurrection-${GITHUB_TAG}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=deathkiller/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://deat.tk/jazz2/
COMMENT=	Open-source Jazz Jackrabbit 2 reimplementation
LICENSE=	gnu-gpl-v3

WRKSRC=			${WRKDIR}/jazz2-native-2.4.0
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17

CMAKE_OVERRIDES+=	-DNCINE_APP_NAME:STRING=Jazz2-Resurrection
CMAKE_OVERRIDES+=	-DNCINE_DOWNLOAD_DEPENDENCIES:BOOL=OFF
CMAKE_OVERRIDES+=	-DNCINE_LINUX_PACKAGE:STRING=Jazz2-Resurrection
CMAKE_OVERRIDES+=	-DNCINE_PACKAGED_CONTENT_PATH:BOOL=OFF
CMAKE_OVERRIDES+=	-DNCINE_OVERRIDE_CONTENT_PATH:STRING=${PREFIX}/share/Jazz2-Resurrection/Content/
CMAKE_OVERRIDES+=	-DPACKAGE_DIRECTORY:STRING=Jazz2-Resurrection
CMAKE_CONFIGURE_ARGS+=	${CMAKE_OVERRIDES}
CMAKE_CONFIGURE_ARGS+=	-DPKGSRC_INCLUDE:PATH=${PREFIX}/include
CMAKE_BUILD_ARGS+=	${CMAKE_OVERRIDES}
CMAKE_INSTALL_ARGS+=	${CMAKE_OVERRIDES}
CXXFLAGS+=		-DNCINE_LINUX_PACKAGE=\"Jazz2-Resurrection\"

.include "../../audio/libopenmpt/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glfw/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
