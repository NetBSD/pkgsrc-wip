# $NetBSD: buildlink3.mk,v 1.2 2009/11/05 05:09:44 schnoebe Exp $

BUILDLINK_TREE+=	poco-data-sqlite

.if !defined(POCO_DATA_SQLITE_BUILDLINK3_MK)
POCO_DATA_SQLITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poco-data-sqlite+=	poco-data-sqlite>=1.3.5
BUILDLINK_PKGSRCDIR.poco-data-sqlite?=	../../wip/poco-data-sqlite

.include "../../wip/poco-data/buildlink3.mk"
.endif # POCO_DATA_SQLITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-poco-data-sqlite
