# $NetBSD: $

PKG_OPTIONS_VAR=	PKG_OPTIONS.labwc
PKG_SUPPORTED_OPTIONS+=	xwayland
PKG_SUGGESTED_OPTIONS+=	xwayland

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Mxwayland)
MESON_ARGS+=	-Dxwayland=disabled
.endif
