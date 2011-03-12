# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/03/12 10:43:33 ryo-on Exp $

BUILDLINK_TREE+=	libburn

.if !defined(LIBBURN_BUILDLINK3_MK)
LIBBURN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libburn+=	libburn>=1.0.4.00
BUILDLINK_PKGSRCDIR.libburn?=	../../wip/libburn
.endif	# LIBBURN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libburn
