# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/11/02 17:03:38 phonohawk Exp $

BUILDLINK_TREE+=	hs-regional-pointers

.if !defined(HS_REGIONAL_POINTERS_BUILDLINK3_MK)
HS_REGIONAL_POINTERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regional-pointers+=	hs-regional-pointers>=0.4
BUILDLINK_PKGSRCDIR.hs-regional-pointers?=	../../wip/hs-regional-pointers

.include "../../wip/hs-base-unicode-symbols/buildlink3.mk"
.include "../../wip/hs-MonadCatchIO-transformers/buildlink3.mk"
.include "../../wip/hs-regions/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_REGIONAL_POINTERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regional-pointers
