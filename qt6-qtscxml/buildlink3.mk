# $NetBSD$

BUILDLINK_TREE+=	qt6-qtscxml

.if !defined(QT6_QTSCXML_BUILDLINK3_MK)
QT6_QTSCXML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtscxml+=	qt6-qtscxml>=6.1.3
BUILDLINK_PKGSRCDIR.qt6-qtscxml?=	../../wip/qt6-qtscxml

.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtdeclarative/buildlink3.mk"
.endif	# QT6_QTSCXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtscxml
