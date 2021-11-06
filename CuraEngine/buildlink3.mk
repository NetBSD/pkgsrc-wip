# $NetBSD$

BUILDLINK_TREE+=	CuraEngine

.if !defined(CURAENGINE_BUILDLINK3_MK)
CURAENGINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.CuraEngine+=	CuraEngine>=4.11.0
BUILDLINK_PKGSRCDIR.CuraEngine?=	../../wip/CuraEngine

.include "../../devel/protobuf/buildlink3.mk"
.include "../../wip/libArcus/buildlink3.mk"
.endif	# CURAENGINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-CuraEngine
