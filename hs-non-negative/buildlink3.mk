# $NetBSD: buildlink3.mk,v 1.2 2010/11/02 16:07:11 phonohawk Exp $

BUILDLINK_TREE+=	hs-non-negative

.if !defined(HS_NON_NEGATIVE_BUILDLINK3_MK)
HS_NON_NEGATIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-non-negative+=	hs-non-negative>=0.1
BUILDLINK_PKGSRCDIR.hs-non-negative?=	../../wip/hs-non-negative

.include "../../wip/hs-QuickCheck/buildlink3.mk"
.include "../../wip/hs-utility-ht/buildlink3.mk"
.endif	# HS_NON_NEGATIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-non-negative
