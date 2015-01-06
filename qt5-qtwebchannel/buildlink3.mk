# $NetBSD: buildlink3.mk,v 1.1 2015/01/06 11:32:24 nros Exp $
#

BUILDLINK_TREE+=	qt5-qtwebchannel

.if !defined(QT5_QTWEBCHANNEL_BUILDLINK3_MK)
QT5_QTWEBCHANNEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtwebchannel+=qt5-qtwebchannel>=5.4.0
BUILDLINK_PKGSRCDIR.qt5-qtwebchannel?=	../../wip/qt5-qtwebchannel

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# QT5_QTWEBCHANNEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtwebchannel
