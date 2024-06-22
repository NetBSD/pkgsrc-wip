# $NetBSD$

BUILDLINK_TREE+=	libbacktrace

.if !defined(LIBBACKTRACE_BUILDLINK3_MK)
LIBBACKTRACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbacktrace+=	libbacktrace>=1.0.0
BUILDLINK_PKGSRCDIR.libbacktrace?=	../../wip/libbacktrace

.endif	# LIBBACKTRACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbacktrace
