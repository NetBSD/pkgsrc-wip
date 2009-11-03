# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/11/03 00:14:23 schnoebe Exp $

BUILDLINK_TREE+=	poco-data

.if !defined(POCO_DATA_BUILDLINK3_MK)
POCO_DATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poco-data+=	poco-data>=1.3.5
BUILDLINK_PKGSRCDIR.poco-data?=	../../wip/poco-data

.include "../../wip/poco/buildlink3.mk"
.endif # POCO_DATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-poco-data
