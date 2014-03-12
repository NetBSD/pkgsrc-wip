# $NetBSD: buildlink3.mk,v 1.3 2014/03/12 23:09:15 szptvlfn Exp $

BUILDLINK_TREE+=	hs-ghc-mtl

.if !defined(HS_GHC_MTL_BUILDLINK3_MK)
HS_GHC_MTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ghc-mtl+=	hs-ghc-mtl>=1.1.0
BUILDLINK_PKGSRCDIR.hs-ghc-mtl?=	../../wip/hs-ghc-mtl

.include "../../wip/hs-exceptions/buildlink3.mk"
.include "../../wip/hs-extensible-exceptions/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.endif	# HS_GHC_MTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ghc-mtl
