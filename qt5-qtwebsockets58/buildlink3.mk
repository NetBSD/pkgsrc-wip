# $NetBSD: buildlink3.mk,v 1.7 2016/12/04 05:17:17 ryoon Exp $

BUILDLINK_TREE+=	qt5-websockets

.if !defined(QT5_WEBSOCKETS_BUILDLINK3_MK)
QT5_WEBSOCKETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-websockets+=	qt5-websockets>=5.8.0
BUILDLINK_ABI_DEPENDS.qt5-websockets+=	qt5-websockets>=5.8.0
BUILDLINK_PKGSRCDIR.qt5-websockets?=	../../wip/qt5-qtwebsockets58

.include "../../wip/qt5-qtdeclarative58/buildlink3.mk"
.endif	# QT5_WEBSOCKETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-websockets
