# $NetBSD: options.mk,v 1.2 2012/11/06 14:58:16 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tkhtml3
PKG_SUPPORTED_OPTIONS=	threads
PKG_SUGGESTED_OPTIONS+=	threads

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mthreads)
.include "../../mk/pthread.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-threads
.else
CONFIGURE_ARGS+=	--disable-threads
.endif
