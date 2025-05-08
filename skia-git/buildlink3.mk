# $NetBSD$

BUILDLINK_TREE+=	skia

.if !defined(SKIA_BUILDLINK3_MK)
SKIA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.skia+=	skia>=129nb20250507
BUILDLINK_PKGSRCDIR.skia?=	../../wip/skia-git

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/libjpeg-turbo/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif	# SKIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-skia
