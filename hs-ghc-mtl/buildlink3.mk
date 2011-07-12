# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/12 04:06:28 phonohawk Exp $

BUILDLINK_TREE+=	hs-ghc-mtl

.if !defined(HS_GHC_MTL_BUILDLINK3_MK)
HS_GHC_MTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ghc-mtl+=	hs-ghc-mtl>=1.0
BUILDLINK_PKGSRCDIR.hs-ghc-mtl?=	../../wip/hs-ghc-mtl

.include "../../wip/hs-MonadCatchIO-mtl/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.endif	# HS_GHC_MTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ghc-mtl
