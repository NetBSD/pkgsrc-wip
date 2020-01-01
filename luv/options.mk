# $NetBSD$
# $NetBSD $

PKG_OPTIONS_VAR=		PKG_OPTIONS.luv
PKG_OPTIONS_REQUIRED_GROUPS=	lua
PKG_OPTIONS_GROUP.lua=		lua luajit
PKG_SUGGESTED_OPTIONS=		lua

.include "../../mk/bsd.options.mk"

###
### Use lua (add dependency)
###
.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_LUA_ENGINE=Lua
.endif

###
### Use luajit (add dependency)
###
.if !empty(PKG_OPTIONS:Mluajit)
.include "../../lang/LuaJIT2/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_LUA_ENGINE=LuaJIT
.endif
