# $NetBSD: buildlink3.mk,v 1.5 2014/05/15 21:49:07 szptvlfn Exp $

BUILDLINK_TREE+=	hs-data-accessor

.if !defined(HS_DATA_ACCESSOR_BUILDLINK3_MK)
HS_DATA_ACCESSOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-data-accessor+=	hs-data-accessor>=0.2.2
BUILDLINK_PKGSRCDIR.hs-data-accessor?=	../../wip/hs-data-accessor

.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_DATA_ACCESSOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-data-accessor
