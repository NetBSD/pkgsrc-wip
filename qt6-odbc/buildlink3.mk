# $NetBSD$

BUILDLINK_TREE+=	qt6-odbc

.if !defined(QT6_ODBC_BUILDLINK3_MK)
QT6_ODBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-odbc+=	qt6-odbc>=6.0.1
BUILDLINK_PKGSRCDIR.qt6-odbc?=		../../wip/qt6-odbc

BUILDLINK_LIBDIRS.qt6-odbc+=		qt6/plugins/sqldrivers

.endif	# QT6_ODBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-odbc
