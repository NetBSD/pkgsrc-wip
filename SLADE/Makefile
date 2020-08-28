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
USE_TOOLS+=	pkg-config zip
USE_CMAKE=	yes
CMAKE_ARGS+=	-Wno-dev
CMAKE_ARGS+=	-DNO_COTIRE=ON  # CMake has similar functionality since 3.16
CMAKE_ARGS+=	-DNO_WEBVIEW=ON
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release  # Use "Debug" for development

INSTALLATION_DIRS+=	share/icons/hicolor/128x128/apps

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/applications/net.mancubus.SLADE.desktop \
		${DESTDIR}${PREFIX}/share/applications/SLADE.desktop
	${MV} ${DESTDIR}${PREFIX}/share/icons/net.mancubus.SLADE.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/128x128/apps/SLADE.png
	${MV} ${DESTDIR}${PREFIX}/share/metainfo/net.mancubus.SLADE.metainfo.xml \
		${DESTDIR}${PREFIX}/share/metainfo/SLADE.metainfo.xml

BUILDLINK_API_DEPENDS.fluidsynth+=	fluidsynth>=1.1.3
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=		zlib>=1.2.3
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freeimage/buildlink3.mk"
.include "../../graphics/ftgl/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.sfml+=		sfml>=2.0
.include "../../multimedia/sfml/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.if ${PKG_BUILD_OPTIONS.wxGTK30:Mgtk2}
CMAKE_ARGS+=	-DWX_GTK3=OFF
.endif

.include "../../mk/bsd.pkg.mk"
