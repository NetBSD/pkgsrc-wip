# $NetBSD$

BUILDLINK_TREE+=	libzippp

.if !defined(LIBZIPPP_BUILDLINK3_MK)
LIBZIPPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libzippp+=	libzippp>=6.1
BUILDLINK_ABI_DEPENDS.libzippp+=	libzippp>=7.0
BUILDLINK_PKGSRCDIR.libzippp?=		../../wip/libzippp

.endif	# LIBZIPPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libzippp
