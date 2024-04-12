# $NetBSD: buildlink3.mk,v 1.26 2023/11/08 13:20:40 wiz Exp $

BUILDLINK_TREE+=	cups-filters

.if !defined(CUPS_FILTERS_BUILDLINK3_MK)
CUPS_FILTERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cups-filters+=	cups-filters>=2.0.0
BUILDLINK_ABI_DEPENDS.cups-filters+=	cups-filters>=2.0.0
BUILDLINK_PKGSRCDIR.cups-filters?=	../../wip/cups-filters

.include "../../print/cups-base/buildlink3.mk"
.endif # CUPS_FILTERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-cups-filters
