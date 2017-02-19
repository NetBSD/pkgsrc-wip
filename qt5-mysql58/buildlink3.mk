# $NetBSD: buildlink3.mk,v 1.12 2016/12/04 05:17:15 ryoon Exp $

BUILDLINK_TREE+=	qt5-mysql

.if !defined(QT5_MYSQL_BUILDLINK3_MK)
QT5_MYSQL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-mysql+=	qt5-mysql>=5.8.0
BUILDLINK_ABI_DEPENDS.qt5-mysql+=	qt5-mysql>=5.8.0
BUILDLINK_PKGSRCDIR.qt5-mysql?=	../../wip/qt5-mysql58

BUILDLINK_LIBDIRS.qt5-mysql+=		qt5/plugins

.include "../../wip/qt5-qtbase58/buildlink3.mk"
.endif	# QT5_MYSQL_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-mysql
