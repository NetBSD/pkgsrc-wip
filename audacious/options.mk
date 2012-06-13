# $NetBSD: options.mk,v 1.2 2012/06/13 07:34:31 othyro Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.audacious
PKG_SUPPORTED_OPTIONS=  gtk3
PKG_SUGGESTED_OPTIONS=  # blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=        --enable-gtk3
.include "../../x11/gtk3/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --disable-gtk3
.endif
