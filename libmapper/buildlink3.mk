# $NetBSD$

BUILDLINK_TREE+=	libmapper

.if !defined(LIBMAPPER_BUILDLINK3_MK)
LIBMAPPER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmapper+=	libmapper>=2.1
BUILDLINK_PKGSRCDIR.libmapper?=		../../wip/libmapper

.include "../../audio/liblo/buildlink3.mk"
.endif	# LIBMAPPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmapper
