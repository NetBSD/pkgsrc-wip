# $NetBSD$

BUILDLINK_TREE+=	qt6-qtwebchannel

.if !defined(QT6_QTWEBCHANNEL_BUILDLINK3_MK)
QT6_QTWEBCHANNEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtwebchannel+=	qt6-qtwebchannel>=6.2.0
BUILDLINK_PKGSRCDIR.qt6-qtwebchannel?=		../../wip/qt6-qtwebchannel

.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtdeclarative/buildlink3.mk"
.endif	# QT6_QTWEBCHANNEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtwebchannel
