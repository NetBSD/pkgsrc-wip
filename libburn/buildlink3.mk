# $NetBSD: buildlink3.mk,v 1.3 2011/08/09 13:46:56 ryo-on Exp $

BUILDLINK_TREE+=	libburn

.if !defined(LIBBURN_BUILDLINK3_MK)
LIBBURN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libburn+=	libburn>=1.1.4
BUILDLINK_PKGSRCDIR.libburn?=	../../wip/libburn
.endif	# LIBBURN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libburn
