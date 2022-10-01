# $NetBSD$

BUILDLINK_TREE+=	qt6-qtwebsockets

.if !defined(QT6_QTWEBSOCKETS_BUILDLINK3_MK)
QT6_QTWEBSOCKETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtwebsockets+=	qt6-qtwebsockets>=6.4.0
BUILDLINK_PKGSRCDIR.qt6-qtwebsockets?=		../../wip/qt6-qtwebsockets

.include "../../wip/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTWEBSOCKETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtwebsockets
