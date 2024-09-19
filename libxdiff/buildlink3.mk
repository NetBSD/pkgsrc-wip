# $NetBSD$

BUILDLINK_TREE+=	libxdiff

.if !defined(LIBXDIFF_BUILDLINK3_MK)
LIBXDIFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxdiff+=	libxdiff>=0.23
BUILDLINK_PKGSRCDIR.libxdiff?=		../../wip/libxdiff
.endif	# LIBXDIFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxdiff
