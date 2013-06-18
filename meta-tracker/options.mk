# $NetBSD: options.mk,v 1.2 2013/06/18 11:36:25 noud4 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.meta-tracker
PKG_SUPPORTED_OPTIONS=	unac gnome
PKG_SUPPORTED_OPTIONS+=	vorbis playlist gstreamer
PKG_SUPPORTED_OPTIONS+=	kmail
#PKG_SUPPORTED_OPTIONS+=	rss	# XXX broken, libgrss lateron..
PKG_SUGGESTED_OPTIONS=	unac gnome
PKG_SUGGESTED_OPTIONS+=	vorbis playlist gstreamer

.include "../../mk/bsd.options.mk"

PLIST_VARS+=			${PKG_SUPPORTED_OPTIONS} mplayer totem

.if !empty(PKG_OPTIONS:Munac)
CONFIGURE_ARGS+=	--enable-unac
.include "../../textproc/unac/buildlink3.mk" 
.endif

.if !empty(PKG_OPTIONS:Mgnome)
PLIST.gnome=		yes
BUILDLINK_API_DEPENDS.libglade+=	libglade>=2.5
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-deskbar-applet
.include "../../devel/libglade/buildlink3.mk"		# XXX gtk
.endif

### Metadata Extractors:

.if !empty(PKG_OPTIONS:Mvorbis)
PLIST.vorbis=		yes
CONFIGURE_ARGS+=	--enable-libvorbis
.include "../../audio/libvorbis/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgstreamer)
PLIST.gstreamer=	yes
CONFIGURE_ARGS+=	--enable-gstreamer-tagreadbin
#CONFIGURE_ARGS+=	--enable-gstreamer-helix	# XXX broken
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.else
PLIST.mplayer=		yes
PLIST.totem=		yes
.endif

.if !empty(PKG_OPTIONS:Mplaylist)
PLIST.playlist=		yes
CONFIGURE_ARGS+=	--enable-playlist
.include "../../multimedia/totem-pl-parser/buildlink3.mk"
.endif

### Plugins:

.if !empty(PKG_OPTIONS:Mkmail)
PLIST.kmail=		yes
CONFIGURE_ARGS+=	--enable-kmail-push-module
.endif

.if !empty(PKG_OPTIONS:Mrss)
PLIST.rss=		yes
CONFIGURE_ARGS+=	--enable-rss-push-module
.endif
