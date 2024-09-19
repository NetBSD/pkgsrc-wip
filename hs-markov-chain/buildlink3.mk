# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:26 szptvlfn Exp $

BUILDLINK_TREE+=	hs-markov-chain

.if !defined(HS_MARKOV_CHAIN_BUILDLINK3_MK)
HS_MARKOV_CHAIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-markov-chain+=	hs-markov-chain>=0.0.3
BUILDLINK_ABI_DEPENDS.hs-markov-chain+=	hs-markov-chain>=0.0.3
BUILDLINK_PKGSRCDIR.hs-markov-chain?=	../../wip/hs-markov-chain

.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_MARKOV_CHAIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-markov-chain
