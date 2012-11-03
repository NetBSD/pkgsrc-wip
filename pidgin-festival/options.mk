# $NetBSD: options.mk,v 1.1 2012/11/03 12:27:45 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pidgin-festival
PKG_SUPPORTED_OPTIONS=	debug
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif
