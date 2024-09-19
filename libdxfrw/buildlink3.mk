# $NetBSD$

BUILDLINK_TREE+=	libdxfrw

.if !defined(LIBDXFRW_BUILDLINK3_MK)
LIBDXFRW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdxfrw+=	libdxfrw>=0.5.12
BUILDLINK_PKGSRCDIR.libdxfrw?=		../../wip/libdxfrw
.endif	# LIBDXFRW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdxfrw
