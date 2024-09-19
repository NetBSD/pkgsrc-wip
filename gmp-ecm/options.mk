# $NetBSD: options.mk,v 1.1 2008/05/29 15:05:34 athaba Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ecm
PKG_SUPPORTED_OPTIONS=	opteron sse2

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

###
### Optimize for Athlon64/Opteron
###
.if !empty(PKG_OPTIONS:Mopteron)
CONFIGURE_ARGS+=	--enable-asm-redc
.endif

###
### SSE2 optimization
###
.if !empty(PKG_OPTIONS:Msse2)
CONFIGURE_ARGS+=	--sse2
.endif
