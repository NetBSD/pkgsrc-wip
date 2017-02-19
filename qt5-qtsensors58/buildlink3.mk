# $NetBSD: buildlink3.mk,v 1.13 2016/12/04 05:17:16 ryoon Exp $

BUILDLINK_TREE+=	qt5-qtsensors

.if !defined(QT5_QTSENSORS_BUILDLINK3_MK)
QT5_QTSENSORS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtsensors+=	qt5-qtsensors>=5.8.0
BUILDLINK_ABI_DEPENDS.qt5-qtsensors+=	qt5-qtsensors>=5.8.0
BUILDLINK_PKGSRCDIR.qt5-qtsensors?=	../../wip/qt5-qtsensors58

BUILDLINK_INCDIRS.qt5-qtsensors+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtsensors+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtsensors+=	qt5/plugins

.include "../../wip/qt5-qtdeclarative58/buildlink3.mk"
.endif	# QT5_QTSENSORS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtsensors
