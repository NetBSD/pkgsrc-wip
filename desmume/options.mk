# $NetBSD: options.mk,v 1.2 2012/05/04 15:38:34 noud4 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.desmume
PKG_SUPPORTED_OPTIONS=	lua openal
PKG_SUGGESTED_OPTIONS=	lua

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua/buildlink3.mk"
#CFLAGS+=		-DHAVE_LUA=1
.else
CFLAGS+=		-DHAVE_LUA=0	# XXX needs lua-engine.h ?
.endif

.if !empty(PKG_OPTIONS:Mopenal)
.include "../../audio/openal/buildlink3.mk"
CFLAGS+=		-DHAVE_OPENAL=1
.else
CFLAGS+=		-DHAVE_OPENAL=0
.endif
