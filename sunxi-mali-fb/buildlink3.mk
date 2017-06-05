# $NetBSD$

BUILDLINK_TREE+=	sunxi-mali-fb

.if !defined(SUNXI_MALI_FB_BUILDLINK3_MK)
SUNXI_MALI_FB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sunxi-mali-fb+=	sunxi-mali-fb>=0
BUILDLINK_PKGSRCDIR.sunxi-mali-fb?=	../../wip/sunxi-mali-fb
BUILDLINK_INCDIRS.sunxi-mali-fb+=	sunxi-mali-fb/include
BUILDLINK_LIBDIRS.sunxi-mali-fb+=	sunxi-mali-fb/lib
.endif	# SUNXI_MALI_FB_BUILDLINK3_MK

BUILDLINK_TREE+=	-sunxi-mali-fb
