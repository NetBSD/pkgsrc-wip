# $NetBSD$

BUILDLINK_TREE+=	libyuv-git

.if !defined(LIBYUV_GIT_BUILDLINK3_MK)
LIBYUV_GIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libyuv-git+=	libyuv-git>=0
BUILDLINK_PKGSRCDIR.libyuv-git?=	../../wip/libyuv-git
.endif	# LIBYUV_GIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libyuv-git
