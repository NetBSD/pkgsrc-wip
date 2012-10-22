# $NetBSD: options.mk,v 1.1 2012/10/22 22:15:25 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tktable
PKG_SUPPORTED_OPTIONS=	threads
PKG_SUGGESTED_OPTIONS+=	threads

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mthreads)
CONFIGURE_ARGS+=	--enable-threads
.else
CONFIGURE_ARGS+=	--disable-threads
.endif
