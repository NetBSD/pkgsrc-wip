# $NetBSD: buildlink3.mk,v 1.2 2010/12/30 09:05:54 phonohawk Exp $

BUILDLINK_TREE+=	hs-storablevector

.if !defined(HS_STORABLEVECTOR_BUILDLINK3_MK)
HS_STORABLEVECTOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-storablevector+=	hs-storablevector>=0.2
BUILDLINK_PKGSRCDIR.hs-storablevector?=	../../wip/hs-storablevector

.include "../../wip/hs-QuickCheck/buildlink3.mk"
.include "../../wip/hs-non-negative/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.include "../../wip/hs-utility-ht/buildlink3.mk"
.endif	# HS_STORABLEVECTOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-storablevector
