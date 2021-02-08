# $NetBSD$

BUILDLINK_TREE+=	qt6-psql

.if !defined(QT6_PSQL_BUILDLINK3_MK)
QT6_PSQL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-psql+=	qt6-psql>=6.0.1
BUILDLINK_PKGSRCDIR.qt6-psql?=		../../wip/qt6-psql

BUILDLINK_LIBDIRS.qt6-psql+=		qt6/plugins/sqldrivers

.endif	# QT6_PSQL_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-psql
