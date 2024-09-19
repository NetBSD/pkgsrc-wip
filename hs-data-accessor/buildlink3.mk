# $NetBSD: buildlink3.mk,v 1.6 2014/08/29 14:10:11 szptvlfn Exp $

BUILDLINK_TREE+=	hs-data-accessor

.if !defined(HS_DATA_ACCESSOR_BUILDLINK3_MK)
HS_DATA_ACCESSOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-data-accessor+=	hs-data-accessor>=0.2.2
BUILDLINK_ABI_DEPENDS.hs-data-accessor+=	hs-data-accessor>=0.2.2.3
BUILDLINK_PKGSRCDIR.hs-data-accessor?=		../../wip/hs-data-accessor

.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_DATA_ACCESSOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-data-accessor
