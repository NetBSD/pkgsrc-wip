# $NetBSD: buildlink3.mk,v 1.4 2010/01/17 12:03:30 thomasklausner Exp $

BUILDLINK_TREE+=	poco-data-sqlite

.if !defined(POCO_DATA_SQLITE_BUILDLINK3_MK)
POCO_DATA_SQLITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poco-data-sqlite+=	poco-data-sqlite>=1.3.5
BUILDLINK_ABI_DEPENDS.poco-data-sqlite?=	poco-data-sqlite>=1.3.5nb1
BUILDLINK_PKGSRCDIR.poco-data-sqlite?=	../../wip/poco-data-sqlite

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../wip/poco-data/buildlink3.mk"
.endif # POCO_DATA_SQLITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-poco-data-sqlite
