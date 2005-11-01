# $NetBSD: options.mk,v 1.1 2005/11/01 11:54:44 leonardschmidt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bmpx
PKG_SUPPORTED_OPTIONS=	gui
PKG_SUGGESTED_OPTIONS=	gui

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgui)
BUILDLINK_DEPENDS.glib2+=	glib2>=2.8.0
BUILDLINK_DEPENDS.libglade2+=	libglade2>=2.5.1

.  include "../../devel/glib2/buildlink3.mk"
.  include "../../devel/libglade2/buildlink3.mk"
.  include "../../devel/pango/buildlink3.mk"
.  include "../../graphics/cairo/buildlink3.mk"
.  include "../../textproc/libxml2/buildlink3.mk"
.  include "../../x11/gtk2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gui
.else
CONFIGURE_ARGS+=	--disable-gui
.endif
