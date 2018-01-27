# $NetBSD: buildlink3.mk,v 1.6 2014/08/29 14:10:28 szptvlfn Exp $

BUILDLINK_TREE+=	hs-storablevector

.if !defined(HS_STORABLEVECTOR_BUILDLINK3_MK)
HS_STORABLEVECTOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-storablevector+=	hs-storablevector>=0.2.7
BUILDLINK_ABI_DEPENDS.hs-storablevector+=	hs-storablevector>=0.2.7.2
BUILDLINK_PKGSRCDIR.hs-storablevector?=		../../wip/hs-storablevector

.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../wip/hs-non-negative/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.include "../../wip/hs-utility-ht/buildlink3.mk"
.endif	# HS_STORABLEVECTOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-storablevector
