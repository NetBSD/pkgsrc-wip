# $NetBSD: buildlink3.mk,v 1.7 2016/12/04 05:17:16 ryoon Exp $

BUILDLINK_TREE+=	qt5-qtwebchannel

.if !defined(QT5_QTWEBCHANNEL_BUILDLINK3_MK)
QT5_QTWEBCHANNEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtwebchannel+=	qt5-qtwebchannel>=5.8.0
BUILDLINK_ABI_DEPENDS.qt5-qtwebchannel+=	qt5-qtwebchannel>=5.8.0
BUILDLINK_PKGSRCDIR.qt5-qtwebchannel?=	../../wip/qt5-qtwebchannel58

BUILDLINK_INCDIRS.qt5-qtwebchannel+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtwebchannel+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtwebchannel+=	qt5/plugins

.include "../../wip/qt5-qtdeclarative58/buildlink3.mk"
.endif	# QT5_QTWEBCHANNEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtwebchannel
