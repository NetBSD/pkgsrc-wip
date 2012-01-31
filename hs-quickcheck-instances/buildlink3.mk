# $NetBSD: buildlink3.mk,v 1.2 2012/01/31 13:09:06 phonohawk Exp $

BUILDLINK_TREE+=	hs-quickcheck-instances

.if !defined(HS_QUICKCHECK_INSTANCES_BUILDLINK3_MK)
HS_QUICKCHECK_INSTANCES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-quickcheck-instances+=	hs-quickcheck-instances>=0.2.0
BUILDLINK_PKGSRCDIR.hs-quickcheck-instances?=	../../wip/hs-quickcheck-instances

.include "../../wip/hs-QuickCheck/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.endif	# HS_QUICKCHECK_INSTANCES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-quickcheck-instances
