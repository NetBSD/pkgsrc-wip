# $NetBSD: buildlink3.mk,v 1.1 2013/01/15 12:56:00 phonohawk Exp $

BUILDLINK_TREE+=	hs-Cabal

.if !defined(HS_CABAL_BUILDLINK3_MK)
HS_CABAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-Cabal+=	hs-Cabal>=1.16
BUILDLINK_PKGSRCDIR.hs-Cabal?=	../../wip/hs-Cabal
.endif	# HS_CABAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-Cabal
