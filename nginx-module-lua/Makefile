# $NetBSD$

DISTNAME=	lua-nginx-module-0.10.20
MASTER_SITE=	${MASTER_SITE_GITHUB:=openresty/lua-nginx-module}
LICENSE=	2-clause-bsd

NGINX_MODULE=		lua
NGINX_HTTP_MODULES+=	lua

.include "../../lang/LuaJIT2/buildlink3.mk"
CONFIGURE_ENV+=		LUAJIT_LIB=${PREFIX}/lib
CONFIGURE_ENV+=		LUAJIT_INC=${PREFIX}/include/luajit-2.0

.include "../../wip/nginx-modular/module.mk"
.include "../../mk/bsd.pkg.mk"
