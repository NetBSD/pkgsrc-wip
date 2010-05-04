# $NetBSD: options.mk,v 1.2 2010/05/04 13:14:19 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.oxim-setup
PKG_SUPPORTED_OPTIONS=	gtk qt
PKG_SUGGESTED_OPTIONS=	gtk

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gtk qt

.if !empty(PKG_OPTIONS:Mgtk)
CONFIGURE_ARGS+=	--enable-setup-gtk
.include "../../x11/gtk2/buildlink3.mk"
PLIST.gtk=	yes
.else
CONFIGURE_ARGS+=	--disable-setup-gtk
.endif

.if !empty(PKG_OPTIONS:Mqt)
CONFIGURE_ARGS+=	--enable-setup-qt3
.include "../../x11/qt3-libs/buildlink3.mk"
PLIST.qt=	yes
.else
CONFIGURE_ARGS+=	--disable-setup-qt3
.include "../../x11/qt3-libs/buildlink3.mk"
.endif
