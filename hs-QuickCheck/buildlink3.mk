# $NetBSD: buildlink3.mk,v 1.2 2009/09/23 05:56:35 phonohawk Exp $

BUILDLINK_TREE+=	hs-QuickCheck

.if !defined(HS_QUICKCHECK_BUILDLINK3_MK)
HS_QUICKCHECK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-QuickCheck+=	hs-QuickCheck>=2.1.0.2nb1
BUILDLINK_PKGSRCDIR.hs-QuickCheck?=	../../wip/hs-QuickCheck

.include "../../wip/hs-mtl/buildlink3.mk"
.endif	# HS_QUICKCHECK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-QuickCheck
