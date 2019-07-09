# $NetBSD: buildlink3.mk,v 1.17 2013/01/24 21:52:28 wiz Exp $

BUILDLINK_TREE+=	compat32_jpeg

.if !defined(COMPAT32_JPEG_BUILDLINK3_MK)
COMPAT32_JPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compat32_jpeg+=	compat32_jpeg>=8nb1
BUILDLINK_ABI_DEPENDS.compat32_jpeg+=	compat32_jpeg>=9
BUILDLINK_PKGSRCDIR.compat32_jpeg?=	../../wip/jpeg-32
BUILDLINK_LIBDIRS.compat32_jpeg=	lib/32
.endif # COMPAT32_JPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-compat32_jpeg
