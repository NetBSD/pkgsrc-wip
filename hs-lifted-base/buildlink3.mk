# $NetBSD: buildlink3.mk,v 1.3 2014/02/13 13:05:44 szptvlfn Exp $

BUILDLINK_TREE+=	hs-lifted-base

.if !defined(HS_LIFTED_BASE_BUILDLINK3_MK)
HS_LIFTED_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lifted-base+=	hs-lifted-base>=0.2.2
BUILDLINK_PKGSRCDIR.hs-lifted-base?=	../../wip/hs-lifted-base

.include "../../wip/hs-base-unicode-symbols/buildlink3.mk"
.include "../../wip/hs-monad-control/buildlink3.mk"
.include "../../wip/hs-transformers-base/buildlink3.mk"
.endif	# HS_LIFTED_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lifted-base
