# $NetBSD: options.mk,v 1.5 2014/04/18 16:01:58 thomasklausner Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.audacious-plugins
PKG_SUPPORTED_OPTIONS=  gtk3
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=        --enable-gtk3
.include "../../x11/gtk3/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --disable-gtk3
.endif
