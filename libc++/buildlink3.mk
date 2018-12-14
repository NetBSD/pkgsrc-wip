# $NetBSD$

BUILDLINK_TREE+=	libc++

.if !defined(LIBC++_BUILDLINK3_MK)
LIBC++_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libc+++=	libc++>=4.0.0
BUILDLINK_PKGSRCDIR.libc++?=	../../wip/libc++
.endif	# LIBC++_BUILDLINK3_MK

BUILDLINK_TREE+=	-libc++
