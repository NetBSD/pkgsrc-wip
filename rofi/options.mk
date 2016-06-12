# $NetBSD: options.mk,v 1.8 2015/01/21 22:56:43 heidnes Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rofi

PKG_SUPPORTED_OPTIONS+=	i3
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mi3)
.include "../../wm/i3/buildlink3.mk"
.endif
