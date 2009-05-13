# $NetBSD: buildlink3.mk,v 1.2 2009/05/13 11:05:29 emil_s Exp $

BUILDLINK_TREE+=	hs-cabal

.if !defined(HS_CABAL_BUILDLINK3_MK)
HS_CABAL_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hs-cabal?=		build
BUILDLINK_API_DEPENDS.hs-cabal+=	hs-cabal>=1.6.0.2
BUILDLINK_PKGSRCDIR.hs-cabal?=		../../wip/hs-cabal

.include "../../lang/ghc/buildlink3.mk"
.endif # HS_CABAL_BUILDLINK3_MK

BUILDLINK_TREE+=	hs-cabal
