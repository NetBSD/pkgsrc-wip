# $NetBSD$

BUILDLINK_TREE+=	libdoom-umapinfo

.if !defined(LIBDOOM_UMAPINFO_BUILDLINK3_MK)
LIBDOOM_UMAPINFO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdoom-umapinfo+=	libdoom-umapinfo>=0.8.1
BUILDLINK_PKGSRCDIR.libdoom-umapinfo?=		../../wip/libdoom-umapinfo
.endif	# LIBDOOM_UMAPINFO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdoom-umapinfo
