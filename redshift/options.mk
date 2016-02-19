# $NetBSD: options.mk,v 1.3 2015/07/20 23:03:24 dholland Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.redshift
PKG_SUPPORTED_OPTIONS+=		drm randr geoclue
PKG_SUGGESTED_OPTIONS=		drm randr

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdrm)
CONFIGURE_ARGS+=	--enable-drm
.include "../../x11/libdrm/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-drm
.endif

.if !empty(PKG_OPTIONS:Mrandr)
CONFIGURE_ARGS+=	--enable-randr
.include "../../x11/libxcb/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-randr
.endif

.if !empty(PKG_OPTIONS:Mgeoclue)
CONFIGURE_ARGS+=	--enable-geoclue
.include "../../geography/geoclue/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-geoclue
.endif
