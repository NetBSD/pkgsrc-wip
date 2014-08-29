# $NetBSD: buildlink3.mk,v 1.12 2014/08/29 14:10:02 szptvlfn Exp $

BUILDLINK_TREE+=	hs-QuickCheck

.if !defined(HS_QUICKCHECK_BUILDLINK3_MK)
HS_QUICKCHECK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-QuickCheck+=	hs-QuickCheck>=2.7.3
BUILDLINK_ABI_DEPENDS.hs-QuickCheck+=	hs-QuickCheck>=2.7.3
BUILDLINK_PKGSRCDIR.hs-QuickCheck?=	../../wip/hs-QuickCheck

.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-tf-random/buildlink3.mk"
.endif	# HS_QUICKCHECK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-QuickCheck
