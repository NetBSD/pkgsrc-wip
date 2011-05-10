# $NetBSD: buildlink3.mk,v 1.3 2011/05/10 23:35:47 phonohawk Exp $

BUILDLINK_TREE+=	hs-regional-pointers

.if !defined(HS_REGIONAL_POINTERS_BUILDLINK3_MK)
HS_REGIONAL_POINTERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regional-pointers+=	hs-regional-pointers>=0.6
BUILDLINK_PKGSRCDIR.hs-regional-pointers?=	../../wip/hs-regional-pointers

.include "../../wip/hs-base-unicode-symbols/buildlink3.mk"
.include "../../wip/hs-monad-control/buildlink3.mk"
.include "../../wip/hs-regions/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_REGIONAL_POINTERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regional-pointers
