# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/03/11 08:38:37 phonohawk Exp $

BUILDLINK_TREE+=	hs-ghc-syb-utils

.if !defined(HS_GHC_SYB_UTILS_BUILDLINK3_MK)
HS_GHC_SYB_UTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ghc-syb-utils+=	hs-ghc-syb-utils>=0.2.1
BUILDLINK_PKGSRCDIR.hs-ghc-syb-utils?=	../../wip/hs-ghc-syb-utils

.include "../../wip/hs-syb/buildlink3.mk"
.endif	# HS_GHC_SYB_UTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ghc-syb-utils
