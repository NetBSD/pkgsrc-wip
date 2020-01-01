# $NetBSD$

DISTNAME=	lua-luv-1.32.0
PKGNAME=	${DISTNAME:S/lua-//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=luvit/}
GITHUB_PROJECT=	luv
GITHUB_TAG=	${PKGVERSION_NOREV}-0

HOMEPAGE=	https://github.com/luvit/luv/
COMMENT=	Bare libuv bindings for Lua
LICENSE=	apache-2.0

USE_CMAKE=	yes

# should follow the LuaJIT API compatibility as those are the 2 options
LUA_VERSIONS_ACCEPTED=	51

CMAKE_ARGS+=	-DWITH_SHARED_LIBUV=ON
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_ARGS+=	-DBUILD_MODULE=OFF
CMAKE_ARGS+=	-DLUA_BUILD_TYPE=System
CMAKE_ARGS+=	-DLUA_COMPAT53_DIR=${PREFIX}/${LUA_LDIR}/compat53/
CMAKE_ARGS+=	-DCMAKE_C_FLAGS="-I${PREFIX}/${LUA_INCDIR} -I${PREFIX}/${LUA_LDIR}/compat53"

.include "options.mk"

.include "../../wip/lua-compat53/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
