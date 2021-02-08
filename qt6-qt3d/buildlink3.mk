# $NetBSD$

BUILDLINK_TREE+=	qt6-qt3d

.if !defined(QT6_QT3D_BUILDLINK3_MK)
QT6_QT3D_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qt3d+=	qt6-qt3d>=6.0.1
BUILDLINK_PKGSRCDIR.qt6-qt3d?=		../../wip/qt6-qt3d

.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtdeclarative/buildlink3.mk"
.endif	# QT6_QT3D_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qt3d
