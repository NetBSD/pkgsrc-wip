# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.yad

PKG_OPTIONS_REQUIRED_GROUPS=	gtk
PKG_OPTIONS_GROUP.gtk=		gtk2 gtk3

PKG_SUGGESTED_OPTIONS=		gtk2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk2)
.include "../../www/webkit24-gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=	--enable-spell
CONFIGURE_ARGS+=	--enable-sourceview
CONFIGURE_ARGS+=	--with-gtk=gtk3
.include "../../textproc/gtkspell3/buildlink3.mk"
.include "../../www/webkit24-gtk3/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
.endif
