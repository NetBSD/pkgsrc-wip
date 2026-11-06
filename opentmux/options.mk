# $NetBSD: options.mk,v 1.3 2015/11/11 16:12:10 leot Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opentmux
PKG_SUPPORTED_OPTIONS=	sixel
PKG_SUGGESTED_OPTIONS=	sixel

.include "../../mk/bsd.options.mk"

###
### Sixel support
###
.if !empty(PKG_OPTIONS:Msixel)
CONFIGURE_ARGS+=	--enable-sixel
.else
CONFIGURE_ARGS+=	--disable-sixel
.endif
