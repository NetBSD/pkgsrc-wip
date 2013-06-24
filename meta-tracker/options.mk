# $NetBSD: options.mk,v 1.3 2013/06/24 09:38:16 noud4 Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.meta-tracker
PKG_SUPPORTED_OPTIONS+=		doc tests hal unac enca gnome
PKG_OPTIONS_OPTIONAL_GROUPS=	video
PKG_OPTIONS_GROUP.video=	gstreamer xine
PKG_SUPPORTED_OPTIONS+=		pdf jpeg tiff vorbis flac html gsf playlist
PKG_SUPPORTED_OPTIONS+=		rss evolution kmail
PKG_SUPPORTED_OPTIONS+=		nautilus
PKG_SUPPORTED_OPTIONS+=		mp3 xmp

#PKG_SUGGESTED_OPTIONS+=		hal unac enca gnome
#PKG_SUGGESTED_OPTIONS+=		pdf jpeg tiff vorbis flac html gsf playlist
#PKG_SUGGESTED_OPTIONS+=		gstreamer
#PKG_SUGGESTED_OPTIONS+=		rss evolution kmail
#PKG_SUGGESTED_OPTIONS+=		nautilus
#PKG_SUGGESTED_OPTIONS+=		mp3 xmp

.include "../../mk/bsd.options.mk"

PLIST_VARS+=			${PKG_SUPPORTED_OPTIONS} mplayer totem

.if !empty(PKG_OPTIONS:Mgstreamer)
PLIST.gstreamer=	yes
CONFIGURE_ARGS+=	--enable-gstreamer-tagreadbin
CONFIGURE_ARGS+=	--enable-gstreamer-helix
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mxine)
PLIST.xine=		yes
.include "../../multimedia/xine-lib/buildlink3.mk"
.else
PLIST.mplayer=		yes
PLIST.totem=		yes
.endif

.if !empty(PKG_OPTIONS:Mdoc)
CONFIGURE_ARGS+=	--enable-gtk-doc=yes
PLIST_SRC+=		${PKGDIR}/PLIST ${PKGDIR}/PLIST.doc
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mtests)
REPLACE_PYTHON+=	tests/functional-tests/*.py \
			tests/tracker-writeback/01-writeback.py
PLIST.tests=		yes
PLIST_SRC+=		${PKGDIR}/PLIST ${PKGDIR}/PLIST.tests
.include "../../lang/python/application.mk"
.else
CONFIGURE_ARGS+=	--disable-unit-tests
CONFIGURE_ARGS+=	--disable-functional-tests
.endif

.if !empty(PKG_OPTIONS:Mhal)
.include "../../sysutils/hal/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-hal
.endif

.if !empty(PKG_OPTIONS:Munac)
.include "../../textproc/unac/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Menca)
.include "../../textproc/enca/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgnome)
PLIST.gnome=		yes
.include "../../devel/libgee/buildlink3.mk"
.include "../../lang/vala018/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-tracker-status-icon=no
CONFIGURE_ARGS+=	--enable-tracker-preferences=no
.endif

### Metadata Extractors:

.if !empty(PKG_OPTIONS:Mpdf)
PLIST.pdf=		yes
CONFIGURE_ARGS+=	--enable-poppler-glib
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mjpeg)
PLIST.jpeg=		yes
CONFIGURE_ARGS+=	--enable-libjpeg
.include "../../mk/jpeg.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mtiff)
PLIST.tiff=		yes
PLIST.jpeg=		yes
.include "../../graphics/tiff/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
PLIST.vorbis=		yes
CONFIGURE_ARGS+=	--enable-libvorbis
.include "../../audio/libvorbis/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mflac)
PLIST.flac=		yes
CONFIGURE_ARGS+=	--enable-libflac
.include "../../audio/flac/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mhtml)
PLIST.html=		yes
.else
CONFIGURE_ARGS+=	--disable-libxml2
.endif

.if !empty(PKG_OPTIONS:Mgsf)
PLIST.gsf=		yes
.include "../../devel/libgsf/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mplaylist)
PLIST.playlist=		yes
.include "../../multimedia/totem-pl-parser/buildlink3.mk"
.endif

### Data Miners:

.if !empty(PKG_OPTIONS:Mrss)
PLIST.rss=		yes
.include "../../wip/libgrss/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mevolution)
PLIST.evolution=	yes
.include "../../mail/evolution/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mkmail)
PLIST.kmail=		yes
CONFIGURE_ARGS+=	--enable-miner-kmail
.else
CONFIGURE_ARGS+=	--enable-miner-kmail=no
.endif

### Plugins:

.if !empty(PKG_OPTIONS:Mnautilus)
PLIST.nautilus=		yes
.include "../../sysutils/nautilus/buildlink3.mk"
.endif

### Writeback:

.if !empty(PKG_OPTIONS:Mmp3)
.include "../../audio/id3lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mxmp)
PLIST.xmp=		yes
CONFIGURE_ARGS+=	--enable-exempi
.include "../../devel/exempi/buildlink3.mk"
.endif
