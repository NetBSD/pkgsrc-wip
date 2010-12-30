# $NetBSD: buildlink3.mk,v 1.4 2010/12/30 08:43:05 phonohawk Exp $

BUILDLINK_TREE+=	hs-QuickCheck

.if !defined(HS_QUICKCHECK_BUILDLINK3_MK)
HS_QUICKCHECK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-QuickCheck+=	hs-QuickCheck>=2.4
BUILDLINK_PKGSRCDIR.hs-QuickCheck?=	../../wip/hs-QuickCheck

.include "../../wip/hs-mtl/buildlink3.mk"
.endif	# HS_QUICKCHECK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-QuickCheck
