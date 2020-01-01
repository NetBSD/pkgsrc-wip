# $NetBSD$

BUILDLINK_TREE+=	libmpack

.if !defined(LIBMPACK_BUILDLINK3_MK)
LIBMPACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmpack+=	libmpack>=1.0.0
BUILDLINK_PKGSRCDIR.libmpack?=		../../wip/libmpack
.endif	# LIBMPACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmpack
