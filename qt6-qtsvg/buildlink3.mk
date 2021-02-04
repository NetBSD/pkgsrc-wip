# $NetBSD$

BUILDLINK_TREE+=	qt6-qtsvg

.if !defined(QT6_QTSVG_BUILDLINK3_MK)
QT6_QTSVG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtsvg+=	qt6-qtsvg>=6.0.0
BUILDLINK_PKGSRCDIR.qt6-qtsvg?=		../../wip/qt6-qtsvg

BUILDLINK_INCDIRS.qt6-qtsvg+=	qt6/include
BUILDLINK_LIBDIRS.qt6-qtsvg+=	qt6/lib
BUILDLINK_LIBDIRS.qt6-qtsvg+=	qt6/plugins

.include "../../wip/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTSVG_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtsvg
