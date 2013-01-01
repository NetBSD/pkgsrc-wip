# $NetBSD: options.mk,v 1.1 2013/01/01 01:46:24 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mono
PKG_SUPPORTED_OPTIONS=	moonlight
# PKG_SUGGESTED_OPTIONS=	moonlight

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		moon

.if !empty(PKG_OPTIONS:Mmoonlight)
PLIST.moon=	yes
CONFIGURE_ARGS+=	--with-moonlight=yes
.else
CONFIGURE_ARGS+=	--with-moonlight=no
.endif
