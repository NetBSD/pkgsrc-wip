# $NetBSD: options.mk,v 1.5 2019/04/26 13:13:46 maya Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.blis
PKG_SUPPORTED_OPTIONS=	openmp pthread
PKG_SUGGESTED_OPTIONS=	openmp


.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenmp)
CONFIGURE_ARGS+=	--enable-threading=openmp
.  if !empty(PKG_OPTIONS:Mpthread)
CONFIGURE_ARGS+=	--enable-threading=pthread
.  else
CONFIGURE_ARGS+=	--enable-threading=no
.  endif
.endif
