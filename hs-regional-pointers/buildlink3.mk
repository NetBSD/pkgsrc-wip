# $NetBSD: buildlink3.mk,v 1.6 2014/08/29 14:10:28 szptvlfn Exp $

BUILDLINK_TREE+=	hs-regional-pointers

.if !defined(HS_REGIONAL_POINTERS_BUILDLINK3_MK)
HS_REGIONAL_POINTERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regional-pointers+=	hs-regional-pointers>=0.6
BUILDLINK_ABI_DEPENDS.hs-regional-pointers+=	hs-regional-pointers>=0.6
BUILDLINK_PKGSRCDIR.hs-regional-pointers?=	../../wip/hs-regional-pointers

.include "../../devel/hs-base-unicode-symbols/buildlink3.mk"
.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../wip/hs-regions/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_REGIONAL_POINTERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regional-pointers
