# $NetBSD: buildlink3.mk,v 1.2 2013/11/05 13:16:17 szptvlfn Exp $

BUILDLINK_TREE+=	hs-lifted-base

.if !defined(HS_LIFTED_BASE_BUILDLINK3_MK)
HS_LIFTED_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lifted-base+=	hs-lifted-base>=0.2.1.1
BUILDLINK_PKGSRCDIR.hs-lifted-base?=	../../wip/hs-lifted-base

.include "../../wip/hs-base-unicode-symbols/buildlink3.mk"
.include "../../wip/hs-monad-control/buildlink3.mk"
.include "../../wip/hs-transformers-base/buildlink3.mk"
.endif	# HS_LIFTED_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lifted-base
