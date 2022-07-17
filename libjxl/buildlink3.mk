# $NetBSD$

BUILDLINK_TREE+=	libjxl

.if !defined(LIBJXL_BUILDLINK3_MK)
LIBJXL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libjxl+=	libjxl>=0.6
BUILDLINK_PKGSRCDIR.libjxl?=	../../wip/libjxl

.include "../../archivers/brotli/buildlink3.mk"
.include "../../graphics/libhighway/buildlink3.mk"
.endif	# LIBJXL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libjxl
