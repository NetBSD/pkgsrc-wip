# $NetBSD$
#

DISTNAME=	openhexagon-2.0
CATEGORIES=	games

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vittorioromeo.info/projects.html
COMMENT=	Open-source clone of the game "Super Hexagon by Terry Cavanagh"
LICENSE=	afl-3.0

# (sorted in order of build dependency)
MODULES=	SSVUtils-c8190f843ab5bdfcff99e92aec7421c413c887e3 \
		SSVEntitySystem-8123beabe3bc8ffe91cb94e6ba061254f3bba18b \
		SSVJsonCpp-a45c64c418dc0b1fab1eec52fa70b6a14308c635 \
		SSVUtilsJson-95836250e3a9b65883f22991190e652a455121c1 \
		SSVStart-112229f184f5e4cf88c71fe67b4588806d290f71 \
		SSVMenuSystem-03d32b26b2880a35d5daa1ad7ab6199a4d19c742 \
		SSVLuaWrapper-ca905bddae86358182cf85eff2d0220ccdd785d0 \
		SSVOpenHexagonAssets-1d125de695be2e74c9f2ad3198e8b5b29911d010 \
		SSVOpenHexagon-2.0-preview

.for dist in ${MODULES:=.tar.gz}
DISTFILES+=	${dist}
SITES.${dist}+=	${MASTER_SITE_GITHUB:S,^,-,:=SuperV1234/${dist:S,-,/archive/,}}
.endfor

WRKSRC=		${WRKDIR}

USE_LANGUAGES=	c c++14
USE_CMAKE=	yes
USE_TOOLS+=	pax sed

SUBST_CLASSES+=		wrap
SUBST_STAGE.wrap=	pre-configure
SUBST_MESSAGE.wrap=	Adjusting shell wrapper
SUBST_FILES.wrap=	${PKGBASE}
SUBST_VARS.wrap=	PREFIX PKGBASE

SUBST_CLASSES+=		include
SUBST_STAGE.include=	post-configure
SUBST_MESSAGE.include=	Fixing hardcoded include path
SUBST_FILES.include=	${MODULES:MSSVLuaWrapper*}/include/SSVLuaWrapper/LuaContext/LuaContext.h
SUBST_SED.include=	-e 's,lua5.1,lua-${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR},'

MODULE_PATH=	${MODULES:NSSVOpenHexagon*:=${WRKDIR}/%/cmake/modules}

CMAKE_ARGS+=	-DBUILD_SHARED_LIB:BOOL=OFF
CMAKE_ARGS+=	-DLUA_LIBRARY=${BUILDLINK_DIR}/lib/liblua${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}.so
CMAKE_ARGS+=	-DLUA_INCLUDE_DIR=${BUILDLINK_DIR}/${LUA_INCDIR}
CMAKE_ARGS+=	-DSSVUTILS_INCLUDE_DIR=${MODULES:MSSVUtils-*:=${WRKDIR}/%/include}
CMAKE_ARGS+=	-DSSVUTILS_LIBRARY_RELEASE=${MODULES:MSSVUtils-*:=${WRKDIR}/%/libSSVUtils-s.a}
CMAKE_ARGS+=	-DSSVENTITYSYSTEM_INCLUDE_DIR=${MODULES:MSSVEntitySystem-*:=${WRKDIR}/%/include}
CMAKE_ARGS+=	-DSSVENTITYSYSTEM_LIBRARY_RELEASE=${MODULES:MSSVEntitySystem-*:=${WRKDIR}/%/libSSVEntitySystem-s.a}
CMAKE_ARGS+=	-DSSVJSONCPP_INCLUDE_DIR=${MODULES:MSSVJsonCpp-*:=${WRKDIR}/%/include}
CMAKE_ARGS+=	-DSSVJSONCPP_LIBRARY_RELEASE=${MODULES:MSSVJsonCpp-*:=${WRKDIR}/%/libSSVJsonCpp-s.a}
CMAKE_ARGS+=	-DSSVUTILSJSON_INCLUDE_DIR=${MODULES:MSSVUtilsJson-*:=${WRKDIR}/%/include}
CMAKE_ARGS+=	-DSSVUTILSJSON_LIBRARY_RELEASE=${MODULES:MSSVUtilsJson-*:=${WRKDIR}/%/libSSVUtilsJson-s.a}
CMAKE_ARGS+=	-DSSVSTART_INCLUDE_DIR=${MODULES:MSSVStart-*:=${WRKDIR}/%/include}
CMAKE_ARGS+=	-DSSVSTART_LIBRARY_RELEASE=${MODULES:MSSVStart-*:=${WRKDIR}/%/libSSVStart-s.a}
CMAKE_ARGS+=	-DSSVMENUSYSTEM_INCLUDE_DIR=${MODULES:MSSVMenuSystem-*:=${WRKDIR}/%/include}
CMAKE_ARGS+=	-DSSVMENUSYSTEM_LIBRARY_RELEASE=${MODULES:MSSVMenuSystem-*:=${WRKDIR}/%/libSSVMenuSystem-s.a}
CMAKE_ARGS+=	-DSSVLUAWRAPPER_INCLUDE_DIR=${MODULES:MSSVLuaWrapper-*:=${WRKDIR}/%/include}
CMAKE_ARGS+=	-DSSVLUAWRAPPER_LIBRARY_RELEASE=${MODULES:MSSVLuaWrapper-*:=${WRKDIR}/%/libSSVLuaWrapper-s.a}
CMAKE_ARGS+=	-DMODULE_PATH=${MODULE_PATH:ts;:Q}
CMAKE_ARGS+=	-DPKGBASE=${PKGBASE}

CONFIGURE_DIRS+=	${MODULES:NSSVOpenHexagonAssets*}

BUILD_DIRS+=		${MODULES:NSSVOpenHexagonAssets*}

INSTALL_DIRS+=		${MODULES:MSSVOpenHexagon-*}

INSTALLATION_DIRS+=	bin lib/${PKGBASE}

post-extract:
	${CP} ${FILESDIR}/${PKGBASE}.sh ${WRKSRC}/${PKGBASE}

post-build:
	for p in ${WRKDIR}/${MODULES:MSSVOpenHexagonAssets-*}/_RELEASE/Packs/*; do \
	    ${ECHO} "{ \"name\":\"$${p##*/}\", \"priority\":0 }" >$${p}/pack.json; \
	done

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGBASE} ${DESTDIR}${PREFIX}/bin
	cd ${WRKDIR}/${MODULES:MSSVOpenHexagonAssets-*}/_RELEASE && \
	    ${PAX} -rwpm Assets Packs ${DESTDIR}${PREFIX}/lib/${PKGBASE}

LUA_VERSIONS_ACCEPTED=	51

.include "../../wip/sfml+/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
