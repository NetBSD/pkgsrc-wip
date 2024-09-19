# $NetBSD: options.mk,v 1.3 2013/12/19 03:25:56 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.desmume
PKG_SUPPORTED_OPTIONS=	lua nls openal
PKG_SUGGESTED_OPTIONS=	lua nls
PLIST_VARS+=		nls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlua)
LUA_VERSIONS_ACCEPTED=	51
.include "../../lang/lua/buildlink3.mk"
#CFLAGS+=		-DHAVE_LUA=1
.else
CFLAGS+=		-DHAVE_LUA=0	# XXX needs lua-engine.h ?
.endif

.if !empty(PKG_OPTIONS:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
PLIST.nls=		yes
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.if !empty(PKG_OPTIONS:Mopenal)
.include "../../audio/openal-soft/buildlink3.mk"
CFLAGS+=		-DHAVE_OPENAL=1
.else
CFLAGS+=		-DHAVE_OPENAL=0
.endif
