# $NetBSD: buildlink3.mk,v 1.1 2015/01/15 14:45:51 makoto Exp $

BUILDLINK_TREE+=	dbh

.if !defined(DBH_BUILDLINK3_MK)
DBH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dbh+=		dbh>=1.0.22
BUILDLINK_PKGSRCDIR.dbh?=	../../databases/dbh
.endif # DBH_BUILDLINK3_MK

BUILDLINK_TREE+=	-dbh
