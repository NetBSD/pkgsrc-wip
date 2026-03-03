# $NetBSD: $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wlroots
PKG_SUPPORTED_OPTIONS+=	xwayland
PKG_SUGGESTED_OPTIONS+=	xwayland

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	xwayland
.if !empty(PKG_OPTIONS:Mxwayland)
.include "../../wip/xwayland/buildlink3.mk"
PLIST.xwayland=	yes
.endif
