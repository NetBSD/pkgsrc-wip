# $NetBSD: buildlink3.mk,v 1.2 2010/12/30 08:49:24 phonohawk Exp $

BUILDLINK_TREE+=	hs-regional-pointers

.if !defined(HS_REGIONAL_POINTERS_BUILDLINK3_MK)
HS_REGIONAL_POINTERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regional-pointers+=	hs-regional-pointers>=0.5
BUILDLINK_PKGSRCDIR.hs-regional-pointers?=	../../wip/hs-regional-pointers

.include "../../wip/hs-base-unicode-symbols/buildlink3.mk"
.include "../../wip/hs-monad-peel/buildlink3.mk"
.include "../../wip/hs-regions/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_REGIONAL_POINTERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regional-pointers
