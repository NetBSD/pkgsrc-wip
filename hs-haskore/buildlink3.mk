# $NetBSD: buildlink3.mk,v 1.3 2014/05/15 21:49:08 szptvlfn Exp $

BUILDLINK_TREE+=	hs-haskore

.if !defined(HS_HASKORE_BUILDLINK3_MK)
HS_HASKORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-haskore+=	hs-haskore>=0.1.0.2
BUILDLINK_PKGSRCDIR.hs-haskore?=	../../wip/hs-haskore

.include "../../wip/hs-data-accessor/buildlink3.mk"
.include "../../wip/hs-event-list/buildlink3.mk"
.include "../../wip/hs-haskell-src/buildlink3.mk"
.include "../../wip/hs-HUnit/buildlink3.mk"
.include "../../wip/hs-markov-chain/buildlink3.mk"
.include "../../wip/hs-midi/buildlink3.mk"
.include "../../wip/hs-non-negative/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.include "../../wip/hs-utility-ht/buildlink3.mk"
.endif	# HS_HASKORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-haskore
