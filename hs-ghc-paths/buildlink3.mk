# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/08 09:51:57 phonohawk Exp $

BUILDLINK_TREE+=	hs-ghc-paths

.if !defined(HS_GHC_PATHS_BUILDLINK3_MK)
HS_GHC_PATHS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ghc-paths+=	hs-ghc-paths>=0.1
BUILDLINK_PKGSRCDIR.hs-ghc-paths?=	../../wip/hs-ghc-paths
.endif	# HS_GHC_PATHS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ghc-paths
