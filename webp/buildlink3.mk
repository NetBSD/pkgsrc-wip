# $NetBSD: buildlink3.mk,v 1.1 2011/10/28 13:32:04 ryo-on Exp $

BUILDLINK_TREE+=	libwebp

.if !defined(LIBWEBP_BUILDLINK3_MK)
LIBWEBP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwebp+=	libwebp>=0.1.3
BUILDLINK_PKGSRCDIR.libwebp?=	../../wip/webp

.endif	# LIBWEBP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwebp
