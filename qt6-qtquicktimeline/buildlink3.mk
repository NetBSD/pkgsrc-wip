# $NetBSD$

BUILDLINK_TREE+=	qt6-qtquicktimeline

.if !defined(QT6_QTQUICKTIMELINE_BUILDLINK3_MK)
QT6_QTQUICKTIMELINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtquicktimeline+=	qt6-qtquicktimeline>=6.2.0
BUILDLINK_PKGSRCDIR.qt6-qtquicktimeline?=	../../wip/qt6-qtquicktimeline

.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtdeclarative/buildlink3.mk"
.endif	# QT6_QTQUICKTIMELINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtquicktimeline
