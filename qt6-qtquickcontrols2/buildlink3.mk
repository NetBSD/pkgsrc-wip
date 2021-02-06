# $NetBSD$

BUILDLINK_TREE+=	qt6-qtquickcontrols2

.if !defined(QT6_QTQUICKCONTROLS2_BUILDLINK3_MK)
QT6_QTQUICKCONTROLS2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtquickcontrols2+=	qt6-qtquickcontrols2>=6.0.1
BUILDLINK_PKGSRCDIR.qt6-qtquickcontrols2?=	../../wip/qt6-qtquickcontrols2

.include "../../wip/qt6-qtdeclarative/buildlink3.mk"
.endif	# QT6_QTQUICKCONTROLS2_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtquickcontrols2
