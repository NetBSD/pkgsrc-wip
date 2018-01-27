# $NetBSD: options.mk,v 1.10 2014/11/25 13:20:15 thomasklausner Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.meta-tracker
PKG_SUPPORTED_OPTIONS+=		doc tests hal unac enca libsecret gnome
PKG_OPTIONS_OPTIONAL_GROUPS=	video
PKG_OPTIONS_GROUP.video=	gstreamer xine
PKG_SUPPORTED_OPTIONS+=		pdf xps gif jpeg tiff vorbis flac html gsf playlist
PKG_SUPPORTED_OPTIONS+=		rss evolution firefox # thunderbird -- broken?
PKG_SUPPORTED_OPTIONS+=		nautilus
PKG_SUPPORTED_OPTIONS+=		mp3 taglib xmp

PKG_SUGGESTED_OPTIONS+=		hal unac enca libsecret gnome
PKG_SUGGESTED_OPTIONS+=		pdf xps gif jpeg tiff vorbis flac html gsf playlist
PKG_SUGGESTED_OPTIONS+=		-gstreamer
PKG_SUGGESTED_OPTIONS+=		rss evolution firefox # thunderbird
PKG_SUGGESTED_OPTIONS+=		mp3 taglib xmp
# XXX pbulk complains:
# Cyclic dependency for package:
# meta-tracker-0.16.3nb2
# nautilus-3.16.2
# PKG_SUGGESTED_OPTIONS+=		nautilus

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	${PKG_SUPPORTED_OPTIONS} mplayer totem
PLIST.mplayer=	yes
PLIST.totem=	yes

.if !empty(PKG_OPTIONS:Mgstreamer)
PLIST.gstreamer=	yes
#CONFIGURE_ARGS+=	--enable-gstreamer-tagreadbin
#CONFIGURE_ARGS+=	--enable-gstreamer-helix
CONFIGURE_ARGS+=	--enable-generic-media-extractor=gstreamer
CONFIGURE_ARGS+=	--with-gstreamer-backend

.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mxine)
PLIST.xine=		yes
.include "../../multimedia/xine-lib/buildlink3.mk"
PLIST.mplayer=		yes
PLIST.totem=		yes
.endif

.if !empty(PKG_OPTIONS:Mdoc)
CONFIGURE_ARGS+=	--enable-gtk-doc=yes
# will check later
#PLIST_SRC+=		${PKGDIR}/PLIST ${PKGDIR}/PLIST.doc
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.endif
PLIST_SRC+=		${PKGDIR}/PLIST ${PKGDIR}/PLIST.doc

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

.if !empty(PKG_OPTIONS:Mlibsecret)
.include "../../security/libsecret/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgnome)
PLIST.gnome=		yes
CONFIGURE_ARGS+=	--enable-icon
.include "../../devel/libgee/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../wip/gnome-keyring/buildlink3.mk"
#.include "../../x11/gnome-panel/buildlink3.mk" # XXX remove this when we have gnome-panel3
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-tracker-status-icon=no
CONFIGURE_ARGS+=	--enable-tracker-preferences=no
.endif

### Metadata Extractors:

.if !empty(PKG_OPTIONS:Mxps)
PLIST.xps=		yes
CONFIGURE_ARGS+=	--enable-libgxps
.include "../../print/libgxps/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpdf)
PLIST.pdf=		yes
CONFIGURE_ARGS+=	--enable-poppler
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgif)
PLIST.gif=		yes
.include "../../graphics/giflib/buildlink3.mk"
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
#.include "../../mail/evolution/buildlink3.mk" # XXX when we get evolution updated..
.endif

.if !empty(PKG_OPTIONS:Mthunderbird)
PLIST_SRC+=		${PKGDIR}/PLIST.thunderbird
CONFIGURE_ARGS+=	--with-thunderbird-plugin-dir=${PREFIX}/lib/thunderbird/extensions
DEPENDS+=		thunderbird>=17.0.9:../../mail/thunderbird
.else
CONFIGURE_ARGS+=	--disable-miner-thunderbird
.endif

.if !empty(PKG_OPTIONS:Mfirefox)
PLIST_SRC+=		${PKGDIR}/PLIST.firefox
CONFIGURE_ARGS+=	--with-firefox-plugin-dir=${PREFIX}/lib/firefox/browser/extensions
DEPENDS+=		firefox>=24.0:../../www/firefox
.else
CONFIGURE_ARGS+=	--disable-miner-firefox
.endif

### Plugins:

.if !empty(PKG_OPTIONS:Mnautilus)
PLIST.nautilus=		yes
.include "../../sysutils/nautilus/buildlink3.mk"
.endif

### Writeback:

.if !empty(PKG_OPTIONS:Mmp3)
PLIST.mp3=		yes
.include "../../audio/id3lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mtaglib)
PLIST.taglib=		yes
.include "../../audio/taglib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mxmp)
PLIST.xmp=		yes
CONFIGURE_ARGS+=	--enable-exempi
.include "../../devel/exempi/buildlink3.mk"
.endif
