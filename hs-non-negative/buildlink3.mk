# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/09/23 06:08:11 phonohawk Exp $

BUILDLINK_TREE+=	hs-non-negative

.if !defined(HS_NON_NEGATIVE_BUILDLINK3_MK)
HS_NON_NEGATIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-non-negative+=	hs-non-negative>=0.0.5
BUILDLINK_PKGSRCDIR.hs-non-negative?=	../../wip/hs-non-negative

.include "../../wip/hs-QuickCheck1/buildlink3.mk"
.endif	# HS_NON_NEGATIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-non-negative
