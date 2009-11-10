# $NetBSD: buildlink3.mk,v 1.5 2009/11/10 09:31:56 phonohawk Exp $

BUILDLINK_TREE+=	hs-Cabal

.if !defined(HS_CABAL_BUILDLINK3_MK)
HS_CABAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-Cabal+=	hs-Cabal>=1.6.0.3
BUILDLINK_PKGSRCDIR.hs-Cabal?=	../../wip/hs-cabal
.endif	# HS_CABAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-Cabal
