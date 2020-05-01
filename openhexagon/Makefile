# $NetBSD$
#

DISTNAME=	openhexagon-2.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=SuperV1234/}
GITHUB_PROJECT=	SSVOpenHexagon
GITHUB_TAG=	2.0-preview

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vittorioromeo.info/projects.html
COMMENT=	Open-source clone of the game "Super Hexagon by Terry Cavanagh"
LICENSE=	afl-3.0

USE_LANGUAGES=	c c++14
USE_CMAKE=	yes

SUBST_CLASSES+=		wrap
SUBST_STAGE.wrap=	pre-configure
SUBST_MESSAGE.wrap=	Adjusting wrapper
SUBST_FILES.wrap=	${PKGBASE}
SUBST_VARS.wrap=	PREFIX PKGBASE GITHUB_PROJECT

CMAKE_ARGS+=	-DLUA_LIBRARY=${PREFIX}/lib/liblua${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}.so
CMAKE_ARGS+=	-DLUA_INCLUDE_DIR=${PREFIX}/${LUA_INCDIR}
CMAKE_ARGS+=	-DMODULE_PATH=${PREFIX}/lib/cmake
CMAKE_ARGS+=	-DPKGBASE=${PKGBASE}

INSTALLATION_DIRS+=	games lib/${PKGBASE}

post-extract:
	${CP} ${FILESDIR}/${PKGBASE}.sh ${WRKSRC}/${PKGBASE}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGBASE} ${DESTDIR}${PREFIX}/games

# Dependencies
#
# perhaps also some assets, see wget-assets.sh
# seems to be a couple of packs with large music files are they important?

.include "../../wip/sfml+/buildlink3.mk"
.include "../../wip/SSVJsonCpp/buildlink3.mk"
.include "../../wip/SSVUtils/buildlink3.mk"
.include "../../wip/SSVStart/buildlink3.mk"
.include "../../wip/SSVEntitySystem/buildlink3.mk"
.include "../../wip/SSVLuaWrapper/buildlink3.mk"
.include "../../wip/SSVMenuSystem/buildlink3.mk"
.include "../../wip/SSVUtilsJson/buildlink3.mk"
.include "../../lang/lua/luaversion.mk"
.include "../../mk/bsd.pkg.mk"
