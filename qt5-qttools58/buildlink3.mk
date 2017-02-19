# $NetBSD: buildlink3.mk,v 1.21 2017/01/21 20:06:46 ryoon Exp $

BUILDLINK_TREE+=	qt5-qttools

.if !defined(QT5_QTTOOLS_BUILDLINK3_MK)
QT5_QTTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qttools+=	qt5-qttools>=5.8.0
BUILDLINK_ABI_DEPENDS.qt5-qttools+=	qt5-qttools>=5.8.0
BUILDLINK_PKGSRCDIR.qt5-qttools?=	../../wip/qt5-qttools58

BUILDLINK_INCDIRS.qt5-qttools+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qttools+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qttools+=	qt5/plugins

.include "../../wip/qt5-qtxmlpatterns58/buildlink3.mk"
.include "../../wip/qt5-qtwebkit58/buildlink3.mk"
.include "../../wip/qt5-sqlite358/buildlink3.mk"
.endif	# QT5_QTTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qttools
