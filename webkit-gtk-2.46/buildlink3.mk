# $NetBSD: buildlink3.mk,v 1.93 2022/11/23 16:19:06 adam Exp $

BUILDLINK_TREE+=	webkit-gtk

.if !defined(WEBKIT_GTK_BUILDLINK3_MK)
WEBKIT_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.webkit-gtk+=	webkit-gtk>=2.8
BUILDLINK_ABI_DEPENDS.webkit-gtk?=	webkit-gtk>=2.36.8nb1
BUILDLINK_PKGSRCDIR.webkit-gtk?=	../../wip/webkit-gtk-2.46

# This is necessary to match the package requirement.
GCC_REQD+=	8

pkgbase := webkit-gtk
.include "../../mk/pkg-build-options.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # WEBKIT_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-webkit-gtk
