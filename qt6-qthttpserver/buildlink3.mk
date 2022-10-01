# $NetBSD$

BUILDLINK_TREE+=	qt6-qthttpserver

.if !defined(QT6_QTHTTPSERVER_BUILDLINK3_MK)
QT6_QTHTTPSERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qthttpserver+=	qt6-qthttpserver>=6.4.0
BUILDLINK_PKGSRCDIR.qt6-qthttpserver?=		../../wip/qt6-qthttpserver

.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtwebsockets/buildlink3.mk"
.endif	# QT6_QTHTTPSERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qthttpserver
