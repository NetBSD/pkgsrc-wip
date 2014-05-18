# $NetBSD: buildlink3.mk,v 1.4 2014/05/18 21:33:29 szptvlfn Exp $

BUILDLINK_TREE+=	hs-quickcheck-instances

.if !defined(HS_QUICKCHECK_INSTANCES_BUILDLINK3_MK)
HS_QUICKCHECK_INSTANCES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-quickcheck-instances+=	hs-quickcheck-instances>=0.3.2
BUILDLINK_PKGSRCDIR.hs-quickcheck-instances?=	../../wip/hs-quickcheck-instances

.include "../../wip/hs-QuickCheck/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_QUICKCHECK_INSTANCES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-quickcheck-instances
