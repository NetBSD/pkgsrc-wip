# $NetBSD$

DISTNAME=	SLADE-3.1.12a
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=sirjuddington/}
GITHUB_TAG=	${DISTNAME:S/SLADE-//}

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://slade.mancubus.net/
COMMENT=	It's a Doom Editor
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=	c c++14
USE_TOOLS+=	pkg-config
USE_CMAKE=	yes
CMAKE_ARGS+=	-Wno-dev
CMAKE_ARGS+=	-DNO_COTIRE=ON  # cmake has similar functionality since 3.16
CMAKE_ARGS+=	-DNO_WEBVIEW=ON

.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.3
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freeimage/buildlink3.mk"
.include "../../graphics/ftgl/buildlink3.mk"
.include "../../multimedia/sfml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.if ${PKG_BUILD_OPTIONS.wxGTK30:Mgtk2}
CMAKE_ARGS+=	-DWX_GTK3=OFF
.endif

.include "../../mk/bsd.pkg.mk"
