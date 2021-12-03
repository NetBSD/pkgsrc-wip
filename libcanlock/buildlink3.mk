# $NetBSD$

BUILDLINK_TREE+=	libcanlock

.if !defined(LIBCANLOCK_BUILDLINK3_MK)
LIBCANLOCK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcanlock+=	libcanlock>=3.0.0
BUILDLINK_PKGSRCDIR.libcanlock?=	../../wip/libcanlock
.endif	# LIBCANLOCK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcanlock
