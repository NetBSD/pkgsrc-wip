# $NetBSD: buildlink3.mk,v 1.3 2010/11/02 16:02:15 phonohawk Exp $

BUILDLINK_TREE+=	hs-QuickCheck

.if !defined(HS_QUICKCHECK_BUILDLINK3_MK)
HS_QUICKCHECK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-QuickCheck+=	hs-QuickCheck>=2.3.0.2
BUILDLINK_PKGSRCDIR.hs-QuickCheck?=	../../wip/hs-QuickCheck

.include "../../wip/hs-mtl/buildlink3.mk"
.endif	# HS_QUICKCHECK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-QuickCheck
