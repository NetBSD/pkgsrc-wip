# $NetBSD$
#

# use date of commit as has no version only a tag

DISTNAME=	SSVLuaWrapper
PKGNAME=	${DISTNAME}-20130708
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=SuperV1234/}
GITHUB_TAG=	ca905bddae86358182cf85eff2d0220ccdd785d0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SuperV1234/SSVLuaWrapper
COMMENT=	C++11 LUA wrapper written by Tomaka17
LICENSE=	afl-3.0

USE_LANGUAGES=	c c++14
USE_CMAKE=	yes

LUA_VERSIONS_ACCEPTED=	51

CMAKE_ARGS+=	-DLUA_LIBRARY=${PREFIX}/lib/liblua${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}.so
CMAKE_ARGS+=	-DLUA_INCLUDE_DIR=${PREFIX}/${LUA_INCDIR}
CMAKE_ARGS+=	-DBUILD_SHARED_LIB:BOOL=OFF

SUBST_CLASSES+=		include
SUBST_STAGE.include=	post-configure
SUBST_MESSAGE.include=	Fixing hardcoded path
SUBST_FILES.include=	include/SSVLuaWrapper/LuaContext/LuaContext.h
SUBST_SED.include=	-e 's,lua5.1,lua-${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR},'

INSTALLATION_DIRS+=	include/${PKGBASE} lib/cmake

post-install:
	${INSTALL_DATA} ${WRKSRC}/cmake/modules/Find${PKGBASE}.cmake \
		${DESTDIR}${PREFIX}/lib/cmake

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
