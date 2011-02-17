# $NetBSD: buildlink3.mk,v 1.6 2011/02/17 14:48:14 phonohawk Exp $

BUILDLINK_TREE+=	hs-haskell-src-exts

.if !defined(HS_HASKELL_SRC_EXTS_BUILDLINK3_MK)
HS_HASKELL_SRC_EXTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-haskell-src-exts+=	hs-haskell-src-exts>=1.10
BUILDLINK_PKGSRCDIR.hs-haskell-src-exts?=	../../wip/hs-haskell-src-exts

.include "../../wip/hs-cpphs/buildlink3.mk"
.endif	# HS_HASKELL_SRC_EXTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-haskell-src-exts
