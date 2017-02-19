# $NetBSD: buildlink3.mk,v 1.12 2016/12/04 05:17:16 ryoon Exp $

BUILDLINK_TREE+=	qt5-qtserialport

.if !defined(QT5_QTSERIALPORT_BUILDLINK3_MK)
QT5_QTSERIALPORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtserialport+=	qt5-qtserialport>=5.8.0
BUILDLINK_ABI_DEPENDS.qt5-qtserialport+=	qt5-qtserialport>=5.8.0
BUILDLINK_PKGSRCDIR.qt5-qtserialport?=	../../wip/qt5-qtserialport58

BUILDLINK_INCDIRS.qt5-qtserialport+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtserialport+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtserialport+=	qt5/plugins

.include "../../wip/qt5-qtbase58/buildlink3.mk"
.endif	# QT5_QTSERIALPORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtserialport
