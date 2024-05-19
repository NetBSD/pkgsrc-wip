# $NetBSD$

BUILDLINK_TREE+=	sqlitewrite

.if !defined(SQLITEWRITE_BUILDLINK3_MK)
SQLITEWRITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sqlitewrite+=	sqlitewrite>=0.0.0.20240122
BUILDLINK_PKGSRCDIR.sqlitewrite?=	../../wip/sqlitewrite

.include "../../databases/sqlite3/buildlink3.mk"
.endif	# SQLITEWRITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-sqlitewrite
