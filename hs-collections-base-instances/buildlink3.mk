# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/11/14 08:33:26 phonohawk Exp $

BUILDLINK_TREE+=	hs-collections-base-instances

.if !defined(HS_COLLECTIONS_BASE_INSTANCES_BUILDLINK3_MK)
HS_COLLECTIONS_BASE_INSTANCES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-collections-base-instances+=	hs-collections-base-instances>=1.0.0
BUILDLINK_PKGSRCDIR.hs-collections-base-instances?=	../../wip/hs-collections-base-instances

.include "../../wip/hs-collections-api/buildlink3.mk"
.endif	# HS_COLLECTIONS_BASE_INSTANCES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-collections-base-instances
