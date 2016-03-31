# $NetBSD$

BUILDLINK_TREE+=	libmatemixer

.if !defined(LIBMATEMIXER_BUILDLINK3_MK)
LIBMATEMIXER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmatemixer+=	libmatemixer>=1.12.1
BUILDLINK_PKGSRCDIR.libmatemixer?=	../../wip/libmatemixer

.endif	# LIBMATEMIXER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmatemixer
