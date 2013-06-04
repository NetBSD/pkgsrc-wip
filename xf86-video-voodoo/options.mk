# $NetBSD: options.mk,v 1.1 2013/06/04 04:12:02 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xf86-video-voodoo
PKG_SUPPORTED_OPTIONS=	static
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mstatic)
CONFIGURE_ARGS+=	--enable-static=yes
.else
CONFIGURE_ARGS+=	--enable-static=no
.endif
