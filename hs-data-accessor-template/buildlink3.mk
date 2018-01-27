# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:11 szptvlfn Exp $

BUILDLINK_TREE+=	hs-data-accessor-template

.if !defined(HS_DATA_ACCESSOR_TEMPLATE_BUILDLINK3_MK)
HS_DATA_ACCESSOR_TEMPLATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-data-accessor-template+=	hs-data-accessor-template>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-data-accessor-template+=	hs-data-accessor-template>=0.2.1.10
BUILDLINK_PKGSRCDIR.hs-data-accessor-template?=		../../wip/hs-data-accessor-template

.include "../../wip/hs-data-accessor/buildlink3.mk"
.include "../../wip/hs-utility-ht/buildlink3.mk"
.endif	# HS_DATA_ACCESSOR_TEMPLATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-data-accessor-template
