# $NetBSD: buildlink3.mk,v 1.3 2011/07/08 08:26:09 phonohawk Exp $

BUILDLINK_TREE+=	hs-data-accessor

.if !defined(HS_DATA_ACCESSOR_BUILDLINK3_MK)
HS_DATA_ACCESSOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-data-accessor+=	hs-data-accessor>=0.2
BUILDLINK_PKGSRCDIR.hs-data-accessor?=	../../wip/hs-data-accessor

.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_DATA_ACCESSOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-data-accessor
