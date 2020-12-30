# $NetBSD$

PKGNAME=	arx-libertatis-1.2
CATEGORIES=	games
DISTFILES+=	arx-libertatis-data-1.tar.xz
SITES.arx-libertatis-data-1.tar.xz= \
https://arx-libertatis.org/files/data/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://arx-libertatis.org/
COMMENT=	Cross-platform, open source port of the Arx Fatalis RPG
LICENSE=	gnu-gpl-v3

GIT_REPOSITORIES=	arxlibertatis
GIT_REPO.arxlibertatis=	git://github.com/arx/ArxLibertatis
WRKSRC=			${WRKDIR}/arxlibertatis

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-D CMAKE_INSTALL_MANDIR:STRING:=${PKGMANDIR}
CMAKE_ARGS+=	-D DATA_FILES:STRING:=${WRKDIR}/arx-libertatis-data-1
CMAKE_ARGS+=	-D INSTALL_BLENDER_PLUGIN:BOOL=OFF
CMAKE_ARGS+=	-D USE_QT4:BOOL=OFF
CMAKE_ARGS+=	-D USE_QT5:BOOL=OFF

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	NotDarwin

.if ${OPSYS} != "Darwin"
PLIST.NotDarwin=	yes
.endif

.include "options.mk"

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glm/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
