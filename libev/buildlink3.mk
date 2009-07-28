# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/07/28 21:39:35 jtonio Exp $

BUILDLINK_TREE+=	libev

.if !defined(LIBEV_BUILDLINK3_MK)
LIBEV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libev+=	libev>=3.7
BUILDLINK_PKGSRCDIR.libev?=	../../wip/libev
.endif	# LIBEV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libev
