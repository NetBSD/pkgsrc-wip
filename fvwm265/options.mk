# $NetBSD: options.mk,v 1.5 2013/01/20 11:16:45 makoto Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.fvwm
PKG_OPTIONS_LEGACY_VARS+=	FVWM2_USE_GTK:gtk
PKG_OPTIONS_LEGACY_VARS+=	FVWM2_USE_RPLAY:rplay
PKG_SUPPORTED_OPTIONS=		fribidi gdk-imlib gnome gtk png rplay svg stroke xrender xcursor xft2
PKG_SUGGESTED_OPTIONS=		fribidi gdk-imlib gnome gtk png rplay svg stroke xrender xcursor xft2

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk

.if !empty(PKG_OPTIONS:Mfribidi)
.  include "../../converters/fribidi/buildlink3.mk"
#DEPENDS+=		fribidi-[0-9]*:../../misc/fribidi
.else
CONFIGURE_ARGS+=	--disable-bidi
.endif

.if !empty(PKG_OPTIONS:Mgdk-imlib)
#.include "../../graphics/gdk-pixbuf/buildlink3.mk"
# not found in pkgsrc yet (?)
.else
CONFIGURE_ARGS+=	--disable-gdk
.endif

.if !empty(PKG_OPTIONS:Mgnome)
.include "../../devel/libgnome/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --disable-gnome
.endif

.if !empty(PKG_OPTIONS:Mgtk)
.  include "../../x11/gtk/buildlink3.mk"
PLIST.gtk=		yes
.else
CONFIGURE_ARGS+=	--without-gtk-prefix
.endif

.if !empty(PKG_OPTIONS:Mpng)
.include "../../graphics/png/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --disable-png
.endif

.if !empty(PKG_OPTIONS:Mrplay)
.  include "../../audio/rplay/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --disable-rsvg
.endif

# libstroke ?
# .if !empty(PKG_OPTIONS:Mstroke)
# .include "../../x11/libXrender/buildlink3.mk"
# .else
# CONFIGURE_ARGS+=        --disable-stroke
# .endif

.if !empty(PKG_OPTIONS:Mxcursor)
CONFIGURE_ARGS+=	--enable-xcursor
.include "../../x11/libXcursor/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xcursor
.endif

.if !empty(PKG_OPTIONS:Mxft2)
CONFIGURE_ARGS+=        --enable-xft
.include "../../x11/libXft/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --disable-xft
.endif

.if !empty(PKG_OPTIONS:Mxrender)
CONFIGURE_ARGS+=        --enable-xrender
.include "../../x11/libXrender/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --disable-xrender
.endif
