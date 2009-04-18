# $NetBSD: options.mk,v 1.1.1.1 2009/04/18 00:24:20 jihbed Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libanaculus-sharp

PKG_SUPPORTED_OPTIONS=	gtk-sharp
PKG_SUGGESTED_OPTIONS=    gtk-sharp

.include "../../mk/bsd.options.mk"

###
### Enable Gtk-Sharp Support
###
.if !empty(PKG_OPTIONS:Mgtk-sharp)
CONFIGURE_ARGS+=	--enable-gtk-sharp
.include "../../x11/gtk-sharp/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gtk-sharp
.endif
