# $NetBSD: options.mk,v 1.1.1.1 2009/11/28 11:01:20 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.oxim
PKG_SUPPORTED_OPTIONS=	chewing gtk unicode
PKG_SUGGESTED_OPTIONS=	chewing gtk unicode

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	chewing gtk unicode qt

.if !empty(PKG_OPTIONS:Mchewing)
CONFIGURE_ARGS+=	--enable-chewing-module
.include "../../inputmethod/libchewing/buildlink3.mk"
PLIST.chewing=	yes
.else
CONFIGURE_ARGS+=	--disable-chewing-module
.endif

.if !empty(PKG_OPTIONS:Mgtk)
CONFIGURE_ARGS+=	--enable-gtk-immodule
GTK2_IMMODULES=	yes
.include "../../x11/gtk2/modules.mk"
PLIST.gtk=	yes
.else
CONFIGURE_ARGS+=	--disable-dtk-immodule
.endif

.if !empty(PKG_OPTIONS:Municode)
CONFIGURE_ARGS+=	--enable-unicode-module
PLIST.unicode=	yes
.else
CONFIGURE_ARGS+=	--disable-unicode-module
.endif

.if !empty(PKG_OPTIONS:Mqt)
CONFIGURE_ARGS+=	--enable-qt-immodule
.include "../../x11/qt4-libs/buildlink3.mk"
PLIST.qt=	yes
.else
CONFIGURE_ARGS+=	--disable-qt-immodule
.endif
