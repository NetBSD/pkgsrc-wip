# $NetBSD: options.mk,v 1.4 2019/10/20 11:10:48 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.luakit
PKG_SUPPORTED_OPTIONS=		luajit
PKG_SUGGESTED_OPTIONS=		luajit

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mluajit)
MAKE_FLAGS+=	USE_LUAJIT=1
NOT_PAX_MPROTECT_SAFE+=	bin/luakit # LuaJit
.  include "../../lang/LuaJIT2/buildlink3.mk"
.else
MAKE_FLAGS+=	USE_LUAJIT=0
.  include "../../lang/lua51/buildlink3.mk"
.endif
