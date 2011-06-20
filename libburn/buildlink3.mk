# $NetBSD: buildlink3.mk,v 1.2 2011/06/20 20:02:52 ryo-on Exp $

BUILDLINK_TREE+=	libburn

.if !defined(LIBBURN_BUILDLINK3_MK)
LIBBURN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libburn+=	libburn>=1.1.0
BUILDLINK_PKGSRCDIR.libburn?=	../../wip/libburn
.endif	# LIBBURN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libburn
