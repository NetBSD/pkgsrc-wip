# $NetBSD: buildlink3.mk,v 1.3 2010/12/30 08:31:08 phonohawk Exp $

BUILDLINK_TREE+=	hs-regions

.if !defined(HS_REGIONS_BUILDLINK3_MK)
HS_REGIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regions+=	hs-regions>=0.8
BUILDLINK_PKGSRCDIR.hs-regions?=	../../wip/hs-regions

.include "../../wip/hs-base-unicode-symbols/buildlink3.mk"
.include "../../wip/hs-monad-peel/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_REGIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regions
