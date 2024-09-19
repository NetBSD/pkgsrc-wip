# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.wlroots

PKG_SUPPORTED_OPTIONS=	x11 xwayland

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11 xwayland

.if empty(PKG_OPTIONS:Mx11)
MESON_ARGS+=		-Dx11-backend=disabled
.else
PLIST.x11=		yes
.endif

.if empty(PKG_OPTIONS:Mxwayland)
MESON_ARGS+=		-Dxwayland=disabled
.else
PLIST.xwayland=		yes
.endif
