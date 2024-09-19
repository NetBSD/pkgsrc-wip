# $NetBSD: options.mk,v 1.1.1.1 2009/12/27 21:23:39 jihbed Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.gerris
PKG_SUPPORTED_OPTIONS=	gts-check mpi dx
PKG_SUGGESTED_OPTIONS=	gts-check

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgts-check)
.  include "../../graphics/gts/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gts-check
.endif

.if !empty(PKG_OPTIONS:Mmpi)
CONFIGURE_ARGS+=	--disable-mpi
.endif

.if !empty(PKG_OPTIONS:Mdx)
CONFIGURE_ARGS+=	--disable-dx
.endif
