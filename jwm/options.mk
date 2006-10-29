# $NetBSD: options.mk,v 1.3 2006/10/29 08:32:45 shattered Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.jwm
PKG_SUPPORTED_OPTIONS=	debug nopng

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Mnopng)
CONFIGURE_ARGS+=	--disable-png
.else
CC+=			-lpng -lz
.endif
