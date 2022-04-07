# $NetBSD$

BUILDLINK_TREE+=	lapinotte-util

.if !defined(LAPINOTTE_UTIL_BUILDLINK3_MK)
LAPINOTTE_UTIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lapinotte-util+=	lapinotte-util>=0.0nb20220407
BUILDLINK_PKGSRCDIR.lapinotte-util?=	../../wip/lapinott-util-git
BUILDLINK_DEPMETHOD.lapinotte-util?=	build

.include "../../devel/boost-libs/buildlink3.mk"
.endif	# LAPINOTTE_UTIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-lapinotte-util
