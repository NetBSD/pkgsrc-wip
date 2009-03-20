# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:43:39 jsonn Exp $

BUILDLINK_TREE+=	cabal

.if !defined(CABAL_BUILDLINK3_MK)
CABAL_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.cabal?=	build
BUILDLINK_API_DEPENDS.cabal+=	cabal>=1.4.0.2
BUILDLINK_PKGSRCDIR.cabal?=	../../wip/cabal

.include "../../lang/ghc/buildlink3.mk"
.endif # CABAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-cabal
