# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/01/24 09:40:28 jihbed Exp $

BUILDLINK_TREE+=	libode

.if !defined(LIBODE_BUILDLINK3_MK)
LIBODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libode+=	libode>=0.11.1
BUILDLINK_PKGSRCDIR.libode?=	../../wip/libode
.endif	# LIBODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libode
