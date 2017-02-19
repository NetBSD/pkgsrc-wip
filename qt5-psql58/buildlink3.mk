# $NetBSD: buildlink3.mk,v 1.12 2016/12/04 05:17:15 ryoon Exp $

BUILDLINK_TREE+=	qt5-psql

.if !defined(QT5_PSQL_BUILDLINK3_MK)
QT5_PSQL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-psql+=	qt5-psql>=5.8.0
BUILDLINK_ABI_DEPENDS.qt5-psql+=	qt5-psql>=5.8.0
BUILDLINK_PKGSRCDIR.qt5-psql?=	../../wip/qt5-psql58

BUILDLINK_LIBDIRS.qt5-psql+=		qt5/plugins

.include "../../wip/qt5-qtbase58/buildlink3.mk"
.endif	# QT5_PSQL_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-psql
