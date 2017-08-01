# $NetBSD: buildlink3.mk,v 1.10 2017/04/22 21:03:23 adam Exp $

BUILDLINK_TREE+=	qt5-qtwebsockets

.if !defined(QT5_WEBSOCKETS_BUILDLINK3_MK)
QT5_WEBSOCKETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtwebsockets+=	qt5-qtwebsockets>=5.9.1
BUILDLINK_ABI_DEPENDS.qt5-qtwebsockets+=	qt5-qtwebsockets>=5.9.1
BUILDLINK_PKGSRCDIR.qt5-qtwebsockets?=		../../wip/qt5-qtwebsockets

.include "../../wip/qt5-qtdeclarative/buildlink3.mk"
.endif	# QT5_WEBSOCKETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtwebsockets
