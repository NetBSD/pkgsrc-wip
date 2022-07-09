# $NetBSD$

BUILDLINK_TREE+=	qt6-qtcharts

.if !defined(QT6_QTCHARTS_BUILDLINK3_MK)
QT6_QTCHARTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtcharts+=	qt6-qtcharts>=6.3.1
BUILDLINK_PKGSRCDIR.qt6-qtcharts?=	../../wip/qt6-qtcharts

.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtdeclarative/buildlink3.mk"
.endif	# QT6_QTCHARTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtcharts
