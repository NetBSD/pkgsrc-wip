# $NetBSD$

BUILDLINK_TREE+=	libyuv

.if !defined(LIBYUV_BUILDLINK3_MK)
LIBYUV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libyuv+=	libyuv>=git
BUILDLINK_PKGSRCDIR.libyuv?=	../../wip/libyuv-git
.endif	# LIBYUV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libyuv
