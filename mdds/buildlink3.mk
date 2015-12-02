# $NetBSD$

BUILDLINK_TREE+=	mdds

.if !defined(MDDS_BUILDLINK3_MK)
MDDS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mdds+=	mdds>=1.0.0
BUILDLINK_PKGSRCDIR.mdds?=	../../wip/mdds

.include "../../devel/boost-libs/buildlink3.mk"
.endif	# MDDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mdds
