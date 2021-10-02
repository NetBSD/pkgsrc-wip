# $NetBSD$

BUILDLINK_TREE+=	qt6-qtdatavis3d

.if !defined(QT6_QTDATAVIS3D_BUILDLINK3_MK)
QT6_QTDATAVIS3D_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtdatavis3d+=	qt6-qtdatavis3d>=6.2.0
BUILDLINK_PKGSRCDIR.qt6-qtdatavis3d?=	../../wip/qt6-qtdatavis3d

.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtdeclarative/buildlink3.mk"
.endif	# QT6_QTDATAVIS3D_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtdatavis3d
