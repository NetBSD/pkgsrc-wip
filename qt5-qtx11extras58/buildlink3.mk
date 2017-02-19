# $NetBSD: buildlink3.mk,v 1.13 2016/12/04 05:17:17 ryoon Exp $

BUILDLINK_TREE+=	qt5-qtx11extras

.if !defined(QT5_QTX11EXTRAS_BUILDLINK3_MK)
QT5_QTX11EXTRAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtx11extras+=	qt5-qtx11extras>=5.8.0
BUILDLINK_ABI_DEPENDS.qt5-qtx11extras+=	qt5-qtx11extras>=5.8.0
BUILDLINK_PKGSRCDIR.qt5-qtx11extras?=	../../wip/qt5-qtx11extras58

BUILDLINK_INCDIRS.qt5-qtx11extras+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtx11extras+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtx11extras+=	qt5/plugins

.include "../../wip/qt5-qtxmlpatterns58/buildlink3.mk"
.endif	# QT5_QTX11EXTRAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtx11extras
