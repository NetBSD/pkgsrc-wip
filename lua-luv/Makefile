# $NetBSD$

DISTNAME=	luv-1.43.0-0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/-0$//1}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=luvit/}
GITHUB_PROJECT=	luv
GITHUB_TAG=	${DISTNAME:S/^luv-//1}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/luvit/luv
COMMENT=	Bare libuv bindings for Lua
LICENSE=	apache-2.0

.include "../../lang/lua/luaversion.mk"

.if ${_LUA_VERSION} == "51" || ${_LUA_VERSION} == "52"
DEPENDS+=	${LUA_PKGPREFIX}-compat53-[0-9]*:../../devel/lua-compat53
.endif

USE_CMAKE=	yes

CMAKE_CONFIGURE_ARGS+=	-DWITH_SHARED_LIBUV=ON
CMAKE_CONFIGURE_ARGS+=	-DBUILD_MODULE=ON
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DLUA_BUILD_TYPE=System
CMAKE_CONFIGURE_ARGS+=	-DWITH_LUA_ENGINE=Lua

pre-configure:
.if ${_LUA_VERSION} == "51" || ${_LUA_VERSION} == "52"
	${CP} ${PREFIX}/${LUA_INCDIR}/compat-5.3.* ${WRKSRC}/src
.endif

.include "../../lang/lua/module.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
