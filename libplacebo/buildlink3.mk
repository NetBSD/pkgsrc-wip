# $NetBSD$

BUILDLINK_TREE+=	libplacebo

.if !defined(LIBPLACEBO_BUILDLINK3_MK)
LIBPLACEBO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libplacebo+=	libplacebo>=6.338.1
BUILDLINK_PKGSRCDIR.libplacebo?=	../../wip/libplacebo

.include "../../devel/xxhash/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/vulkan-headers/buildlink3.mk"
.endif	# LIBPLACEBO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libplacebo
