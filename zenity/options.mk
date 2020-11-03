# $NetBSD$

PKG_OPTIONS_VAR=        PKG_OPTIONS.zenity
PKG_SUPPORTED_OPTIONS=  webkit
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mwebkit)
.include "../../www/webkit-gtk/buildlink3.mk"
.endif
