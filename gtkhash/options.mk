# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.gtkhash
PKG_OPTIONS_REQUIRED_GROUPS=	gtk
PKG_OPTIONS_GROUP.gtk=		gtk2 gtk3
PKG_SUPPORTED_OPTIONS=		caja nautilus thunar
PKG_SUGGESTED_OPTIONS=		gtk3

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	caja
PLIST_VARS+=	nautilus
PLIST_VARS+=	thunar

#
# Use GTK+ version 2
#
.if !empty(PKG_OPTIONS:Mgtk2)
CONFIGURE_ARGS+=	--with-gtk=2.0
.include "../../x11/gtk2/buildlink3.mk"
.endif

#
# Use GTK+ version 3 (upstream default)
#
.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=	--with-gtk=3.0
.include "../../x11/gtk3/buildlink3.mk"
.endif

#
# Build the optional Caja extension
#
.if !empty(PKG_OPTIONS:Mcaja)
PLIST.caja=		yes
CONFIGURE_ARGS+=	--enable-caja
.include "../../sysutils/caja/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-caja
.endif

#
# Build the optional Nautilus extension
#
.if !empty(PKG_OPTIONS:Mnautilus)
PLIST.nautilus=		yes
CONFIGURE_ARGS+=	--enable-nautilus
.include "../../sysutils/nautilus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nautilus
.endif

#
# Build the optional Thunar extension
#
.if !empty(PKG_OPTIONS:Mthunar)
PLIST.thunar=		yes
CONFIGURE_ARGS+=	--enable-thunar
.include "../../sysutils/xfce4-thunar/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-thunar
.endif
