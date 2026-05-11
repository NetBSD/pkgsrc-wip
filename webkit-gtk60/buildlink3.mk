# $NetBSD$

BUILDLINK_TREE+=	webkit-gtk60

.if !defined(WEBKIT_GTK60_BUILDLINK3_MK)
WEBKIT_GTK60_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.webkit-gtk60+=	webkit-gtk60>=2.50.6
BUILDLINK_ABI_DEPENDS.webkit-gtk60?=	webkit-gtk60>=2.50.6
BUILDLINK_PKGSRCDIR.webkit-gtk60?=	../../wip/webkit-gtk60

GCC_REQD+=	11

pkgbase := webkit-gtk60
.include "../../mk/pkg-build-options.mk"

.include "../../textproc/enchant2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/graphene/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif # WEBKIT_GTK60_BUILDLINK3_MK

BUILDLINK_TREE+=	-webkit-gtk60
