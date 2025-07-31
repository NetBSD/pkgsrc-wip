# $NetBSD$

BUILDLINK_TREE+=	libtatsu

.if !defined(LIBTATSU_BUILDLINK3_MK)
LIBTATSU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtatsu+=	libtatsu>=1.0.5
BUILDLINK_PKGSRCDIR.libtatsu?=		../../wip/libtatsu

.include "../../textproc/libplist/buildlink3.mk"
.endif	# LIBTATSU_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtatsu
