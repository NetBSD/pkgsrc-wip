# $NetBSD: buildlink3.mk,v 1.81 2020/11/05 09:07:13 ryoon Exp $

BUILDLINK_TREE+=	webkit-gtk4

.if !defined(WEBKIT_GTK_BUILDLINK3_MK)
WEBKIT_GTK4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.webkit-gtk4+=	webkit-gtk4>=2.8
BUILDLINK_ABI_DEPENDS.webkit-gtk4?=	webkit-gtk4>=2.30.2
BUILDLINK_PKGSRCDIR.webkit-gtk4?=	../../wip/webkit-gtk4

# This is necessary to match the package requirement.
GCC_REQD+=	7.3

pkgbase := webkit-gtk4
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.webkit-gtk4:Menchant)
.include "../../textproc/enchant2/buildlink3.mk"
.endif

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../wip/gtk4/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif # WEBKIT_GTK4_BUILDLINK3_MK

BUILDLINK_TREE+=	-webkit-gtk4
