# $NetBSD: buildlink3.mk,v 1.7 2013/01/15 09:24:49 phonohawk Exp $

BUILDLINK_TREE+=	hs-QuickCheck

.if !defined(HS_QUICKCHECK_BUILDLINK3_MK)
HS_QUICKCHECK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-QuickCheck+=	hs-QuickCheck>=2.5.1
BUILDLINK_PKGSRCDIR.hs-QuickCheck?=	../../wip/hs-QuickCheck

.include "../../wip/hs-random/buildlink3.mk"
.endif	# HS_QUICKCHECK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-QuickCheck
