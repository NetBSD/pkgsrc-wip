# $NetBSD$

BUILDLINK_TREE+=	liburing

.if !defined(LIBURING_BUILDLINK3_MK)
LIBURING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liburing+=	liburing>=2.3
BUILDLINK_PKGSRCDIR.liburing?=		../../wip/liburing
.endif	# LIBURING_BUILDLINK3_MK

BUILDLINK_TREE+=	-liburing
