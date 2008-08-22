# $NetBSD: options.mk,v 1.1.1.1 2008/08/22 05:18:49 phonohawk Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtk2hs

PKG_SUPPORTED_OPTIONS=	\
	libglade \
	gconf \
	sourceview \
	firefox \
	cairo \
	svg \
	opengl \
	gnomevfs \
	gstreamer

PKG_SUGGESTED_OPTIONS=	\
	libglade \
	gconf \
	sourceview \
	cairo \
	svg \
	opengl \
	gnomevfs \
	gstreamer

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibglade)
.include "../../devel/libglade/buildlink3.mk"
PLIST_SRC+= PLIST.libglade
.endif

.if !empty(PKG_OPTIONS:Mgconf)
.include "../../devel/GConf/buildlink3.mk"
PLIST_SRC+= PLIST.gconf
.endif

.if !empty(PKG_OPTIONS:Msourceview)
.include "../../x11/gtksourceview/buildlink3.mk"
PLIST_SRC+= PLIST.sourceview
.endif

.if !empty(PKG_OPTIONS:Mfirefox)
.include "../../www/firefox/buildlink3.mk"
PLIST_SRC+= PLIST.mozembed
.endif

.if !empty(PKG_OPTIONS:Mcairo)
.include "../../graphics/cairo/buildlink3.mk"
PLIST_SRC+= PLIST.cairo
.endif

.if !empty(PKG_OPTIONS:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
PLIST_SRC+= PLIST.svgcairo
.endif

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/gtkglext/buildlink3.mk"
PLIST_SRC+= PLIST.gtkglext
.endif

.if !empty(PKG_OPTIONS:Mgnomevfs)
.include "../../sysutils/gnome-vfs/buildlink3.mk"
PLIST_SRC+= PLIST.gnomevfs
.endif

.if !empty(PKG_OPTIONS:Mgstreamer)
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
PLIST_SRC+= PLIST.gstreamer
.endif
