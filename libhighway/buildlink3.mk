# $NetBSD$

BUILDLINK_TREE+=	libhighway

.if !defined(LIBHIGHWAY_BUILDLINK3_MK)
LIBHIGHWAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhighway+=	libhighway>=0.12.2
BUILDLINK_PKGSRCDIR.libhighway?=	../../wip/libhighway

.endif	# LIBHIGHWAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libhighway
