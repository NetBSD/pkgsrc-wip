# $NetBSD$

BUILDLINK_TREE+=	libvips

.if !defined(LIBVIPS_BUILDLINK3_MK)
LIBVIPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvips+=	libvips>=8.16.0
BUILDLINK_PKGSRCDIR.libvips?=	../../wip/libvips

#.include "../../devel/zlib/buildlink3.mk"
#.include "../../graphics/libexif/buildlink3.mk"
#.include "../../graphics/libheif/buildlink3.mk"
#.include "../../graphics/libjxl/buildlink3.mk"
#.include "../../graphics/librsvg/buildlink3.mk"
#.include "../../graphics/libwebp/buildlink3.mk"
#.include "../../graphics/openexr/buildlink3.mk"
#.include "../../graphics/openjpeg/buildlink3.mk"
#.include "../../graphics/png/buildlink3.mk"
#.include "../../print/poppler/buildlink3.mk"
#.include "../../textproc/expat/buildlink3.mk"
#.include "../../devel/glib2/buildlink3.mk"
#.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBVIPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvips
