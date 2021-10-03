# $NetBSD$

BUILDLINK_TREE+=	qt6-websockets

.if !defined(QT6_WEBSOCKETS_BUILDLINK3_MK)
QT6_WEBSOCKETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-websockets+=	qt6-websockets>=6.2.0
BUILDLINK_PKGSRCDIR.qt6-websockets?=	../../wip/qt6-qtwebsockets

.include "../../wip/qt6-qtbase/buildlink3.mk"
.endif	# QT6_WEBSOCKETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-websockets
