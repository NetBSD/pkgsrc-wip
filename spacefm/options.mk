# $NetBSD: Makefile,v 0.3 2018/09/11 14:44:10 andyb Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.spacefm

PKG_OPTIONS_REQUIRED_GROUPS=    gtk
PKG_OPTIONS_GROUP.gtk=          gtk2 gtk3

PKG_SUGGESTED_OPTIONS=  gtk2

PLIST_VARS+=            gtk3
.if !empty(PKG_OPTIONS:Mgtk2)
CONFIGURE_ARGS+=        --enable-default-toolkit=cairo-gtk2
.include "../../x11/gtk2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=        --enable-default-toolkit=cairo-gtk3
.include "../../x11/gtk3/buildlink3.mk"
PLIST.gtk3=             yes
.endif
