# $NetBSD$

DISTNAME=	libmpack-lua-1.0.8
PKGNAME=	${DISTNAME:S/libmpack-lua/${LUA_PKGPREFIX}-mpack/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libmpack/}
GITHUB_PROJECT=	libmpack-lua

HOMEPAGE=	https://github.com/libmpack/libmpack-lua
COMMENT=	Lua binding for libmpack
LICENSE=	mit

USE_LANGUAGES=	c

INSTALLATION_DIRS+=	${LUA_CDIR}
USE_TOOLS+=		gmake pkg-config


MAKE_ENV+=	DEPS_PREFIX=${PREFIX}
MAKE_ENV+=	USE_SYSTEM_LUA=yes
MAKE_ENV+=	USE_SYSTEM_MPACK=yes
MAKE_ENV+=	MPACK_LUA_VERSION=${_LUA_DOT_VERSION}.0

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
BUILD_MAKE_FLAGS+=	LDFLAGS="-undefined dynamic_lookup"
BUILD_MAKE_FLAGS+=	LUA_CDIR=${LUA_CDIR}
.endif

.include "../../lang/lua/luaversion.mk"
.include "../../lang/lua/module.mk"
.include "../../wip/libmpack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
