# $NetBSD$

BUILDLINK_TREE+=	qt6-qtspeech

.if !defined(QT6_QTSPEECH_BUILDLINK3_MK)
QT6_QTSPEECH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtspeech+=	qt6-qtspeech>=6.4.0
BUILDLINK_PKGSRCDIR.qt6-qtspeech?=	../../wip/qt6-qtspeech

.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtdeclarative/buildlink3.mk"
.endif	# QT6_QTSPEECH_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtspeech
