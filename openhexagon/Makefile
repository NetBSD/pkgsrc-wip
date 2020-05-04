# $NetBSD$
#

DISTNAME=	openhexagon-2.0
CATEGORIES=	games
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vittorioromeo.info/projects.html
COMMENT=	Open-source clone of the game "Super Hexagon by Terry Cavanagh"
LICENSE=	afl-3.0

GITHUB_MODULES= \
	SSVOpenHexagon		2.0-preview \
	SSVOpenHexagonAssets	1d125de695be2e74c9f2ad3198e8b5b29911d010

# EXTRACT_SUFX must be defined here otherwise we cannot
# set the SITES.* variables correctly

.for mod tag in ${GITHUB_MODULES}
DISTFILES+=	${mod}-${tag}${EXTRACT_SUFX}
SITES.${mod}-${tag}${EXTRACT_SUFX}+= \
	-http://github.com/SuperV1234/${mod}/archive/${tag}${EXTRACT_SUFX}
MODULES+=	${mod}-${tag}
.endfor

USE_LANGUAGES=	c c++14
USE_CMAKE=	yes
USE_TOOLS+=	pax sed

SUBST_CLASSES+=		wrap
SUBST_STAGE.wrap=	pre-configure
SUBST_MESSAGE.wrap=	Adjusting wrapper
SUBST_FILES.wrap=	${PKGBASE}
SUBST_VARS.wrap=	PREFIX PKGBASE

CMAKE_ARGS+=	-DLUA_LIBRARY=${PREFIX}/lib/liblua${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}.so
CMAKE_ARGS+=	-DLUA_INCLUDE_DIR=${PREFIX}/${LUA_INCDIR}
CMAKE_ARGS+=	-DMODULE_PATH=${PREFIX}/lib/cmake
CMAKE_ARGS+=	-DPKGBASE=${PKGBASE}

WRKSRC=	${WRKDIR}/${MODULES:MSSVOpenHexagon-*}

INSTALLATION_DIRS+=	bin lib/${PKGBASE}

post-extract:
	${CP} ${FILESDIR}/${PKGBASE}.sh ${WRKSRC}/${PKGBASE}

post-build:
	for p in ${WRKDIR}/${MODULES:MSSVOpenHexagonAssets-*}/_RELEASE/Packs/*; do \
	    echo "{ \"name\":\"$${p##*/}\", \"priority\":0 }" >$${p}/pack.json; \
	done

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGBASE} ${DESTDIR}${PREFIX}/bin
	cd ${WRKDIR}/${MODULES:MSSVOpenHexagonAssets-*}/_RELEASE && \
	    ${PAX} -rwpm Assets Packs ${DESTDIR}${PREFIX}/lib/${PKGBASE}

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
