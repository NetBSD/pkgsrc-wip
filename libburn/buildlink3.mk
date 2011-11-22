# $NetBSD: buildlink3.mk,v 1.4 2011/11/22 17:09:03 ryo-on Exp $

BUILDLINK_TREE+=	libburn

.if !defined(LIBBURN_BUILDLINK3_MK)
LIBBURN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libburn+=	libburn>=1.1.8
BUILDLINK_PKGSRCDIR.libburn?=	../../wip/libburn
.endif	# LIBBURN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libburn
