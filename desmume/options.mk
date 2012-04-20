# $NetBSD: options.mk,v 1.1 2012/04/20 08:16:54 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.desmume
PKG_SUPPORTED_OPTIONS=	lua openal
PKG_SUGGESTED_OPTIONS=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua/buildlink3.mk"
#CFLAGS+=		-DHAVE_LUA=1 # needs lua-engine.h ?
.else
CFLAGS+=		-DHAVE_LUA=0
.endif

.if !empty(PKG_OPTIONS:Mopenal)
.include "../../audio/openal/buildlink3.mk"
CFLAGS+=		-DHAVE_OPENAL=1
.else
CFLAGS+=		-DHAVE_OPENAL=0
.endif
