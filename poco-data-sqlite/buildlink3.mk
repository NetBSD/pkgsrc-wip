# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/11/03 00:16:26 schnoebe Exp $

BUILDLINK_TREE+=	poco-data-sqlite

.if !defined(POCO_DATA_SQLITE_BUILDLINK3_MK)
POCO_DATA_SQLITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poco-data-sqlite+=	poco-data>=1.3.5
BUILDLINK_PKGSRCDIR.poco-data-sqlite?=	../../wip/poco-data

.include "../../wip/poco-data/buildlink3.mk"
.endif # POCO_DATA_SQLITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-poco-data-sqlite
