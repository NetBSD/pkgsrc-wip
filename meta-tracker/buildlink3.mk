# $NetBSD: buildlink3.mk,v 1.5 2014/11/25 13:20:15 thomasklausner Exp $

BUILDLINK_TREE+=	meta-tracker

.if !defined(META_TRACKER_BUILDLINK3_MK)
META_TRACKER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.meta-tracker+=	meta-tracker>=0.9.0
BUILDLINK_ABI_DEPENDS.meta-tracker+=	meta-tracker>=0.9.38
BUILDLINK_PKGSRCDIR.meta-tracker?=	../../wip/meta-tracker

pkgbase := meta-tracker
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.meta-tracker:Mgstreamer)
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.elif !empty(PKG_BUILD_OPTIONS.meta-tracker:Mxine)
.include "../../multimedia/xine-lib/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.meta-tracker:Mdoc)
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.meta-tracker:Mtests)
.include "../../lang/python/application.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.meta-tracker:Mhal)
.include "../../sysutils/hal/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.meta-tracker:Munac)
.include "../../textproc/unac/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.meta-tracker:Menca)
.include "../../textproc/enca/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.meta-tracker:Mgnome)
.include "../../devel/libgee/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../wip/gnome-keyring/buildlink3.mk"
#.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.meta-tracker:Mpdf)
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.meta-tracker:Mjpeg)
.include "../../mk/jpeg.buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.meta-tracker:Mtiff)
.include "../../graphics/tiff/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.meta-tracker:Mvorbis)
.include "../../audio/libvorbis/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.meta-tracker:Mflac)
.include "../../audio/flac/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.meta-tracker:Mgsf)
.include "../../devel/libgsf/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.meta-tracker:Mplaylist)
.include "../../multimedia/totem-pl-parser/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.meta-tracker:Mrss)
.include "../../wip/libgrss/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.meta-tracker:Mevolution)
#.include "../../mail/evolution/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.meta-tracker:Mnautilus)
.include "../../sysutils/nautilus/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.meta-tracker:Mmp3)
.include "../../audio/id3lib/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.meta-tracker:Mxmp)
.include "../../devel/exempi/buildlink3.mk"
.endif

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.endif	# META_TRACKER_BUILDLINK3_MK

BUILDLINK_TREE+=	-meta-tracker
