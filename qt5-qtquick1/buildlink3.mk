# $NetBSD: buildlink3.mk,v 1.25 2017/04/22 21:03:22 adam Exp $

BUILDLINK_TREE+=	qt5-qtquick1

.if !defined(QT5_QTQUICK1_BUILDLINK3_MK)
QT5_QTQUICK1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtquick1+=	qt5-qtquick1>=5.9.1
BUILDLINK_ABI_DEPENDS.qt5-qtquick1+=	qt5-qtquick1>=5.9.1
BUILDLINK_PKGSRCDIR.qt5-qtquick1?=	../../wip/qt5-qtquick1

BUILDLINK_INCDIRS.qt5-qtquick1+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtquick1+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtquick1+=	qt5/plugins

.include "../../wip/qt5-qtscript/buildlink3.mk"
.include "../../wip/qt5-qttools/buildlink3.mk"
.include "../../wip/qt5-qtwebkit/buildlink3.mk"
.include "../../wip/qt5-qtxmlpatterns/buildlink3.mk"
.endif	# QT5_QTQUICK1_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtquick1
