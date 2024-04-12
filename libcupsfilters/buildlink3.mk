# $NetBSD$

BUILDLINK_TREE+=	libcupsfilters

.if !defined(LIBCUPSFILTERS_BUILDLINK3_MK)
LIBCUPSFILTERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcupsfilters+=	libcupsfilters>=2.0.0
BUILDLINK_ABI_DEPENDS.libcupsfilters+=	libcupsfilters>=2.0.0
BUILDLINK_PKGSRCDIR.libcupsfilters?=	../../wip/libcupsfilters

pkgbase := libcupsfilters
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.libcupsfilters:Mdbus}
.include "../../sysutils/dbus/buildlink3.mk"
.endif

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../print/libcups/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/qpdf/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.endif # LIBCUPSFILTERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcupsfilters
