# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.toxic
PKG_SUPPORTED_OPTIONS+=	notify x11
PKG_SUGGESTED_OPTIONS+=	notify x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnotify)
.include "../../sysutils/libnotify/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libX11/buildlink3.mk"
.endif
