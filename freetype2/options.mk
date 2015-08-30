# $NetBSD: options.mk,v 1.1 2015/08/30 09:18:16 makoto Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.freetype2
PKG_SUPPORTED_OPTIONS=	png subpixel

.include "../../mk/bsd.options.mk"

# subpixel (lcd) rendering, patent issues
.if !empty(PKG_OPTIONS:Msubpixel)
CFLAGS+=	-DFT_CONFIG_OPTION_SUBPIXEL_RENDERING
.endif

.if !empty(PKG_OPTIONS:Mpng)
CONFIGURE_ARGS+= --with-png=yes
.include "../../graphics/png/buildlink3.mk"
.else
CONFIGURE_ARGS+= --with-png=no
.endif
