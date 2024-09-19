# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:13 szptvlfn Exp $

BUILDLINK_TREE+=	hs-ghc-syb-utils

.if !defined(HS_GHC_SYB_UTILS_BUILDLINK3_MK)
HS_GHC_SYB_UTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ghc-syb-utils+=	hs-ghc-syb-utils>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-ghc-syb-utils+=	hs-ghc-syb-utils>=0.2.1.0
BUILDLINK_PKGSRCDIR.hs-ghc-syb-utils?=		../../wip/hs-ghc-syb-utils

.include "../../devel/hs-syb/buildlink3.mk"
.endif	# HS_GHC_SYB_UTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ghc-syb-utils
