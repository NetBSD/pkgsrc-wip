# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/03/25 18:43:42 jihbed Exp $

BUILDLINK_TREE+=	libcuba

.if !defined(LIBCUBA_BUILDLINK3_MK)
LIBCUBA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcuba+=	libcuba>=2.1
BUILDLINK_PKGSRCDIR.libcuba?=	../../wip/libcuba
.endif	# LIBCUBA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcuba
