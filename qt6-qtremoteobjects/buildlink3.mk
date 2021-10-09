# $NetBSD$

BUILDLINK_TREE+=	qt6-qtremoteobjects

.if !defined(QT6_QTREMOTEOBJECTS_BUILDLINK3_MK)
QT6_QTREMOTEOBJECTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtremoteobjects+=	qt6-qtremoteobjects>=6.2.0
BUILDLINK_PKGSRCDIR.qt6-qtremoteobjects?=	../../wip/qt6-qtremoteobjects

.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtdeclarative/buildlink3.mk"
.endif	# QT6_QTREMOTEOBJECTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtremoteobjects
