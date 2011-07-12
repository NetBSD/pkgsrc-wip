# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/12 04:15:47 phonohawk Exp $

BUILDLINK_TREE+=	hs-hint

.if !defined(HS_HINT_BUILDLINK3_MK)
HS_HINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hint+=	hs-hint>=0.3
BUILDLINK_PKGSRCDIR.hs-hint?=	../../wip/hs-hint

.include "../../wip/hs-MonadCatchIO-mtl/buildlink3.mk"
.include "../../wip/hs-ghc-mtl/buildlink3.mk"
.include "../../wip/hs-ghc-paths/buildlink3.mk"
.include "../../wip/hs-haskell-src/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-utf8-string/buildlink3.mk"
.endif	# HS_HINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hint
