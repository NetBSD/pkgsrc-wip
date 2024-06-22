# $NetBSD$

BUILDLINK_TREE+=	libstacktrace

.if !defined(LIBSTACKTRACE_BUILDLINK3_MK)
LIBSTACKTRACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libstacktrace+=	libstacktrace>=1.0.0
BUILDLINK_PKGSRCDIR.libstacktrace?=	../../wip/libstacktrace

.endif	# LIBSTACKTRACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libstacktrace
