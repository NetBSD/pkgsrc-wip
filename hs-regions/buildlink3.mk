# $NetBSD: buildlink3.mk,v 1.7 2014/08/29 14:10:28 szptvlfn Exp $

BUILDLINK_TREE+=	hs-regions

.if !defined(HS_REGIONS_BUILDLINK3_MK)
HS_REGIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regions+=	hs-regions>=0.9
BUILDLINK_ABI_DEPENDS.hs-regions+=	hs-regions>=0.9
BUILDLINK_PKGSRCDIR.hs-regions?=	../../wip/hs-regions

.include "../../devel/hs-base-unicode-symbols/buildlink3.mk"
.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_REGIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regions
